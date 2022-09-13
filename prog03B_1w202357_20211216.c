#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define PI 3.1415926535897932384626433832795

/* 終端記号，非終端記号の識別子 （列挙型として定義）*/
enum { Prog, Com_list, Rep_com, Prim_com, WALK, MOVE, GOUP, MOVEUP };

/* 2分木ノードの定義 */
struct tnode {
	int type;//非終端記号の種類（Prog, Com_list, Rep_com, Prim_com）
	int op; //コマンドの種類（WALK, MOVE, GOUP, MOVEUP）
	int inum;//整数値（繰り返し回数）
	double fnum1;//実数値（primitive commandの第1引数）
	double fnum2;//実数値（primitive commandの第2引数）
	struct tnode *left;//左側のノードを指すポインタ
	struct tnode *right;//右側のノードを指すポインタ
};

/* 大域変数 */
char *s, *tp;
char delim[] = " \t\r\n";
//ロボットの座標
double pos_r = 0;//r座標
double pos_th = 0;//θ座標
double pos_z = 0;//z座標
int moved = 0;//move,move_upによる移動が起きたことを記録

/* 関数プロトタイプ宣言 */
struct tnode *talloc(int);
void nextToken(void);
int match(char *);
int isnumber(char *);
int isfloat(char *);
void err(char *msg);
void parse(struct tnode *);
void disp_tree(struct tnode *);
void exe(struct tnode *);
void print_pos();

/* メイン関数 */
int main(int argc, char ** argv) {
	FILE *fp;
	char fileName[256] = "./input.txt";
	fpos_t size;
	struct tnode *root;
	char c;
	int i;

	//ファイルを開く
	fp = fopen(fileName, "rb");
	if(fp == NULL) {
		printf("File Open Error!(%s)\n", fileName);
		return -1;
	}

	//ファイルの終端位置にポインタを移動する
	fseek(fp, 0, SEEK_END);

	//ファイルサイズを取得する(fgetposの場合)
	fgetpos(fp, &size);

	//ファイルサイズ＋1バイトの文字配列を確保
	//（＋1は最後のヌル文字の分．これがないとstrtokが文字列の最後を検出できない）
	//演習環境（32bit linux）のときは下のようにする
	s = (char *)malloc((size_t)(size.__pos + 1)*sizeof(char));
	//Windowsや64bit linuxの場合は下のようにする
	//s = (char *)malloc((size_t)(size + 1)*sizeof(char));
	if (s == NULL) { /*確保失敗*/
		printf("malloc failed\n");
		return(-1);
	}

	//ファイルポインタをファイル先頭に移動しファイル内容を読み込む
	fseek(fp, 0, SEEK_SET);
	for (i = 0; (c = (char)getc(fp)) != EOF; i++) {
		s[i] = c;
	}
	s[i] = '\0'; //最後にヌル文字を入れる

	//最初のトークンを認識
	tp = strtok(s, delim);

	//解析木の作成
	root = talloc(Prog);
	parse(root);

	//移動軌跡の出力
	print_pos();//初期座標を出力
	exe(root);

	free(s);
	fclose(fp);
	return 0;
}

/* パーサ */
/* 文法
（1）Prog → Com_list [EOF]
（2）Com_list → [Rep_com Prim_com] Com_list?
（3）Rep_com → { inum  Com_list? }
（4）Prim_com → walk fnum  fnum
		| move fnum  fnum
		| go_up fnum
		| move_up fnum
（inum = [0-9]+, fnum = [+-]?[0-9]+(.[0-9]+)?）
*/
void parse(struct tnode *p) {
	if (p->type == Prog) {
		/* Progの場合 */
		p->left = talloc(Com_list);//左にCom_listを作って
		parse(p->left);//丸投げ
		if (tp != NULL) {//最後に余分な文字があったらエラー
			err("parse Prog: extra token at the end of input: ");
		}
	} else if (p->type == Com_list) {
		/*
		  Com_listの場合：
		  トークンが"{"だったらRep_comノード作成＆parse呼び出し．
		  "walk","move","go_up","move_up"のいずれかだったらPrim_comノード作成＆parse呼び出し．
		  Prim_comの場合，ここでnextToken()を行わないように注意．
		  （parseを呼び出した先で，どのコマンドかわからなくなる）
		*/
		if (match("{")) {//Rep_comかどうか調べる
			nextToken();
			p->left = talloc(Rep_com);//左にRep_comノードを作って
			parse(p->left);//丸投げ
		} else if (match("walk") || match("move") || match("go_up") || match("move_up")) {//Prim_comかどうか調べる
			p->left = talloc(Prim_com);//左にPrim_comノードを作って
			parse(p->left);//丸投げ
		} else {//Rep_com, Prim_comのどちらでもなければエラー
			err("parse Com_list: unknown command: ");
		}
		if (match("{") || match("walk") || match("move") || match("go_up") || match("move_up")) {//さらにCom_listがあるか調べる
			p->right = talloc(Com_list); //右にCom_listノードを作って
			parse(p->right); //丸投げ
		}
	} else if (p->type == Rep_com) {
		/* Rep_comの場合 */
		if (isnumber(tp)) {//繰り返し回数があるか調べる
			p->inum = atoi(tp);//繰り返し回数をinumに得る
			nextToken();
			if (match("{") || match("walk") || match("move") || match("go_up") || match("move_up")) {//さらにCom_listがあるか調べる
				p->left = talloc(Com_list); //左にCom_listノードを作って
				parse(p->left); //丸投げ
			}
			nextToken();
		} else {//整数でなければエラー
			err("parse Rep_com: illegal number in Rep_com command: ");
		}
	} else if (p->type == Prim_com) {
		/* Prim_comの場合 */
		if(match("walk")){
			/*walkの場合*/
			p->op = WALK;//opに入れる
			nextToken();
			if (isfloat(tp)) {//第1引数チェック
				p->fnum1 = atof(tp);//第1引数をfum1に入れる
				nextToken();
			} else {
				err("parse Prim_com: illegal number in walk command: ");
			}
			if (isfloat(tp)) {//第2引数チェック
				p->fnum2 = atof(tp);//第2引数をfum2に入れる
				nextToken();
			} else {
				err("parse Prim_com: illegal number in walk command: ");
			}
		} else if(match("move")){
			/*moveの場合*/
			p->op = MOVE;//opに入れる
			nextToken();
			if (isfloat(tp)) {//第1引数チェック
				p->fnum1 = atof(tp);//第1引数をfum1に入れる
				nextToken();
			} else {
				err("parse Prim_com: illegal number in move command: ");
			}
			if (isfloat(tp)) {//第2引数チェック
				p->fnum2 = atof(tp);//第2引数をfum2に入れる
				nextToken();
			} else {
				err("parse Prim_com: illegal number in move command: ");
			}
		} else if(match("go_up")){
			/*go_upの場合*/
			p->op = GOUP;//opに入れる
			nextToken();
			if (isfloat(tp)) {//第1引数チェック
				p->fnum1 = atof(tp);//第1引数をfum1に入れる
				nextToken();
			} else {
				err("parse Prim_com: illegal number in go_up command: ");
			}
		} else if(match("move_up")){
			/*move_upの場合*/
			p->op = MOVEUP;
			nextToken();
			if (isfloat(tp)) {//第1引数チェック
				p->fnum1 = atof(tp);//第1引数をfum1に入れる
				nextToken();
			} else {
				err("parse Prim_com: illegal number in move_up command: ");
			}
		}
	}
}

/* exe関数（エグゼキュータ） */
int flag_move = 0, flag_up = 0;//exe関数の中でこれらのフラグを使うために宣言
void exe(struct tnode *p) {
	/* 作成せよ
	  repeatコマンドなどでmoveやmove_upが連続して実行されても，
	  「改行2回」の出力は連続しないように注意せよ．
	*/
	if (p->type == Prog) {
		/* Progの場合 */
		exe(p->left);//左ノードをexe
	} else if (p->type == Com_list) {
		/* Com_listの場合 */
		exe(p->left);//左ノードをexe
		if (p->right != NULL) {//右にノードがあった場合
			exe(p->right);//右ノードをexe
		}
	} else if (p->type == Rep_com) {
		/* Rep_comの場合 */
		for(int i = 0; i < p->inum; i++){
			if (p->left != NULL) {//左にノードがあった場合
				exe(p->left);//左ノードをexe
			}
		}
	} else if (p->type == Prim_com) {
		if (p->op == WALK) {
			/* "walk"の場合 */
			if(flag_move || flag_up){
				/*ひとつ前にmoveかmove_upがある場合*/
				printf("\n\n");//二回改行
				flag_move = 0;//フラグを元に戻す
				flag_up = 0;//フラグを元に戻す
			}
				print_pos();//現地点を表示
				pos_r += p->fnum1;//r方向に足す
				pos_th += p->fnum2;//θ方向に足す
				print_pos();//移動後を表示
		} else if (p->op == GOUP) {
			/* "go_up" の場合 */
			if(flag_move || flag_up){
				/*ひとつ前にmoveかmove_upがある場合*/
				printf("\n\n");//二回改行
				flag_move = 0;//フラグを元に戻す
				flag_up = 0;//フラグを元に戻す
			}
				print_pos();//現地点を表示
				pos_z += p->fnum1;//z方向に足す
				print_pos();//現地点を表示
		} else if (p->op == MOVE) {
			/* "move" の場合 */
			flag_move = 1;//moveがあった情報を保存
			pos_r += p->fnum1;//r方向に足す
			pos_th += p->fnum2;//θ方向に足す
		}  else if (p->op == MOVEUP) {
			/* "move_up" の場合 */
			flag_up = 1;//move_upがあった情報を保存
			pos_z += p->fnum1;//z方向に足す
		}
	}
}
//引数の指す文字列が[0-9]+のパターンであるかを判定
int isnumber(char *s) {
	if (s == NULL)//引数が無効（偽を返す）
		return 0;
	if (!isdigit(*s))//最初の数字のチェック（数字でなければ偽を返す）
		return 0;
	s++;//最初の数字を確認したので次の文字に進む（次のwhileに含めても可）
	while(isdigit(*s))//後に続く数字のチェック
		s++;
	if (*s != '\0')//数字かヌル文字以外の文字があったら偽を返す
		return 0;
	return 1;//何事もなく文字列の終わりに到達（真を返す）
}
//引数の指す文字列が[+-]?[0-9]+(.[0-9]+)?のパターンであるかを判定
int isfloat(char *s) {
	if (s == NULL)//引数が無効（偽を返す）
		return 0;
	if (*s == '+' || *s == '-')//正または負号があった
		s++;
	if (!isdigit(*s))//最初の数字のチェック（数字でなければ偽を返す）
		return 0;
	s++;//最初の数字を確認したので次の文字に進む（次のwhileに含めても可）
	while(isdigit(*s))//後に続く数字のチェック
		s++;
	if (*s == '.') {//小数点があった
		s++;
		if(!isdigit(*s))//小数部の最初の数字をチェック（数字でなければ偽を返す）
			return 0;
		s++;
		while(isdigit(*s))//後に続く数字のチェック
			s++;
	}
	if (*s != '\0')//数字かヌル文字以外の文字があったら偽を返す
		return 0;
	return 1;//何事もなく文字列の終わりに到達（真を返す）
}
/*2分木のノード1つ分のメモリ領域を確保し，その先頭へのポインタを返す関数*/
struct tnode *talloc(int t) {
	struct tnode *p = (struct tnode *) malloc(sizeof(struct tnode));
	p->type = t;
	p->op = -1;
	p->inum = 0;
	p->fnum1 = 0;
	p->fnum2 = 0;
	p->left = NULL;
	p->right = NULL;
	return p;
}
/*次のトークンに進む（すなわちtpが次のトークンを指すようにする）関数*/
void nextToken(void) {
	if (tp != NULL) {
		tp = strtok(NULL, delim);
	}
}
/*現在のトークン（tpの指すトークン）が，引数文字列と同じかどうかを判定する関数*/
int match(char *s) {
	if (s == NULL || tp == NULL) {//引数またはtpがNULLだったら0（偽）を返す
		return 0;
	}
	if (strcmp(tp, s) == 0) {
		return 1; //引数文字列と同じなら1（真）を返す
	} else {
		return 0; //そうでなければ0（偽）を返す
	}
}
/*エラーメッセージと現在のトークンを表示し，プログラムを途中終了する関数*/
void err(char *msg) {
	if (tp != NULL)
		printf("%s Token: %s\n", msg, tp);
	else
		printf("%s Token: NULL\n", msg);
	exit(EXIT_FAILURE);//プログラムを途中終了するライブラリ関数．
}
/*ロボットの座標を出力する関数*/
void print_pos() {
	double x = pos_r*cos(pos_th*PI/180);
	double y = pos_r*sin(pos_th*PI/180);
	double z = pos_z;
	printf("%f\t%f\t%f\n", x, y, z);
}

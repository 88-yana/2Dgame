CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJS_DIR = ./mandatory/objs
OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

SRCS_DIR = ./mandatory/src
SRCS = $(addprefix src/, ${SRCS_NAME})

SRCS_NAME = main.c \
	check_arg.c \
	display_map.c \
	draw_back_white.c \
	free.c \
	hook_utils.c \
	hook.c \
	init.c \
	read_file.c \
	make_map.c \
	check_map_utils.c \
	check_map.c \
	check_path.c


OBJS_DIR_BONUS = ./bonus/objs
OBJS_BONUS = $(addprefix $(OBJS_DIR_BONUS)/, $(notdir $(SRCS_BONUS:.c=.o)))

SRCS_DIR_BONUS = ./bonus/src
SRCS_BONUS = $(addprefix src/, ${SRCS_NAME_BONUS})

SRCS_NAME_BONUS = main_bonus.c \
	check_arg_bonus.c \
	display_map_bonus.c \
	draw_back_white_bonus.c \
	free_bonus.c \
	hook_utils_bonus.c \
	hook_bonus.c \
	init_bonus.c \
	read_file_bonus.c \
	make_map_bonus.c \
	check_map_utils_bonus.c \
	check_map_bonus.c \
	check_path_bonus.c


NAME = so_long
NAME_BONUS = so_long_bonus

LIBFTDIR = libft
LIBFT_A = $(LIBFTDIR)/libft.a

GNLDIR = gnl
GNL_A = $(GNLDIR)/gnl.a

MINILIBXDIR = minilibx
MINILIBX = libmlx.dylib

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS) $(LIBFT_A) $(GNL_A) $(MINILIBX)
	cc $(OBJS) $(LIBFT_A) $(GNL_A) $(MINILIBX) -o $(NAME)
$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT_A) $(GNL_A) $(MINILIBX)
	cc $(OBJS_BONUS) $(LIBFT_A) $(GNL_A) $(MINILIBX) -o $(NAME_BONUS)
$(LIBFT_A):
	$(MAKE) -C $(LIBFTDIR)
$(GNL_A):
	$(MAKE) -C $(GNLDIR)
$(MINILIBX):
	$(MAKE) -C $(MINILIBXDIR)
${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	mkdir -p ${OBJS_DIR}
	$(CC) $(CFLAGS) -c $< -o $@
${OBJS_DIR_BONUS}/%.o: ${SRCS_DIR_BONUS}/%.c
	mkdir -p ${OBJS_DIR_BONUS}
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) -rf $(OBJS_DIR)
	$(RM) -rf $(OBJS_DIR_BONUS)
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)
	$(MAKE) clean -C $(LIBFTDIR)
	$(MAKE) clean -C $(GNLDIR)
	$(MAKE) clean -C $(MINILIBXDIR)
fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR)
	$(MAKE) fclean -C $(GNLDIR)
	$(RM) $(NAME) $(NAME_BONUS) $(MINILIBX) ../$(MINILIBX)
re: fclean all

.PHONY : all clean fclean re

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJS_DIR = ./mandatory/objs

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

SRCS_DIR = ./mandatory/src

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
	check_map.c

SRCS = $(addprefix src/, ${SRCS_NAME})

SRCS_BONUS = bonus/main.c \

OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)
NAME = so_long
NAME_BONUS = so_long_bonus

LIBFTDIR = libft
LIBFT_A = $(LIBFTDIR)/libft.a

GNLDIR = gnl
GNL_A = $(GNLDIR)/gnl.a

MINILIBXDIR = minilibx
MINILIBX = libmlx.dylib

all: $(NAME)

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	mkdir -p ${OBJS_DIR}
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME): $(OBJS) $(LIBFT_A) $(GNL_A) $(MINILIBX)
	cc $(OBJS) $(LIBFT_A) $(GNL_A) $(MINILIBX) -o $(NAME)
$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT_A) $(GNL_A) $(MINILIBX)
	cc $(OBJS_BONUS) $(LIBFT_A) $(GNL_A) $(MINILIBX) -o $(NAME)
$(LIBFT_A):
	$(MAKE) -C $(LIBFTDIR)
$(GNL_A):
	$(MAKE) -C $(GNLDIR)
$(MINILIBX):
	$(MAKE) -C $(MINILIBXDIR)
clean:
	$(RM) -rf ${OBJS_DIR}
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

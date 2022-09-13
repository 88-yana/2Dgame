CC = cc
# CFLAGS = -Wall -Wextra -Werror -I ./include
SRCS = mandatory/main.c \
	gnl/get_next_line.c \
	gnl/get_next_line_utils.c

OBJS = $(SRCS:%.c=%.o)
NAME = so_long

LIBFTDIR = libft
LIBFT_A = $(LIBFTDIR)/libft.a

MINILIBXDIR = minilibx
MINILIBX = libmlx.dylib

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A) $(MINILIBX)
	cc $(OBJS) $(LIBFT_A) $(MINILIBX) -o $(NAME)
$(LIBFT_A):
	$(MAKE) -C $(LIBFTDIR)
$(MINILIBX):
	$(MAKE) -C $(MINILIBXDIR)
clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFTDIR)
	$(MAKE) clean -C $(MINILIBXDIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR)
	$(RM) $(NAME) $(MINILIBX) ../$(MINILIBX)

re: fclean all

.PHONY : all clean fclean re


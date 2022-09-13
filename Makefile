CC = cc
# CFLAGS = -Wall -Wextra -Werror -I ./include
SRCS = mandatory/main.c \

SRCS_BONUS = bonus/main.c \

OBJS = $(SRCS:%.c=%.o)
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


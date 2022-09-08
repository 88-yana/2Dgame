CC = cc
# CFLAGS = -Wall -Wextra -Werror -I ./include
SRCS = main.c gnl/get_next_line.c gnl/get_next_line_utils.c
OBJS = $(SRCS:%.c=%.o)
NAME = so_long

LIBFTDIR = libft
LIBFT_A = $(LIBFTDIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	cc $(OBJS) $(LIBFT_A) -o $(NAME)
$(LIBFT_A):
	$(MAKE) -C $(LIBFTDIR)
clean:
	$(RM) $(OBJS)
clean_l:
	$(MAKE) clean -C $(LIBFTDIR)
fclean: clean
	$(RM) $(NAME)
fclean_l:
	$(MAKE) fclean -C $(LIBFTDIR)
re: fclean all
re_l:
	$(MAKE) fclean $(MAKE) all -C $(LIBFTDIR)

.PHONY : all clean fclean re clean_l fclean_l re_l

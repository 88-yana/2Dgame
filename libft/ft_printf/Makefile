CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
	ft_put.c \
	ft_putnb_hex.c \
	ft_putnb.c \
	ft_putuni.c
OBJS = $(SRCS:%.c=%.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar r $(NAME) $(OBJS)
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY : all clean fclean re
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = get_next_line.c \
	get_next_line_utils.c
OBJS = $(SRCS:%.c=%.o)
NAME = gnl.a

all: $(NAME)

$(NAME): $(OBJS)
	ar r $(NAME) $(OBJS)
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY : all clean fclean re
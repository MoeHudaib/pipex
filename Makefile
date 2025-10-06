CC     = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME   = pipex

SRCS = ./parse/parse.c \
	./ppx/ppx.c \
	./parse/parse_utils.c \
	main.c

LIBS = ./libs/libft/libft.a



all: $(NAME)

$(NAME): $(SRCS) $(LIBS)
	$(CC) $(CFLAGS) $(SRCS) $(LIBS) -o $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re do


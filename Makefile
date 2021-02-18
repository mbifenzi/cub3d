SRC =	*.c


OBJECT = $(SRC:.c=.o)

NAME = cub3D.a

all : $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(SRC) -O3
	@ar rc $(NAME) $(OBJECT)
	@ranlib $(NAME)
	@gcc cub3d.c $(NAME) -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o cub3D -fsanitize=address


clean:
	@rm -f $(OBJECT)

fclean: clean
	@rm -f $(NAME)

re: fclean all
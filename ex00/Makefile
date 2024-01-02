NAME = ex00
SOURCES = $(wildcard ./src/*.cpp)
CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
CC = @c++

all:	$(NAME)
$(NAME):	$(SOURCES)
			$(CC) $(CFLAGS) $(^) -o $(@) -fsanitize=address,undefined

clean:
			@rm -f $(wildcard ./src/*.o)

fclean:	clean
			@rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re
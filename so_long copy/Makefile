NAME = so_long
CFLAGS =  -fsanitize=address -g3
LIBFT = libft.a
SRC = so_long.c so_long_utils.c check_map.c check_map2.c events_utils.c events.c graphic_render.c floodfill.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
RM = rm -rf

all : $(LIBFT) $(NAME)

$(LIBFT) :
	make -C libft

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME) : $(SRC:.c=.o)
	$(CC) $(CFLAGS) $^ libft/libft.a -lmlx -framework OpenGL -framework AppKit  -o $(NAME)


clean :
	$(RM) $(SRC:.c=.o)

fclean : clean
	$(RM) $(NAME)

re : fclean all


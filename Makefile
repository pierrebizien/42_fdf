LIBRARY = -I ./minilibx_linux -L ./minilibx_linux/ -I ./libft -L ./libft -lft

NAME = FdF

SRCS = main.c ft_draw_fct.c ft_gen_map.c ft_free.c ft_start.c get_next_line.c get_next_line_utils.c ft_key1.c ft_key2.c ft_key3.c ft_gen_positions.c ft_draw_map.c ft_view.c ft_map_init.c

all:
	$(MAKE) -C ./minilibx_linux
	$(MAKE) -C ./libft
	gcc -Wall -Werror -Wextra ${SRCS} -o ${NAME} -I. ${LIBRARY} -lmlx -lm -lXext -lX11 -g

clean:
	rm -f *.d *.o
	$(MAKE) clean -C libft
	$(MAKE) clean -C minilibx_linux

fclean: clean
	rm FdF
	$(MAKE) fclean -C libft
	$(MAKE) fclean -C minilibx_linux


re: fclean
	all


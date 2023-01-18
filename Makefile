LIBRARY = -I ./minilibx_linux -L ./minilibx_linux/ -I ./libft -L ./libft -lft

NAME = FdF

SRCS = main.c draw_fct.c ft_gen_map.c get_next_line.c get_next_line_utils.c ft_gen_positions.c draw_map.c ft_view.c ft_map_init.c

all:
	$(MAKE) -C ./minilibx_linux
	$(MAKE) -C ./libft
	gcc ${SRCS} -o ${NAME} -I. ${LIBRARY} -lmlx -lm -lXext -lX11 -g

clean:
	rm -f *.d *.o
	$(MAKE) clean -C libft
	$(MAKE) clean -C minilibx_linux

fclean: clean
	rm FdF
	$(MAKE) fclean -C libft
	$(MAKE) fclean -C minilibx_linux

run: all
	./FdF

re: fclean
	all

valgrind: all
	valgrind ./FdF --leak-check=full
LIBRARY = -I ./minilibx_linux -L ./minilibx_linux/ -I ./libft -L ./libft -lft

NAME = FdF

SRCS = ft_gen_map2.c main.c ft_draw_fct.c ft_gen_map.c ft_free.c ft_start.c get_next_line.c get_next_line_utils.c ft_key1.c ft_key2.c ft_key3.c ft_gen_positions.c ft_draw_map.c ft_view.c ft_map_init.c

OBJS = ${SRCS:.c=.o}
DEPS = ${SRCS:.c=.d}

INCLPATH = -I. -I ./minilibx_linux -I ./libft

.c.o:
	cc -g -Wall -Werror -Wextra ${INCLPATH} -c -MMD $< -o ${<:.c=.o}


${NAME}: ${OBJS} 
	$(MAKE) -C ./minilibx_linux
	$(MAKE) -C ./libft
	cc -g -Wall -Werror -Wextra -o ${NAME} ${OBJS} ${LIBRARY} -lmlx -lm -lXext -lX11 

all: ${NAME}

clean:
	rm -f ${OBJS} ${DEPS}
	$(MAKE) clean -C libft
	$(MAKE) clean -C minilibx_linux

fclean: clean
	rm FdF
	$(MAKE) fclean -C libft
	$(MAKE) clean -C minilibx_linux

bonus: ${NAME}

re: fclean all

-include ${DEPS}

.PHONY: all re bonus fclean clean

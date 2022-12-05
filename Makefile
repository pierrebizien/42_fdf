SRCS = main.c bresenham.c ligne.c

OBJS = ${SRCS:.c=.o}

NAME = FdF

FLAGS =# -Wall -Werror -Wextra

FRAMEWORK = -framework OpenGL -framework AppKit

PATH_MINILIBIX = minilibx_macos

LIBS = -I libft -L libft -lft -I gnl  -L gnl -lgnl -I minilibx_macos  -L minilibx_macos -lmlx


${NAME} : ${OBJS}
	+$(MAKE) -C minilibx_macos
	+$(MAKE) -C libft
	+$(MAKE) -C gnl
	gcc -o ${NAME} ${OBJS} ${LIBS} ${FRAMEWORK}


all: ${NAME}

clean:
	rm -f *.d *.o
	$(MAKE) fclean -C libft
	$(MAKE) fclean -C gnl

run: all
	./FdF

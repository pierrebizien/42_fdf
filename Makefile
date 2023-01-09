all:
	$(MAKE) -C ./minilibx_linux 
	gcc main.c -I. -I ./minilibx_linux -L ./minilibx_linux/ -lmlx -lm -lXext -lX11 -g


#ifndef _FDF_H
# define _FDF_H

#include "minilibx_macos/mlx.h"
#include "libft/libft.h"
#include "gnl/get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>

typedef struct	s_data
{
	void *img_ptr;
	char *addr;
	int bpp;
	int size_line;
	int endian;
}				t_data;

void	tracersegment(int p1[2], int p2[2],t_data *img);
int	mlx_pixel_put_img(int x, int y, int color, t_data *img);
void	bres_horizontal(int p1[2], int p2[2], t_data *img);
void	bres_vertical(int p1[2], int p2[2], t_data *img);
void ft_print_ligne(char **line1, char**line2, t_data *img);

#define START_X 600
#define START_Y 100
#endif
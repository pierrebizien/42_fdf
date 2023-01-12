#ifndef _FDF_H_
# define _FDF_H_

#include "minilibx_linux/mlx.h"
#include "libft/libft.h"

#define WIN_HEIGHT 900
#define WIN_WIDTH 1500

#define MAP "./maps/test_maps/2-2.fdf"
#define ROTATE 0.05

#include "get_next_line.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct  s_win
{
    void    *ptr;
    void    *win;
    
} t_win;

typedef struct	s_point
{
	int	x;
	int	y;
	int	h;
}				t_point;
typedef struct	s_data {
	void		*img;
	char		*addr;
	int			bpp;
	int			l_length;
	int			endian;
	int			height;
	int			width;
	float		zoom;
	int			bool_color;
	t_win		mlx;
	t_point		**map;
}				t_data;



//PROTOTYPES DRAW

int		ft_mlx_pixel_put_img(int x, int y, int color, t_data *img);
void	tracersegment(t_point p1, t_point p2, t_data *img);

t_point		**ft_generate_map(int *fd, t_data *img);
t_point    **ft_generate_position(t_data *img, t_point **map);

t_point    **ft_trace_map(t_point **map, t_data *img);

void	ft_rotate(t_data *img);


#endif
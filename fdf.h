#ifndef _FDF_H_
# define _FDF_H_

#include "minilibx_linux/mlx.h"
#include "libft/libft.h"
#include "get_next_line.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define WIN_HEIGHT 900
#define WIN_WIDTH 1500

#define MAP "./maps/test_maps/42.fdf"
#define ROTATE (3.141593 / 180) * 10
#define INCLINE (3.141593 / 180) * 5
#define RELIEF 0.3
#define	ZOOM 1.5
#define TEST

typedef struct  s_win
{
    void    *ptr;
    void    *win;
    
} t_win;

typedef struct	s_point
{
	float	x;
	float	y;
	float	h;
}				t_point;


typedef struct	s_view
{
	float	incl;
	float	rot;
	float	zoom;
	float	relief;
	
}			t_view;

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
	float		offset_x;
	float		offset_y;
	t_view		view;
}				t_data;



//PROTOTYPES DRAW

int		ft_mlx_pixel_put_img(int x, int y, int color, t_data *img);
void	tracersegment(t_point p1, t_point p2, t_data *img);

t_point		**ft_generate_map(int *fd, t_data *img);
t_point**    ft_gen_init_pos(t_data *img, t_point **map);

t_point    **ft_trace_map(t_point **map, t_data *img);

void	ft_rotate(t_data *img, int sens);
void	ft_origin(t_data *img);
void	ft_center(t_data *img);
void	ft_incline(t_data *img, int sens);
void ft_relief(t_data *img, int sens);


void    ft_init_map(t_data	*img);

#endif
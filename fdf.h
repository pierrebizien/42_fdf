#ifndef _FDF_H_
# define _FDF_H_

#include "minilibx_linux/mlx.h"
#include "libft/libft.h"

#define WIN_HEIGHT 900
#define WIN_WIDTH 1500

#include "get_next_line.h"
#include <math.h>

typedef struct  s_win
{
    void    *mlx_ptr;
    void    *win_ptr;
    
} t_win;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		l_length;
	int		endian;
}				t_data;

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

//PROTOTYPES DRAW

int		mlx_pixel_put_img(int x, int y, int color, t_data *img);
void	tracersegment(t_point p1, t_point p2, t_data *img);


#endif
#ifndef _FDF_H_
# define _FDF_H_

#include "minilibx_linux/mlx.h"

#define WIN_HEIGHT 900
#define WIN_WIDTH 1500


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

#endif
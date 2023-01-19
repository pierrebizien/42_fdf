/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:13:27 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/19 18:15:46 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx_linux/mlx.h"
# include "libft/libft.h"
# include "get_next_line.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

# define WIN_HEIGHT 900
# define WIN_WIDTH 1500

# define ROTATE (3.141593 / 180) * 10
# define INCLINE ((3.141593 / 180) * 5)
# define RELIEF 0.3
# define	ZOOM 1.5

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
	int			color_tab[5];
	int			color;
	t_win		mlx;
	t_point		**map;
	float		offset_x;
	float		offset_y;
	t_view		view;
}				t_data;

//PROTOTYPES DRAW

int		ft_mlx_pix_img(int x, int y, int color, t_data *img);
void	tracersegment(t_point p1, t_point p2, t_data *img);
t_point	**ft_generate_map(int *fd, t_data *img, char *av1);
void	ft_gen_init_pos(t_data *img);
void	ft_trace_map(t_data *img);
void	ft_rotate(t_data *img);
void	ft_incline(t_data *img);
void	ft_relief(t_data *img);
void    ft_init_map(t_data	*img);

// FONCTIONS KEYS

int			ft_key_65561(t_data *param);
int			ft_key_65563(t_data *param);
int			ft_key_65562(t_data *param);
int			ft_key_65564(t_data *param);
int			ft_key_61(t_data *param);
int			ft_key_45(t_data *param);
int			ft_key_119(t_data *param);
int			ft_key_115(t_data *param);
int			ft_key_100(t_data *param);
int			ft_key_97(t_data *param);
int			ft_key_105(t_data *param);
int			ft_key_112(t_data *param);
int			ft_key_99(t_data *param);
int			ft_mouse_4(t_data *param);
int			ft_mouse_5(t_data *param);


void	ft_free(t_data *img);
void	ft_close(t_data *param);
void	ft_start(t_data *img);
void	ft_free_double_t(t_data *img);


#endif
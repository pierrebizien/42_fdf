/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:45:55 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/12 15:44:01 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>

static void	ft_mlx_put_to_img(t_data *img, int x, int y, int color)
{
	char	*dst;
	unsigned char	*tmp;
	
	dst = img->addr + y * img->l_length + x * img->bpp;
	*(int*)dst = color;
}

int	deal_key(int key, void *param)
{
	t_data	*tmp;

	tmp = (t_data *)param;
	if (key == 65361)
	{
		tmp->bool_color = 0;
		ft_trace_map(tmp->map, tmp);
		tmp->bool_color = 1;
		
		// ROTATE
		// TRACE COULEUR
	}
}

int main(int ac, char** av)
{
    t_win	mlx_i;
	t_data	img;
	int		fd;
	t_point **map;


	fd = open(MAP, O_RDONLY);
    img.mlx.ptr = mlx_init();
	img.mlx.win = mlx_new_window(img.mlx.ptr, WIN_WIDTH, WIN_HEIGHT, "fdf");
	img.img = mlx_new_image(img.mlx.ptr, WIN_WIDTH ,WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.l_length, &img.endian);
	map = ft_generate_map(&fd, &img);
	map = ft_generate_position(&img, map);
	map = ft_trace_map(map, &img);
	img.map = map;
	mlx_put_image_to_window(img.mlx.ptr, img.mlx.win, img.img, 0 ,0);
	mlx_key_hook(img.mlx.win, deal_key, &img);
	mlx_loop(img.mlx.ptr);
}
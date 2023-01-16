/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:45:55 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/16 10:32:39 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>


int	deal_key(int key, t_data *param)
{
	param->bool_color = 0;
	ft_trace_map(param->map, param);
	param->bool_color = 1;
	if (key == 65361)
	{
		ft_rotate(param, 1);
		ft_trace_map(param->map, param);
		mlx_put_image_to_window(param->mlx.ptr, param->mlx.win, param->img, 0 ,0);
	}
	if (key == 65363)
	{
		ft_rotate(param, -1);
		ft_trace_map(param->map, param);
		mlx_put_image_to_window(param->mlx.ptr, param->mlx.win, param->img, 0 ,0);
	}
}

int main(int ac, char** av)
{
    t_win	mlx_i;
	t_data	img;
	int		fd;
	t_point **map;
	t_point p1;
	t_point p2;

	p1.x = 710;
	p1.y = 412;
	p2.x = 714;
	p2.y = 487;


	fd = open(MAP, O_RDONLY);
    img.mlx.ptr = mlx_init();
	img.mlx.win = mlx_new_window(img.mlx.ptr, WIN_WIDTH, WIN_HEIGHT, "fdf");
	img.img = mlx_new_image(img.mlx.ptr, WIN_WIDTH ,WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.l_length, &img.endian);
	map = ft_generate_map(&fd, &img);
	//pb de free ensuite
	img.map = ft_generate_position(&img, map);
	
	ft_trace_map(map, &img);
	// tracersegment(p1, p2, &img);
	// ft_mlx_pixel_put_img(p1.x, p1.y, 0xFFFFFF, &img);
	// ft_mlx_pixel_put_img(p2.x, p2.y, 0xFF00FF, &img);
	mlx_put_image_to_window(img.mlx.ptr, img.mlx.win, img.img, 0 ,0);
	mlx_key_hook(img.mlx.win, deal_key, &img);
	mlx_loop(img.mlx.ptr);
	
	// TEST

	// fd = open(MAP, O_RDONLY);
    // img.mlx.ptr = mlx_init();
	// img.mlx.win = mlx_new_window(img.mlx.ptr, WIN_WIDTH, WIN_HEIGHT, "fdf");
	// img.img = mlx_new_image(img.mlx.ptr, WIN_WIDTH ,WIN_HEIGHT);
	// img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.l_length, &img.endian);
	
	// mlx_loop(img.mlx.ptr);
}
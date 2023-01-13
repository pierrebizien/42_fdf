/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:45:55 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/13 14:58:37 by pbizien          ###   ########.fr       */
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
		ft_origin(param);
		ft_rotate(param, 1);
		ft_center(param);
		ft_trace_map(param->map, param);
		mlx_put_image_to_window(param->mlx.ptr, param->mlx.win, param->img, 0 ,0);
	}
	if (key == 65363)
	{
		ft_origin(param);
		ft_rotate(param, -1);
		ft_center(param);
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


	fd = open(MAP, O_RDONLY);
    img.mlx.ptr = mlx_init();
	img.mlx.win = mlx_new_window(img.mlx.ptr, WIN_WIDTH, WIN_HEIGHT, "fdf");
	img.img = mlx_new_image(img.mlx.ptr, WIN_WIDTH ,WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.l_length, &img.endian);
	map = ft_generate_map(&fd, &img);
	//pb de free ensuite
	img.map = ft_generate_position(&img, map);
	// ft_center(&img);
	ft_trace_map(map, &img);
	// fprintf(stderr, "\n|%d|\n",map[0][0].x);
	
	// fprintf(stderr, "\n|%d|\n",img.map[0][0].x);
	// fprintf(stderr,"map[0][0].x vaut %d\n", img.map[0][0].x);
	// fprintf(stderr,"map[0][1].x vaut %d\n", img.map[0][1].x);
	// fprintf(stderr,"map[0][2].x vaut %d\n", img.map[0][2].x);
	// fprintf(stderr,"map[1][0].x vaut %d\n", img.map[1][0].x);
	// fprintf(stderr,"map[1][1].x vaut %d\n", img.map[1][1].x);
	// fprintf(stderr,"map[1][2].x vaut %d\n", img.map[1][2].x);
	// fprintf(stderr,"map[2][0].x vaut %d\n", img.map[2][0].x);
	// fprintf(stderr,"map[2][1].x vaut %d\n", img.map[2][1].x);
	// fprintf(stderr,"map[2][2].x vaut %d\n", img.map[2][2].x);
	// fprintf(stderr, "M_PI VAUT %f", M_PI);
	mlx_put_image_to_window(img.mlx.ptr, img.mlx.win, img.img, 0 ,0);
	mlx_key_hook(img.mlx.win, deal_key, &img);
	mlx_loop(img.mlx.ptr);
}
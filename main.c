/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:45:55 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/17 14:37:12 by pbizien          ###   ########.fr       */
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
		param->view.rot += ROTATE;
		ft_gen_init_pos(param, param->map);
		// ft_relief(param, 1);
		ft_rotate(param, 1);
		ft_incline(param, 1);
		ft_trace_map(param->map, param);
		mlx_put_image_to_window(param->mlx.ptr, param->mlx.win, param->img, 0 ,0);
	}
	if (key == 65363)
	{
		param->view.rot -= ROTATE;
		ft_gen_init_pos(param, param->map);
		// ft_relief(param, 1);
		ft_rotate(param, -1);
		ft_incline(param, 1);
		ft_trace_map(param->map, param);
		mlx_put_image_to_window(param->mlx.ptr, param->mlx.win, param->img, 0 ,0);
	}
	if (key == 65362)
	{
		param->view.incl += INCLINE;
		ft_gen_init_pos(param, param->map);
		// ft_relief(param, 1);
		ft_rotate(param, -1);
		ft_incline(param, 1);

		ft_trace_map(param->map, param);
		mlx_put_image_to_window(param->mlx.ptr, param->mlx.win, param->img, 0 ,0);
	}
		if (key == 65364)
	{
		param->view.incl -= INCLINE;
		ft_gen_init_pos(param, param->map);
		// ft_relief(param, 1);
		ft_rotate(param, -1);
		ft_incline(param, 1);
		ft_trace_map(param->map, param);
		mlx_put_image_to_window(param->mlx.ptr, param->mlx.win, param->img, 0 ,0);
	}
	if (key == 61)
	{
		ft_gen_init_pos(param, param->map);
		param->view.relief += RELIEF;
		// ft_relief(param, 1);
		ft_rotate(param, -1);
		ft_incline(param, 1);
		ft_trace_map(param->map, param);
		mlx_put_image_to_window(param->mlx.ptr, param->mlx.win, param->img, 0 ,0);

	}
	if (key == 45)
	{
		ft_gen_init_pos(param, param->map);
		param->view.relief -= RELIEF;
		// ft_relief(param, -1);
		ft_rotate(param, -1);
		ft_incline(param, 1);
		ft_trace_map(param->map, param);
		mlx_put_image_to_window(param->mlx.ptr, param->mlx.win, param->img, 0 ,0);

	}
	fprintf(stderr, "INCLIN = %f", param->view.incl);
	
}

int	deal_mouse(int mouse, int x, int y, t_data *param)
{
	param->bool_color = 0;
	ft_trace_map(param->map, param);
	param->bool_color = 1;
	if (mouse == 4)
	{
		ft_gen_init_pos(param, param->map);
		param->view.zoom *= ZOOM;
		param->view.relief *= ZOOM;
		ft_rotate(param, -1);
		ft_incline(param, 1);
		ft_trace_map(param->map, param);
		mlx_put_image_to_window(param->mlx.ptr, param->mlx.win, param->img, 0 ,0);
	}
	if (mouse == 5)
	{
		ft_gen_init_pos(param, param->map);
		param->view.zoom /= ZOOM;
		param->view.relief /= ZOOM;
		ft_rotate(param, -1);
		ft_incline(param, 1);
		ft_trace_map(param->map, param);
		mlx_put_image_to_window(param->mlx.ptr, param->mlx.win, param->img, 0 ,0);
	}
}

int main(int ac, char** av)
{
    t_win	mlx_i;
	t_data	img;
	int		fd;
	t_point p1;
	t_point p2;

	// p1.x = 1250;
	// p1.y = 443;
	// p2.x = 1250;
	// p2.y = 443;


	fd = open(MAP, O_RDONLY);
    img.mlx.ptr = mlx_init();
	img.mlx.win = mlx_new_window(img.mlx.ptr, WIN_WIDTH, WIN_HEIGHT, "fdf");
	img.img = mlx_new_image(img.mlx.ptr, WIN_WIDTH ,WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.l_length, &img.endian);
	img.map = ft_generate_map(&fd, &img);
	//pb de free ensuite
	img.map = ft_gen_init_pos(&img, img.map);
	ft_init_map(&img);
	ft_trace_map(img.map, &img);
	// tracersegment(p1, p2, &img);

	mlx_put_image_to_window(img.mlx.ptr, img.mlx.win, img.img, 0 ,0);
	mlx_key_hook(img.mlx.win, deal_key, &img);
	mlx_mouse_hook(img.mlx.win, deal_mouse, &img);
	mlx_loop(img.mlx.ptr);
}

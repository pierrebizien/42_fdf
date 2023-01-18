/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:45:55 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/18 15:18:55 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>

void ft_free(t_data *img)
{
	int i;
	
	i = 0;
	fprintf(stderr, "Height %d\n", img->height);
	while (i < img->height)
	{
		free(img->map[i]);
		i++;
	}
	fprintf(stderr, "HEY\n");
	free(img->map);
	
}

int ft_close(t_data *param)
{
	ft_free(param);
	mlx_destroy_image(param->mlx.ptr, param->img);
	mlx_destroy_window(param->mlx.ptr, param->mlx.win);
	mlx_destroy_display(param->mlx.ptr);
	free(param->mlx.ptr);
	
}

int	deal_key(int key, t_data *param)
{
	static int i = 0;
	mlx_destroy_image(param->mlx.ptr, param->img);
	param->img = mlx_new_image(param->mlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	
	if (key == 65361)
	{
		param->view.rot += ROTATE;
		ft_gen_init_pos(param, param->map);
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
	if (key == 119)
	{
		param->offset_y -= 10;
		ft_gen_init_pos(param, param->map);
		ft_rotate(param, -1);
		ft_incline(param, 1);
		ft_trace_map(param->map, param);
		mlx_put_image_to_window(param->mlx.ptr, param->mlx.win, param->img, 0 ,0);
		
	}
		if (key == 115)
	{
		param->offset_y += 10;
		ft_gen_init_pos(param, param->map);
		ft_rotate(param, -1);
		ft_incline(param, 1);
		ft_trace_map(param->map, param);
		mlx_put_image_to_window(param->mlx.ptr, param->mlx.win, param->img, 0 ,0);
		
	}
		if (key == 100)
	{
		param->offset_x += 10;
		ft_gen_init_pos(param, param->map);
		ft_rotate(param, -1);
		ft_incline(param, 1);
		ft_trace_map(param->map, param);
		mlx_put_image_to_window(param->mlx.ptr, param->mlx.win, param->img, 0 ,0);
		
	}
		if (key == 97)
	{
		param->offset_x -= 10;
		ft_gen_init_pos(param, param->map);
		ft_rotate(param, -1);
		ft_incline(param, 1);
		ft_trace_map(param->map, param);
		mlx_put_image_to_window(param->mlx.ptr, param->mlx.win, param->img, 0 ,0);
		
	}
		if (key == 112)
	{
		param->view.incl = 1.57;
		param->view.rot = 0;
		ft_gen_init_pos(param, param->map);
		ft_rotate(param, -1);
		ft_incline(param, 1);
		ft_trace_map(param->map, param);
		mlx_put_image_to_window(param->mlx.ptr, param->mlx.win, param->img, 0 ,0);
		
	}
		if (key == 105)
	{
		param->view.incl = 1.57;
		param->view.rot = 0;
		ft_gen_init_pos(param, param->map);
		ft_rotate(param, -1);
		ft_incline(param, 1);
		ft_trace_map(param->map, param);
		mlx_put_image_to_window(param->mlx.ptr, param->mlx.win, param->img, 0 ,0);
		
	}
		if(key == 65307)
			mlx_loop_end(param->mlx.ptr);
		if (key == 99)
	{
		i++;
		if (i > 4)
			i = 0;
		param->color = param->color_tab[i];
		ft_gen_init_pos(param, param->map);
		ft_rotate(param, -1);
		ft_incline(param, 1);
		ft_trace_map(param->map, param);
		mlx_put_image_to_window(param->mlx.ptr, param->mlx.win, param->img, 0 ,0);
	}
	
}

int	deal_mouse(int mouse, int x, int y, t_data *param)
{
	mlx_destroy_image(param->mlx.ptr, param->img);
	param->img = mlx_new_image(param->mlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	if (mouse == 4)
	{
		if (param->view.zoom * ZOOM < 2000)
		{
			param->view.zoom *= ZOOM;
			param->view.relief *= ZOOM;
			ft_gen_init_pos(param, param->map);
			ft_rotate(param, -1);
			ft_incline(param, 1);
			ft_trace_map(param->map, param);
			mlx_put_image_to_window(param->mlx.ptr, param->mlx.win, param->img, 0 ,0);
		}
		else
		{
			ft_trace_map(param->map, param);
		}
	}
	if (mouse == 5)
	{
		if (param->view.zoom / ZOOM > 0)
		{
			param->view.zoom /= ZOOM;
			param->view.relief /=ZOOM;
			ft_gen_init_pos(param, param->map);
			fprintf(stderr, "ZOOM %f \n", param->view.zoom);
			ft_rotate(param, -1);
			ft_incline(param, 1);
			ft_trace_map(param->map, param);
			mlx_put_image_to_window(param->mlx.ptr, param->mlx.win, param->img, 0 ,0);
		}
		else
			ft_trace_map(param->map, param);
	}
	fprintf(stderr, "%d x %d y %d", mouse, x, y);
}



int main(int ac, char** av)
{
    t_win	mlx_i;
	t_data	img;
	int		fd;

	fd = open(MAP, O_RDONLY);
    img.mlx.ptr = mlx_init();
	img.mlx.win = mlx_new_window(img.mlx.ptr, WIN_WIDTH, WIN_HEIGHT, "fdf");
	img.img = mlx_new_image(img.mlx.ptr, WIN_WIDTH ,WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.l_length, &img.endian);
	img.map = ft_generate_map(&fd, &img);
	ft_gen_init_pos(&img, img.map);
	ft_init_map(&img);
	ft_trace_map(img.map, &img);
	mlx_put_image_to_window(img.mlx.ptr, img.mlx.win, img.img, 0 ,0);
	mlx_hook(img.mlx.win, 17, 0, ft_close, &img);
	mlx_key_hook(img.mlx.win, deal_key, &img);
	mlx_mouse_hook(img.mlx.win, deal_mouse, &img);
	mlx_loop(img.mlx.ptr);
	ft_close(&img);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:45:55 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/10 19:11:26 by pbizien          ###   ########.fr       */
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

int main(int ac, char** av)
{
    t_win	mlx_i;
	t_data	img;
	int		fd;
	t_point **map;

	fd = open(MAP, O_RDONLY);
    mlx_i.mlx_ptr = mlx_init();
	mlx_i.win_ptr = mlx_new_window(mlx_i.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "fdf");
	img.img = mlx_new_image(mlx_i.mlx_ptr, WIN_WIDTH ,WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.l_length, &img.endian);
	map = ft_generate_map(&fd, &img);
	ft_generate_position(&img, map);
	mlx_put_image_to_window(mlx_i.mlx_ptr, mlx_i.win_ptr, img.img, 0 ,0);
	// mlx_loop(mlx_i.mlx_ptr);
}
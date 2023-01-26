/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:45:55 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/26 13:50:34 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_img(t_data *img)
{
	mlx_destroy_window(img->mlx.ptr, img->mlx.win);
	free(img->mlx.ptr);
}

void	ft_free_addr(t_data *img)
{
	mlx_destroy_window(img->mlx.ptr, img->mlx.win);
	mlx_destroy_image(img->mlx.ptr, img->img);
	free(img->mlx.ptr);
}

void	ft_free_fd(t_data *img)
{
	mlx_destroy_window(img->mlx.ptr, img->mlx.win);
	mlx_destroy_image(img->mlx.ptr, img->img);
	mlx_destroy_display(img->mlx.ptr);
	free(img->mlx.ptr);
	write(2, "Error file\n", 11);
}

int	main(int ac, char **av)
{
	t_data	img;
	int		fd;

	if (ac != 2)
		return (write(2, "Error file\n", 11), -1);
	img.mlx.ptr = mlx_init();
	if (!img.mlx.ptr)
		return (-1);
	img.mlx.win = mlx_new_window(img.mlx.ptr, WIN_WIDTH, WIN_HEIGHT, "fdf");
	if (!img.mlx.win)
		return (free(img.mlx.ptr), -1);
	img.img = mlx_new_image(img.mlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!img.img)
		return (ft_free_img(&img), -1);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.l_length, &img.endian);
	if (!img.addr)
		return (ft_free_addr(&img), -1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_free_fd(&img), (-1));
	img.map = ft_generate_map(&fd, &img, av[1]);
	if (!img.map)
		return (ft_free_fd(&img), close(fd), -1);
	ft_start(&img);
	close(fd);
}

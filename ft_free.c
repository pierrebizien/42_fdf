/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:20:13 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/26 13:49:58 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free(t_data *img)
{
	int	i;

	i = 0;
	while (i < img->height)
	{
		free(img->map[i]);
		i++;
	}
	free(img->map);
}

void	ft_close(t_data *param)
{
	ft_free(param);
	mlx_destroy_image(param->mlx.ptr, param->img);
	mlx_destroy_window(param->mlx.ptr, param->mlx.win);
	mlx_destroy_display(param->mlx.ptr);
	free(param->mlx.ptr);
}

void	ft_free_double_t(t_data *img)
{
	int	i;

	i = 0;
	while (img->map[i])
	{
		free(img->map[i]);
		i++;
	}
	free(img->map);
}

void	ft_free_double_t2(t_point **map, int i)
{
	int	j;

	j = 0;
	while (j <= i)
	{
		free(map[j]);
		j++;
	}
	free(map);
}

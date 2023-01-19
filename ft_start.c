/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:13:33 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/19 17:32:21 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key2(int key, t_data *param)
{
	if (key == 119)
		return (ft_key_119(param));
	else if (key == 115)
		return (ft_key_115(param));
	else if (key == 100)
		return (ft_key_100(param));
	else if (key == 97)
		return (ft_key_97(param));
	else if (key == 112)
		return (ft_key_112(param));
	else if (key == 105)
		return (ft_key_105(param));
	else if (key == 65307)
		mlx_loop_end(param->mlx.ptr);
	else if (key == 99)
		return (ft_key_99(param));
	return (0);
}

int	deal_key(int key, t_data *param)
{
	mlx_destroy_image(param->mlx.ptr, param->img);
	param->img = mlx_new_image(param->mlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	if (key == 65361)
		return (ft_key_65561(param));
	else if (key == 65363)
		return (ft_key_65563(param));
	else if (key == 65362)
		return (ft_key_65562(param));
	else if (key == 65364)
		return (ft_key_65564(param));
	else if (key == 61)
		return (ft_key_61(param));
	else if (key == 45)
		return (ft_key_45(param));
	else
		return (deal_key2(key, param));
}

int	deal_mouse(int mouse, int x, int y, t_data *param)
{
	mlx_destroy_image(param->mlx.ptr, param->img);
	param->img = mlx_new_image(param->mlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	(void)x;
	(void)y;
	if (mouse == 4)
		return (ft_mouse_4(param));
	else if (mouse == 5)
		return (ft_mouse_5(param));
	return (0);
}

int	ft_my_loopend(t_data *img)
{
	mlx_loop_end(img->mlx.ptr);
	return (0);
}

void	ft_start(t_data *img)
{
	ft_gen_init_pos(img);
	ft_init_map(img);
	ft_trace_map(img);
	mlx_put_image_to_window(img->mlx.ptr, img->mlx.win, img->img, 0, 0);
	mlx_hook(img->mlx.win, 17, 0, ft_my_loopend, img);
	mlx_key_hook(img->mlx.win, deal_key, img);
	mlx_mouse_hook(img->mlx.win, deal_mouse, img);
	mlx_loop(img->mlx.ptr);
	ft_close(img);
}

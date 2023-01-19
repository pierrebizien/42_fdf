/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:59:40 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/19 15:48:58 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_key_112(t_data *param)
{
	param->view.incl = 1.57;
	param->view.rot = 0;
	ft_gen_init_pos(param);
	ft_rotate(param);
	ft_incline(param);
	ft_trace_map(param);
	mlx_put_image_to_window(param->mlx.ptr, param->mlx.win, param->img, 0, 0);
	return (0);
}

int	ft_key_105(t_data *param)
{
	param->view.incl = 1.57;
	param->view.rot = 0;
	ft_gen_init_pos(param);
	ft_rotate(param);
	ft_incline(param);
	ft_trace_map(param);
	mlx_put_image_to_window(param->mlx.ptr, param->mlx.win, param->img, 0, 0);
	return (0);
}

int	ft_key_99(t_data *param)
{
	static int	i = 0;

	i++;
	if (i > 4)
		i = 0;
	param->color = param->color_tab[i];
	ft_gen_init_pos(param);
	ft_rotate(param);
	ft_incline(param);
	ft_trace_map(param);
	mlx_put_image_to_window(param->mlx.ptr, param->mlx.win, param->img, 0, 0);
	return (0);
}

int	ft_mouse_4(t_data *param)
{
	if (param->view.zoom * ZOOM < 2000)
	{
		param->view.zoom *= ZOOM;
		param->view.relief *= ZOOM;
		ft_gen_init_pos(param);
		ft_rotate(param);
		ft_incline(param);
		ft_trace_map(param);
		mlx_put_image_to_window(param->mlx.ptr, \
			param->mlx.win, param->img, 0, 0);
	}
	else
	{
		ft_trace_map(param);
	}
	return (0);
}

int	ft_mouse_5(t_data *param)
{
	if (param->view.zoom / ZOOM > 0)
	{
		param->view.zoom /= ZOOM;
		param->view.relief /= ZOOM;
		ft_gen_init_pos(param);
		ft_rotate(param);
		ft_incline(param);
		ft_trace_map(param);
		mlx_put_image_to_window(param->mlx.ptr, \
			param->mlx.win, param->img, 0, 0);
	}
	else
		ft_trace_map(param);
	return (0);
}

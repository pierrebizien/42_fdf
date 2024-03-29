/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:35:22 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/23 14:03:37 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_key_45(t_data *param)
{
	ft_gen_init_pos(param);
	param->view.relief -= RELIEF;
	ft_rotate(param);
	ft_incline(param);
	ft_trace_map(param);
	mlx_put_image_to_window(param->mlx.ptr, param->mlx.win, param->img, 0, 0);
	return (0);
}

int	ft_key_119(t_data *param)
{
	ft_gen_init_pos(param);
	param->offset_y -= 10;
	ft_rotate(param);
	ft_incline(param);
	ft_trace_map(param);
	mlx_put_image_to_window(param->mlx.ptr, param->mlx.win, param->img, 0, 0);
	return (0);
}

int	ft_key_115(t_data *param)
{
	ft_gen_init_pos(param);
	param->offset_y += 10;
	ft_rotate(param);
	ft_incline(param);
	ft_trace_map(param);
	mlx_put_image_to_window(param->mlx.ptr, param->mlx.win, param->img, 0, 0);
	return (0);
}

int	ft_key_100(t_data *param)
{
	ft_gen_init_pos(param);
	param->offset_x += 10;
	ft_rotate(param);
	ft_incline(param);
	ft_trace_map(param);
	mlx_put_image_to_window(param->mlx.ptr, param->mlx.win, param->img, 0, 0);
	return (0);
}

int	ft_key_97(t_data *param)
{
	ft_gen_init_pos(param);
	param->offset_x -= 10;
	ft_rotate(param);
	ft_incline(param);
	ft_trace_map(param);
	mlx_put_image_to_window(param->mlx.ptr, param->mlx.win, param->img, 0, 0);
	return (0);
}

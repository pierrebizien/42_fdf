/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:25:12 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/18 17:51:11 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_key_65561(t_data *param)
{
		param->view.rot += ROTATE;
		ft_gen_init_pos(param);
		ft_rotate(param);
		ft_incline(param);
		ft_trace_map(param);
		mlx_put_image_to_window(param->mlx.ptr, param->mlx.win, param->img, 0 ,0);
		return (0);
}

int	ft_key_65563(t_data *param)
{
		param->view.rot -= ROTATE;
		ft_gen_init_pos(param);
		ft_rotate(param);
		ft_incline(param);
		ft_trace_map(param);
		mlx_put_image_to_window(param->mlx.ptr, param->mlx.win, param->img, 0 ,0);
		return (0);
}

int	ft_key_65562(t_data *param)
{
		param->view.incl += INCLINE;
		ft_gen_init_pos(param);
		ft_rotate(param);
		ft_incline(param);
		ft_trace_map(param);
		mlx_put_image_to_window(param->mlx.ptr, param->mlx.win, param->img, 0 ,0);
		return (0);
}

int	ft_key_65564(t_data *param)
{
		param->view.incl -= INCLINE;
		ft_gen_init_pos(param);
		ft_rotate(param);
		ft_incline(param);
		ft_trace_map(param);
		mlx_put_image_to_window(param->mlx.ptr, param->mlx.win, param->img, 0 ,0);
		return (0);
}

int	ft_key_61(t_data *param)
{
		ft_gen_init_pos(param);
		param->view.relief += RELIEF;
		ft_rotate(param);
		ft_incline(param);
		ft_trace_map(param);
		mlx_put_image_to_window(param->mlx.ptr, param->mlx.win, param->img, 0 ,0);
		return (0);
}
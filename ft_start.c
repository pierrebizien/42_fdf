/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:13:33 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/19 16:22:50 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_start(t_data *img)
{
	ft_init_map(&img);
	ft_trace_map(&img);
	mlx_put_image_to_window(img.mlx.ptr, img.mlx.win, img.img, 0 ,0);
	mlx_hook(img.mlx.win, 17, 0, ft_my_loopend, &img);
	mlx_key_hook(img.mlx.win, deal_key, &img);
	mlx_mouse_hook(img.mlx.win, deal_mouse, &img);
	mlx_loop(img.mlx.ptr);
	ft_close(&img);
}
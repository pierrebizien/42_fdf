/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:45:33 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/23 14:02:25 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_trace_map(t_data *img)
{
	int	i;
	int	j;

	i = 0;
	if (img->width <= 1 && img->height <= 1)
		ft_one_point(img);
	while (i <= img->height - 1)
	{
		j = 0;
		while (j <= img->width - 1)
		{
			if (j < img->width - 1)
				tracersegment(img->map[i][j], img->map[i][j + 1], img);
			if (i < img->height - 1)
			{
				tracersegment(img->map[i][j], img->map[i + 1][j], img);
			}
			j++;
		}
		i++;
	}
}

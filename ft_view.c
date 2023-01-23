/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_view.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:21:52 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/23 11:05:14 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_relief(t_data *img)
{
	int		i;
	int		j;

	i = 0;
	while (i < img->height)
	{
		j = 0;
		while (j < img->width)
		{
			img->map[i][j].h *= img->view.relief;
			j++;
		}
		i++;
	}
}

void	ft_incline(t_data *img)
{
	int		i;
	int		j;

	i = 0;
	while (i < img->height)
	{
		j = 0;
		while (j < img->width)
		{
			img->map[i][j].y = (cos(img->view.incl) * img->map[i][j].y - \
			sin(img->view.incl) * img->map[i][j].h * img->view.relief);
			j++;
		}
		i++;
	}
} 

void	ft_rotate(t_data *img)
{
	int		i;
	int		j;
	double	tmp;

	i = 0;
	while (i < img->height)
	{
		j = 0;
		while (j < img->width)
		{
			tmp = img->map[i][j].x;
			img->map[i][j].x = (cos(img->view.rot) * img->map[i][j].x - \
			sin(img->view.rot) * img->map[i][j].y);
			img->map[i][j].y = sin(img->view.rot) * tmp + \
			cos(img->view.rot) * img->map[i][j].y;
			j++;
		}
		i++;
	}
}

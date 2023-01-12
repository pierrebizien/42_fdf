/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:21:52 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/12 17:39:27 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rotate(t_data *img)
{
	int	i;
	int	j;
	double tmp;
	
	i = 0;
	while (i < img->height)
	{
		j = 0;
		while(j < img->width)
		{
			// fprintf(stderr, "j vaut %d et i vaut %d\n", j , i);
			// fprintf(stderr, "\n map[%d][%d].x vaut %d\n", i, j, img->map[2][1].x);
			tmp = img->map[i][j].x;
			img->map[i][j].x = (int)(cos(ROTATE) * (double)img->map[i][j].x - \
			sin(ROTATE) * (double)img->map[i][j].y);
			img->map[i][j].y = (int)(sin(ROTATE) * (double)tmp + \
			cos(ROTATE) * (double)img->map[i][j].y);
			// img->map[i][j].x = (int)tmp;
			
			// printf("x vaut %d et |%f|\n", img->map[i][j]->x, cos(ROTATE) * (double)img->map[i][j]->x - (sin(ROTATE) * (double)img->map[i][j]->y));
			j++;
		}
		i++;
	}
}

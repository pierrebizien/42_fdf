/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:21:52 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/13 15:18:45 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rotate(t_data *img, int sens)
{
	int	i;
	int	j;
	double tmp;
	double tmp2;
	
	i = 0;
	fprintf(stderr, "\nUN x 0.0 vaut %f \n", img->map[0][0].x);
	fprintf(stderr, "y 0.0 vaut %f \n", img->map[0][0].y);
	fprintf(stderr, "x 0.1 vaut %f \n", img->map[0][1].x);
	fprintf(stderr, "y 0.1 vaut %f \n", img->map[0][1].y);
	fprintf(stderr, "x 1.0 vaut %f \n", img->map[1][0].x);
	fprintf(stderr, "y 1.0 vaut %f \n", img->map[1][0].y);
	fprintf(stderr, "x 1.1 vaut %f \n", img->map[1][1].x);
	fprintf(stderr, "y 1.1 vaut %f \n", img->map[1][1].y);
	fprintf(stderr, "\n---------------\n");
	while (i < img->height)
	{
		j = 0;
		while(j < img->width)
		{
			tmp = img->map[i][j].x;
			img->map[i][j].x = (cos(sens * ROTATE) * img->map[i][j].x - \
			sin((double)sens * ROTATE) * img->map[i][j].y);
			img->map[i][j].y = (sin(sens * ROTATE) * tmp + \
			cos((double)sens * ROTATE) * img->map[i][j].y);
			// img->map[i][j].x = (int)tmp;
			
			// printf("x vaut %d et |%f|\n", img->map[i][j]->x, cos(ROTATE) * (double)img->map[i][j]->x - (sin(ROTATE) * (double)img->map[i][j]->y));
			j++;
		}
		i++;
	}
	fprintf(stderr, "\nUN x 0.0 vaut %f \n", img->map[0][0].x);
	fprintf(stderr, "y 0.0 vaut %f \n", img->map[0][0].y);
	fprintf(stderr, "x 0.1 vaut %f \n", img->map[0][1].x);
	fprintf(stderr, "y 0.1 vaut %f \n", img->map[0][1].y);
	fprintf(stderr, "x 1.0 vaut %f \n", img->map[1][0].x);
	fprintf(stderr, "y 1.0 vaut %f \n", img->map[1][0].y);
	fprintf(stderr, "x 1.1 vaut %f \n", img->map[1][1].x);
	fprintf(stderr, "y 1.1 vaut %f \n", img->map[1][1].y);
	fprintf(stderr, "\n---------------\n");

}

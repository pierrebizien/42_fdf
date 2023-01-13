/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:21:52 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/13 14:56:09 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_origin(t_data *img)
{
	int	i;
	int	j;
	float tmpx;
	float tmpy;
	
	tmpx = img->map[0][0].x;
	tmpy = img->map[0][0].y;
	i = 0;
	while (i < img->height)
	{
		j = 0;
		while(j < img->width)
		{
			img->map[i][j].x -= tmpx + ((img->width - 1) * img->zoom) / 2;
			img->map[i][j].y -= tmpy + ((img->height - 1) * img->zoom) / 2;
			j++;
		}
		i++;
	}
}

void	ft_center(t_data *img)
{
	int	i;
	int	j;
	float tmpx;
	float tmpy;
	
	i = 0;
	tmpx = img->map[0][0].x;
	tmpy = img->map[0][0].y;
	fprintf(stderr, "tmpx vaut %f et y vaut %f \n", tmpx, tmpy);
	while (i < img->height)
	{
		j = 0;
		while(j < img->width)
		{
			img->map[i][j].x += -tmpx + WIN_WIDTH / 2 - ((img->width - 1) * img->zoom / 2);
			img->map[i][j].y += -tmpy + WIN_HEIGHT / 2 - ((img->height - 1) * img->zoom / 2);
			j++;
		}
		i++;
	}
}

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:21:52 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/16 17:10:33 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_relief(t_data *img, int sens)
{
	int	i;
	int	j;
	double tmp;
	double tmp2;
	
	i = 0;
	while (i < img->height)
	{
		j = 0;
		while(j < img->width)
		{
			
			img->map[i][j].h *= img->view.relief; 
			// img->map[i][j].x = (int)tmp;
			
			// printf("x vaut %d et |%f|\n", img->map[i][j]->x, cos(ROTATE) * (double)img->map[i][j]->x - (sin(ROTATE) * (double)img->map[i][j]->y));
			j++;
		}
		i++;
	}
}


void	ft_incline(t_data *img, int sens)
{
	int	i;
	int	j;
	double tmp;
	double tmp2;
	
	i = 0;
	while (i < img->height)
	{
		j = 0;
		while(j < img->width)
		{
			tmp = img->map[i][j].y;
			img->map[i][j].y = (cos(img->view.incl) * img->map[i][j].y - \
			sin(img->view.incl) * img->map[i][j].h*img->view.relief);
			// img->map[i][j].h = sin(img->view.incl) * img->map[i][j].y + \
			// cos(img->view.incl) * img->map[i][j].h;
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
	
	while (i < img->height)
	{
		j = 0;
		while(j < img->width)
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
	// fprintf(stderr, "\nDEUX x 0.0 vaut %f \n", img->map[0][0].x);
	// fprintf(stderr, "y 0.0 vaut %f \n", img->map[0][0].y);
	// fprintf(stderr, "x 0.1 vaut %f \n", img->map[0][1].x);
	// fprintf(stderr, "y 0.1 vaut %f \n", img->map[0][1].y);
	// fprintf(stderr, "x 1.0 vaut %f \n", img->map[1][0].x);
	// fprintf(stderr, "y 1.0 vaut %f \n", img->map[1][0].y);
	// fprintf(stderr, "x 1.1 vaut %f \n", img->map[1][1].x);
	// fprintf(stderr, "y 1.1 vaut %f \n", img->map[1][1].y);
	// fprintf(stderr, "\n---------------\n");

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:45:51 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/10 14:45:52 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static int	ft_color(int valeur)
{
	int	i;
	int	color;

	i = 0;
	color = 0x00FFFFFF;
	while (i <= valeur)
	{
		color-= 
		i++;
	}
	return (color);
	
}
int	mlx_pixel_put_img(int x, int y, int color, t_data *img)
{
	char *dst;
	dst = img->addr + (y*img->l_length + x*(img->bpp/8));
	*(int*)dst = color;
	return (0);
}

static void	bres_horizontal(t_point p1, t_point p2, t_data *img)
{
	float temp;
	float m;
	int sens;

	if (p1.x < p2.x)
		sens = 1;
	else 
		sens = -1;
	m = (float)(p2.y - p1.y)/ ((float)(p2.x - p1.x));
	temp = p1.y;
	while (p1.x != p2.x)
	{
		temp = temp + m * 1;
		if(temp - (int)temp > 0.5)
			mlx_pixel_put_img(p1.x, (int)(temp + 1), 0x00FFFFFF, img);
		else
			mlx_pixel_put_img(p1.x, (int)(temp), 0x00FFFFFF, img);
		p1.x+= sens;
	}
}

static void	bres_vertical(t_point p1, t_point p2, t_data *img)
{
	float temp;
	float m;
	int sens;

	if (p1.y < p2.y)
		sens = 1;
	else 
		sens = -1;
	m = (float)(p2.x - p1.x)/ ((float)(p2.y - p1.y));
	temp = p1.x;
	while (p1.y != p2.y)
	{
		temp = temp + m * 1;
		if(temp - (int)temp > 0.5)
			mlx_pixel_put_img((int)(temp + 1), p1.y, 0x00FFFFFF, img);
		else
			mlx_pixel_put_img((int)temp, p1.y, 0x00FFFFFF, img);
		p1.y+= sens;
	}
}

void	tracersegment(t_point p1, t_point p2, t_data *img)
{
	float m;
	m = (float)(p2.y - p1.y)/ ((float)(p2.x - p1.x));
	if (fabs(m) > 0.5)
		bres_vertical(p1, p2, img);
	else
		bres_horizontal(p1, p2, img);
}

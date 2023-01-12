/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:45:51 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/12 15:34:13 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static int	ft_color(int valeur, t_data *img)
{
	int	i;
	int	color;
	
	if (img->bool_color == 0)
		color = 0;
	else
		color = (valeur + 1) * 7000;
	return (color);
	
}
int	ft_mlx_pixel_put_img(int x, int y, int color, t_data *img)
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
		if (temp >= WIN_HEIGHT || p1.x >= WIN_WIDTH)
			return ;
		if(temp - (int)temp > 0.5)
			ft_mlx_pixel_put_img(p1.x, (int)(temp + 1), ft_color(p1.h, img), img);
		else
			ft_mlx_pixel_put_img(p1.x, (int)(temp),  ft_color(p1.h, img), img);
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
	// if (p2.x - p1.x == 0)
	// 	m = p2.y - p1.y + 1;
	// else
	m = (float)(p2.x - p1.x)/ ((float)(p2.y - p1.y));
	temp = p1.x;
	while (p1.y != p2.y + 1)
	{
		temp = temp + m * 1;
		if (temp >= WIN_WIDTH || p1.y >= WIN_HEIGHT)
			return ;
		else
		{
			if(temp - (int)temp > 0.5)
				ft_mlx_pixel_put_img((int)(temp + 1), p1.y,  ft_color(p1.h, img), img);
			else
				ft_mlx_pixel_put_img((int)temp, p1.y,  ft_color(p1.h, img), img);
			p1.y+= sens;
		}
	}
}

void	tracersegment(t_point p1, t_point p2, t_data *img)
{
	float m;

	if (p2.x - p1.x == 0)
	{
		m = (float)(p2.y - p1.y);
	}
	else
		m = (float)(p2.y - p1.y)/ ((float)(p2.x - p1.x));
	if (fabs(m) > 0.5)
	{
		bres_vertical(p1, p2, img);
	}
	else
	{
		bres_horizontal(p1, p2, img);
	}
}

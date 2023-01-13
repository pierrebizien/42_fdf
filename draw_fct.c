/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:45:51 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/13 17:59:22 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static int	ft_color(int valeur, t_data *img)
{
	int	i;
	int	color;
	
	if (img->bool_color == 0)
	{
		color = 0;
	}
	else
		color = (valeur + 1) * 12000;
	return (color);
	
}
int	ft_mlx_pixel_put_img(int x, int y, int color, t_data *img)
{
	char *dst;
	// fprintf(stderr, "\n\navant de print x vaut %d et y vaut %d \n", x, y);
	dst = img->addr + (y*img->l_length + x*(img->bpp/8));
	*(int*)dst = color;
	return (0);
}

static void	bres_horizontal(t_point p1, t_point p2, t_data *img)
{
	float temp;
	float m;
	int sens;
	int tmp;

	
	// fprintf(stderr, "p1x vaut %d et p1y vaut %d\n", (int)(p1.x), (int)(p1.y));
	// fprintf(stderr, "p2x vaut %d et p2y vaut %d\n", (int)(p2.x), (int)(p2.y));
	if (p1.x < p2.x)
		sens = 1;
	else 
		sens = -1;
	m = (float)(p2.y - p1.y)/ ((float)(p2.x - p1.x));
	temp = p1.y;
	fprintf(stderr, "horiz m vaut %f\n", m);
	while ((int)p1.x != (int)p2.x + 1)
	{
		temp = temp + fabs(m) * 1;
		if ((int)temp + 1 > WIN_HEIGHT || (int)p1.x > WIN_WIDTH || (int)temp < 0 || (int)p1.x < 0)
		{
			// fprintf(stderr, "temp vaut %f \n", temp);
			return ;
		}
		if(temp - (int)temp > 0.5)
		{
			// fprintf(stderr, "\n\navant de cast x vaut %f et y vaut %d \n", p1.x, (int)(temp + 1));
			ft_mlx_pixel_put_img((int)p1.x, (int)(temp + 1), ft_color(p1.h, img), img);
		}
		else
		{
			// fprintf(stderr, "\n\navant de cast x vaut %f et y vaut %d \n", p1.x, (int)temp);
			ft_mlx_pixel_put_img((int)p1.x, (int)(temp), ft_color(p1.h, img), img);
		}
		
		p1.x+= sens;
		
	}
	// fprintf(stderr, "p1x vaut %d et p1y vaut %d\n", (int)(p1.x), (int)(temp));
	// fprintf(stderr, "p2x vaut %d et p2y vaut %d\n", (int)(p2.x), (int)(temp));
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
	fprintf(stderr, "vert m vaut %f\n", m);
	// fprintf(stderr, "p2x vaut %d et p2y vaut %d\n", (int)(p2.x), (int)(p2.y));
	while ((int)p1.y != (int)p2.y + 1)
	{
		temp = temp + fabs(m) * 1;
		if (temp + 1 > WIN_WIDTH || p1.y > WIN_HEIGHT || temp < -0 || p1.y < -0)
			return ;
		else
		{
			if(temp - (int)temp > 0.5)
			{

				// fprintf(stderr, "\n\navant de cast y vaut %d et x vaut %d \n", (int)p1.y, (int)(temp + 1));
				ft_mlx_pixel_put_img((int)(temp + 1), (int)p1.y,  ft_color(p1.h, img), img);
			}
			else
			{
				
				// fprintf(stderr, "\n\navant de cast y vaut %d et x vaut %d \n", (int)p1.y, (int)(temp));
				ft_mlx_pixel_put_img((int)temp, (int)p1.y,  ft_color(p1.h, img), img);
			}
			
			p1.y+= sens;
		}
		// fprintf(stderr, "p1x vaut %d et p1y vaut %d\n", (int)(temp), (int)(p1.y));
		// fprintf(stderr, "p2x vaut %d et p2y vaut %d\n", (int)(temp), (int)(p2.y));
	}
}

void	ft_offset(t_point *p1, t_point *p2, t_data *img)
{
	p1->x += img->offset_x;
	p1->y += img->offset_y;
	p2->x += img->offset_x;
	p2->y += img->offset_y;
}

void	tracersegment(t_point p1, t_point p2, t_data *img)
{
	float m;

	ft_offset(&p1, &p2, img);
	if (p2.x - p1.x == 0)
	{
		fprintf(stderr, "coucou\n");
		m = (float)(p2.y - p1.y);
	}
	else
		m = (float)(p2.y - p1.y)/ ((float)(p2.x - p1.x));
	fprintf(stderr, "\n------------\np1 x vaut %f\n", p1.x);
	fprintf(stderr, "\np1 y vaut %f\n", p1.y);
	fprintf(stderr, "\np2 x vaut %f\n", p2.x);
	fprintf(stderr, "\np2 y vaut %f\n", p2.y);
	fprintf(stderr, "\nm ici vaut %f\n", m);
	if (fabs(m) > 1)
	{
		bres_vertical(p1, p2, img);
	}
	else
	{
		bres_horizontal(p1, p2, img);
	}
}

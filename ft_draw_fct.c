/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:45:51 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/18 16:02:24 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	ft_mlx_pix_img(int x, int y, int color, t_data *img)
{
	char	*dst;

	dst = img->addr + (y * img->l_length + x * (img->bpp / 8));
	*(int *)dst = color;
	return (0);
}

static void	bres_horizontal(t_point p1, t_point p2, t_data *img)
{
	float	temp;
	float	m;
	int		s;

	if (p1.x < p2.x)
		s = 1;
	else
		s = -1;
	m = (p2.y - p1.y) / (p2.x - p1.x);
	temp = p1.y;
	while ((s == 1 && p1.x < p2.x) || (s == -1 && p1.x > p2.x))
	{
		temp = temp + m * s;
		if (!((int)temp + 1 >= WIN_HEIGHT || (int)p1.x >= WIN_WIDTH || \
		(int)temp <= 0 || (int)p1.x <= 0))
		{
			if (temp - (int)temp > 0.5)
				ft_mlx_pix_img((int)p1.x, (int)(temp + 1), img->color, img);
			else
				ft_mlx_pix_img((int)p1.x, (int)(temp), img->color, img);
		}
		p1.x += (float)s;
	}
}

static	void	bres_vertical(t_point p1, t_point p2, t_data *img)
{
	float	temp;
	float	m;
	int		sens;

	if (p1.y < p2.y)
		sens = 1;
	else
		sens = -1;
	m = (float)(p2.x - p1.x) / ((float)(p2.y - p1.y));
	temp = p1.x;
	while (((sens == 1 && p1.y < p2.y) || (sens == -1 && p1.y > p2.y)))
	{
		temp = temp + m * sens;
		if (!(temp + 1 >= WIN_WIDTH || p1.y >= WIN_HEIGHT \
		|| temp <= 0 || p1.y <= -0))
		{
			if (temp - (int)temp > 0.5)
				ft_mlx_pix_img((int)(temp + 1), (int)p1.y, img->color, img);
			else
				ft_mlx_pix_img((int)temp, (int)p1.y, img->color, img);
		}
		p1.y += (float)sens;
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
	float	m;

	ft_offset(&p1, &p2, img);
	if ((p1.x < 0 || p1.x > WIN_WIDTH || p1.y < 0 || p1.y > WIN_HEIGHT) && \
	(p2.x < 0 || p2.x > WIN_WIDTH || p2.y < 0 || p2.y > WIN_HEIGHT))
		return ;
	if (p2.x - p1.x == 0)
	{
		m = (float)(p2.y - p1.y);
	}
	else
		m = (float)(p2.y - p1.y) / ((float)(p2.x - p1.x));
	if (fabs(m) > 1)
	{
		bres_vertical(p1, p2, img);
	}
	else
	{
		bres_horizontal(p1, p2, img);
	}
}

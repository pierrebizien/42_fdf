#include "test.h"
#include <math.h>
#include <stdio.h>

int	ft_color(int valeur)
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
	dst = img->addr + (y*img->size_line + x*(img->bpp/8));
	*(int*)dst = color;
	return (0);
}

void	bres_horizontal(int p1[2], int p2[2], t_data *img)
{
	float temp;
	float m;
	int sens;

	if (p1[0] < p2[0])
		sens = 1;
	else 
		sens = -1;
	m = (float)(p2[1] - p1[1])/ fabs(((float)(p2[0] - p1[0])));
	temp = p1[1];
	while (p1[0] != p2[0])
	{
		temp = temp + m * 1;
		if(temp - (int)temp > 0.5)
			mlx_pixel_put_img(p1[0], (int)(temp + 1), 0x00FFFFFF, img);
		else
			mlx_pixel_put_img(p1[0], (int)(temp), 0x00FFFFFF, img);
		p1[0]+= sens;
	}
}

void	bres_vertical(int p1[2], int p2[2], t_data *img)
{
	float temp;
	float m;
	int sens;

	if (p1[1] < p2[1])
		sens = 1;
	else 
		sens = -1;
	m = (float)(p2[0] - p1[0])/ fabs(((float)(p2[1] - p1[1])));
	temp = p1[0];
	while (p1[1] != p2[1])
	{
		temp = temp + m * 1;
		if(temp - (int)temp > 0.5)
			mlx_pixel_put_img((int)(temp + 1), p1[1], 0x00FFFFFF, img);
		else
			mlx_pixel_put_img((int)temp, p1[1], 0x00FFFFFF, img);
		p1[1]+= sens;
	}
}

void	tracersegment(int p1[2], int p2[2], t_data *img)
{
	float m;
	int	sens;
	int temp[4];

	m = (float)(p2[1] - p1[1])/ fabs(((float)(p2[0] - p1[0])));
	temp[0] = p1[0];
	temp[1] = p1[1];
	temp[2] = p2[0];
	temp[3] = p2[1];
	if (fabs(m) > 0.5)
		bres_vertical(p1, p2, img);
	else
		bres_horizontal(p1, p2, img);
	p1[0] = temp[0];
	p1[1] = temp[1];
	p2[0] = temp[2];
	p2[1] = temp[3];
}
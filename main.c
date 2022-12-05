#include "test.h"
#include <math.h>
#include <stdio.h>

// int	mlx_pixel_put_img(int x, int y, int color, t_data *img)
// {
// 	char *dst;
// 	dst = img->addr + (y*img->size_line + x*(img->bpp/8));
// 	*(int*)dst = color;
// 	return (0);
// }

// void	tracersegment(int p1[2], int p2[2], int color, t_data *img)
// {
// 	float m;
// 	float temp;
// 	int	sens;
// 	int swap[2];

// 	if (p1[0] < p2[0])
// 		sens = 1;
// 	else 
// 		sens = -1;
// 	m = (float)(p2[1] - p1[1])/ fabs(((float)(p2[0] - p1[0])));
// 	temp = p1[1];
// 	while ((int)(temp + 0.5) != p2[1])
// 	{
// 		temp = temp + m * 1;
// 		if(temp - (int)temp > 0.5)
// 			mlx_pixel_put_img(p1[0], (int)(temp + 1), color, img);
// 		else
// 			mlx_pixel_put_img(p1[0], (int)(temp), color, img);
// 		p1[0]+= sens;
// 	}
// }

void ft_gros_pix(int x, int y, int color, t_data *img, int largeur)
{
	int	i;
	int j;

	i = 0;
	j = 0;

	while (j < largeur)
	{
		while (i < largeur)
		{
			mlx_pixel_put_img(i + x, j + y, color, img);
			i++;
		}
		i = 0;
		j++;
	}
	
}

int main()
{
	void *mlx_ptr;
	t_data img;
	void *win_ptr;
	char **line1;
	char **line2;
	int fd;

	fd = open("42.fdf", O_RDONLY);
	if (fd == -1)
		return (0);
	line1 = ft_split(get_next_line(fd), ' ');
	line2 = ft_split(get_next_line(fd), ' ');
	mlx_ptr = mlx_init();
	img.img_ptr = mlx_new_image(mlx_ptr, 1500, 800);
	win_ptr = mlx_new_window(mlx_ptr, 1500, 800, "fenetre");
	img.bpp = 32;
	img.endian = 1;
	img.size_line = 1500*(img.bpp/8);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_line, &img.endian);

	ft_print_ligne(line1, line2, &img);
	line1 = line2;
	line2 = ft_split(get_next_line(fd), ' ');
	ft_print_ligne(line1, line2, &img);
	line1 = line2;
	line2 = ft_split(get_next_line(fd), ' ');
	ft_print_ligne(line1, line2, &img);
	line1 = line2;
	line2 = ft_split(get_next_line(fd), ' ');
	ft_print_ligne(line1, line2, &img);
	line1 = line2;
	line2 = ft_split(get_next_line(fd), ' ');
	ft_print_ligne(line1, line2, &img);
	line1 = line2;
	line2 = ft_split(get_next_line(fd), ' ');
	ft_print_ligne(line1, line2, &img);
	line1 = line2;
	line2 = ft_split(get_next_line(fd), ' ');
	ft_print_ligne(line1, line2, &img);
	line1 = line2;
	line2 = ft_split(get_next_line(fd), ' ');
	ft_print_ligne(line1, line2, &img);
	line1 = line2;
	line2 = ft_split(get_next_line(fd), ' ');
	ft_print_ligne(line1, line2, &img);
	line1 = line2;
	line2 = ft_split(get_next_line(fd), ' ');
	ft_print_ligne(line1, line2, &img);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr, 0, 0);
	mlx_loop(mlx_ptr);

}
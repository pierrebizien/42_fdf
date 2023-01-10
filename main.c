#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>

static void	ft_mlx_put_to_img(t_data *img, int x, int y, int color)
{
	char	*dst;
	unsigned char	*tmp;
	
	dst = img->addr + y * img->l_length + x * img->bpp;
	*(int*)dst = color;

}

int main(int ac, char** av)
{
    t_win	mlx_i;
	t_data	img;
	t_point	p1;
	t_point	p2;

	p1.x = 100;
	p1.y = 100;
	p2.x = 300;
	p2.y = 300;

    mlx_i.mlx_ptr = mlx_init();
	mlx_i.win_ptr = mlx_new_window(mlx_i.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "fdf");
	img.img = mlx_new_image(mlx_i.mlx_ptr, WIN_WIDTH ,WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.l_length, &img.endian);
	ft_mlx_put_to_img(&img, p2.x, p2.y, 0x00ffff);
	tracersegment(p1, p2, &img);
	mlx_put_image_to_window(mlx_i.mlx_ptr, mlx_i.win_ptr, img.img, 0 ,0);
	mlx_loop(mlx_i.mlx_ptr);
}
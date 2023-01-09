#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_mlx_put_to_img(t_data *img, int x, int y, int color)
{
	char	*dst;
	unsigned char	*tmp;
	
	dst = img->addr + y * img->l_length + x * img->bpp;
	*(int*)dst = color;
	tmp = calloc(1, 5);
	*(int*)tmp = color;
	printf("%d\n", tmp[0]);
	printf("%d\n", tmp[1]);
	printf("%d\n", tmp[2]);
	printf("%d\n", tmp[3]);


}

int main(int ac, char** av)
{
    t_win	mlx_i;
	t_data	img;
    
    mlx_i.mlx_ptr = mlx_init();
	mlx_i.win_ptr = mlx_new_window(mlx_i.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "fdf");
	img.img = mlx_new_image(mlx_i.mlx_ptr, WIN_WIDTH ,WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.l_length, &img.endian);
	ft_mlx_put_to_img(&img, 200, 200, 0x00ffff);
	mlx_put_image_to_window(mlx_i.mlx_ptr, mlx_i.win_ptr, img.img, 0 ,0);
	mlx_loop(mlx_i.mlx_ptr);
}
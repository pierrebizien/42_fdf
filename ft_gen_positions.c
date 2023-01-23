/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gen_positions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:12:13 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/23 13:40:45 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_init_first_post(t_data *img)
{
	img->map[0][0].x = -((img->width - 1) * img->view.zoom) / 2;
	img->map[0][0].y = -((img->height - 1) * img->view.zoom) / 2;
	img->offset_x = -img->map[0][0].x + WIN_WIDTH / 2 - \
		(img->width - 1) * img->view.zoom / 2;
	img->offset_y = -img->map[0][0].y + WIN_HEIGHT / 2 - \
		(img->height - 1) * img->view.zoom / 2;
}

static void	ft_one_point(t_data *img)
{
	ft_mlx_pix_img(img->map[0][0].x + img->offset_x , \
		img->map[0][0].y + img->offset_y, 0xFFFFFF, img);
}

int	ft_gen_init_pos(t_data *img)
{
	int		i;
	int		j;

	i = 0;
	ft_init_first_post(img);
	if (img->width <= 1 && img->height <= 1)
		return (ft_one_point(img), 0);
	while (i < img->height)
	{
		j = 1;
		while (j < img->width)
		{
			img->map[i][j].x = j * img->view.zoom + img->map[0][0].x;
			img->map[i][j].y = img->map[i][j - 1].y;
			j++;
		}
		if (++i < img->height)
		{
			img->map[i][0].y = img->view.zoom * (float)i + img->map[0][0].y;
			img->map[i][0].x = img->map[i - 1][0].x;
		}
	}
	return (0);
}

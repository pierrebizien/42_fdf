/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_positions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:12:13 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/18 13:56:19 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



t_point**    ft_gen_init_pos(t_data *img, t_point **map)
{
    int i;
    int j;
    float tempx;
    float tempy;

    i = 0;
	img->map[0][0].x = -((img->width - 1) * img->view.zoom) / 2;
	img->map[0][0].y = -((img->height - 1) * img->view.zoom ) / 2;
    tempy = img->map[0][0].y;
    while (i < img->height)
    {
        tempx = img->map[0][0].x;
        j = 1;
        while (j < img->width)
        {
			tempx += img->view.zoom;
			img->map[i][j].x = j * img->view.zoom + img->map[0][0].x;
            img->map[i][j].y = img->map[i][j - 1].y;
            j++;
        }
        if (++i < img->height)
        {
            tempy += img->view.zoom;
            img->map[i][0].y = img->view.zoom * (float)i + img->map[0][0].y;
			img->map[i][0].x = img->map[i - 1][0].x;
        }
    }
}
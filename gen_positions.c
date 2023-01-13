/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_positions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:12:13 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/13 14:23:17 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



t_point**    ft_generate_position(t_data *img, t_point **map)
{
    int i;
    int j;
    float tempx;
    float tempy;

    i = 0;

	map[0][0].x = WIN_WIDTH / 2 - ((img->width - 1) * img->zoom / 2);
	map[0][0].y = WIN_HEIGHT / 2 - ((img->height - 1) * img->zoom / 2);

    tempy = map[0][0].y;
    while (i < img->height)
    {
        tempx = map[0][0].x;
        j = 1;
        while (j < img->width)
        {
			tempx += img->zoom;
			map[i][j].x += (float)j * img->zoom + map[0][0].x;
            map[i][j].y = map[i][j - 1].y;
            j++;
        }
        i++;
        if (i < img->height)
        {
            tempy += img->zoom;
            map[i][0].y += img->zoom * (float)i + map[0][0].y;
			map[i][0].x = map[i - 1][0].x;
        }
    }
    fprintf(stderr, "0 0 y vaut %f\n", map[0][0].y);
	return (map);
}
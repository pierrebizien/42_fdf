/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_positions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:12:13 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/12 11:29:28 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point**    ft_generate_position(t_data *img, t_point **map)
{
    int i;
    int j;
    int tempx;
    int tempy;

    i = 0;

	map[0][0].x = 0;
	map[0][0].y = 0;

    tempy = map[0][0].y;
    while (i < img->height)
    {
        tempx = map[0][0].x;
        j = 1;
        while (j < img->width)
        {
			tempx += img->zoom;
			map[i][j].x += tempx;
            map[i][j].y = map[i][j - 1].y;
            j++;
        }
        i++;
        if (i < img->height)
        {
            tempy += img->zoom;
            map[i][0].y += tempy;
			map[i][0].x = map[i - 1][0].x;
        }
    }
	return (map);
}
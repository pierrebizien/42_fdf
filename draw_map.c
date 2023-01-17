/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:45:33 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/17 15:36:22 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point    **ft_trace_map(t_point **map, t_data *img)
{
    int i;
    int j;

	i = 0;
	while(i <= img->height - 1)
	{
		j = 0;
		while (j <= img->width - 1)
		{
			// fprintf(stderr, "\nDe map[%d][%d].x = %f \t map[%d][%d].y = %f\n", i, j, map[i][j].x, i, j, map[i][j].y);
			// fprintf(stderr, "\nDe map[%d][%d]", i, j);
			if (j < img->width - 1)
			{
				// fprintf(stderr, "A map[%d][%d].x = %f \t map[%d][%d].y = %f\n", i, j, map[i][j].x, i, j, map[i][j + 1].y);
				// // fprintf(stderr, "A map[%d][%d]", i, j + 1);
				// if ((map[i][j].x >= 0 && map[i][j].x <= WIN_WIDTH && map[i][j].y <= WIN_HEIGHT && map[i][j].y >= 0 ) || ( \
				// map[i][j + 1].x >= 0 && map[i][j + 1].x <= WIN_WIDTH && map[i][j + 1].y <= WIN_HEIGHT && map[i][j + 1].y >= 0 ))
					tracersegment(map[i][j], map[i][j + 1], img);
			}
			if (i < img->height - 1)
			{
				// fprintf(stderr, "A map[%d][%d].x = %f \t map[%d][%d].y = %f\n", i, j, map[i][j].x, i, j, map[i + 1][j].y);
				// fprintf(stderr, "A map[%d][%d]", i + 1, j);
				// if ((map[i][j].x >= 0 && map[i][j].x <= WIN_WIDTH && map[i][j].y <= WIN_HEIGHT && map[i][j].y >= 0 ) || ( \
				// map[i + 1][j].x >= 0 && map[i + 1][j].x <= WIN_WIDTH && map[i + 1][j].y <= WIN_HEIGHT && map[i + 1][j].y >= 0 ))
					tracersegment(map[i][j], map[i + 1][j], img);
			}
			j++;
		}
		i++;
	}
	// fprintf(stderr, "----------------------");

}


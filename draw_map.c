/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:45:33 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/16 17:59:07 by pbizien          ###   ########.fr       */
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
			fprintf(stderr, "De map[%d][%d].x = %f \t map[%d][%d].y = %f\n", i, j, map[i][j].x, i, j, map[i][j].y);
			if (j < img->width - 1)
			{
				fprintf(stderr, "A map[%d][%d].x = %f \t map[%d][%d].y = %f\n", i, j, map[i][j].x, i, j, map[i][j + 1].y);

				tracersegment(map[i][j], map[i][j + 1], img);
			}
			if (i < img->height - 1)
			{
				fprintf(stderr, "A map[%d][%d].x = %f \t map[%d][%d].y = %f\n", i, j, map[i][j].x, i, j, map[i + 1][j].y);
				tracersegment(map[i][j], map[i + 1][j], img);
			}
			j++;
		}
		i++;
	}
	fprintf(stderr, "----------------------");

}


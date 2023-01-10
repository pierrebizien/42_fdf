/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_positions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:12:13 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/10 19:23:31 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_generate_position(t_data *img, t_point **map)
{
    int i;
    int j;

    i = 0;
    while (i < img->height)
    {
        j = 0;
        while (j < img->width)
        {
            map[i][j].x = ;
            map[i][j].y;
            j++;
        }
        
        i++;
    }
    
}
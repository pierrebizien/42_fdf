/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:28:28 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/23 14:14:42 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*rotation et inclinaison en radian (dernier chiffre est degre), ratio
 pour relief*/

void	ft_init_map(t_data *img)
{
	img->view.rot = (3.141593 / 180) * 45;
	img->view.incl = (3.141593 / 180) * 60;
	img->view.relief = img->view.zoom / 35;
	img->offset_x = -img->map[0][0].x + WIN_WIDTH / 2 - \
		(img->width - 1) * img->view.zoom / 2;
	img->offset_y = -img->map[0][0].y + WIN_HEIGHT / 2 - \
		(img->height - 1) * img->view.zoom / 2;
	ft_relief(img);
	ft_rotate(img);
	ft_incline(img);
	img->color_tab[0] = 0xFFFFFF;
	img->color_tab[1] = 0x51F74C;
	img->color_tab[2] = 0xF74C4C;
	img->color_tab[3] = 0x00FBFF;
	img->color_tab[4] = 0xF7EF4C;
	img->color = img->color_tab[0];
}

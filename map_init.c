/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:28:28 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/17 17:01:47 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*rotation et inclinaison en radian (dernier chiffre est degre), ratio
 pour relief*/

void    ft_init_map(t_data  *img)
{
    img->view.rot = (3.141593 / 180) * 20;
    img->view.incl = (3.141593 / 180) * 70;
	img->view.relief = img->view.zoom / 35;
	img->offset_x = -img->map[0][0].x + WIN_WIDTH / 2 - (img->width / 2) * img->view.zoom;
    img->offset_y = -img->map[0][0].y + WIN_HEIGHT / 2 - (img->height / 2) * img->view.zoom;
	ft_relief(img, 1);
	ft_rotate(img, 1);
	ft_incline(img, 1);

}
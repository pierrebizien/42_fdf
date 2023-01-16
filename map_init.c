/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:28:28 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/16 17:05:29 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*rotation et inclinaison en radian (dernier chiffre est degre), ratio
 pour relief*/

void    ft_init_map(t_data  *img)
{
    img->view.rot = (3.141593 / 180) * 20;
    img->view.incl = (3.141593 / 180) * 50;
	img->view.relief = 2.5;
	ft_relief(img, 1);
	ft_rotate(img, 1);
	ft_incline(img, 1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gen_map2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:48:45 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/26 13:49:10 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_strlen_double(char **strstr)
{
	int	i;

	i = 0;
	while (strstr[i])
	{
		i++;
	}
	return (i);
}

void	ft_rogne(char **tmp)
{
	int	i;
	int	j;

	i = 0;
	while (tmp[i])
	{
		j = 0;
		while (tmp[i][j])
		{
			if (tmp[i][j] == ',')
				tmp[i][j] = '\0';
			j++;
		}
		i++;
	}
}

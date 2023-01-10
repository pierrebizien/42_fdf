/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:45:47 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/10 18:12:59 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_define_width(char *str)
{
	int	i;
	int	count;
	
	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	return(count);
}

//Tourne une fois gnl et remet a 0 avec un fd
//definit height et with

static int		ft_define(int *fd, t_data *img)
{
    int		i;
	int		j;
	char	*tmp;

	i = 0;
	tmp = get_next_line(*fd);
	// printf("tmp vaut %d\n ", ft_strlen(tmp));
	img->width = ft_define_width(tmp);
    while (tmp)
    {
		free(tmp);
        tmp = get_next_line(*fd);
		i++;
    }
	if (tmp)
		free(tmp);
	j = open(MAP, O_RDONLY);
	close(*fd);
	*fd = j;
	img->height = i;
	return (i);
}

t_point		**ft_generate_map(int *fd, t_data *img)
{
    t_point **output;
	
	ft_define(fd, img);
	output = malloc(sizeof(t_point *) * img->height);
	if (!output)
		return (NULL);
	output[0] = 
}
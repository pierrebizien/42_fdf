/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:45:47 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/18 16:22:24 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_define_width(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] != ' ')
			count++;
		i++;
	}
	return (count + 1);
}

//Tourne une fois gnl et remet a 0 avec un fd
//definit height width et zoom initial

static int	ft_define(int *fd, t_data *img)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	tmp = get_next_line(*fd);
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
	img->view.zoom = (WIN_WIDTH) / (img->width + 1);
	return (i);
}

void	ft_fill_line(char **tmp, t_point *line, t_data *img)
{
	int	i;

	i = 0;
	while (i < img->width)
	{
		line[i].h = ft_atoi(tmp[i]);
		i++;
	}
}

void	ft_free_double_c(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

t_point	**ft_generate_map(int *fd, t_data *img)
{
	t_point	**output;
	char	**tmp;
	char	*tmp_gnl;
	int		i;

	i = 0;
	if (ft_define(fd, img) == -1)
		return (NULL);
	output = ft_calloc(sizeof(t_point *), (img->height));
	if (!output)
		return (NULL);
	while (i < img->height)
	{
		output[i] = ft_calloc(sizeof(t_point), (img->width));
		if (!output[i])
			return (NULL);
		tmp_gnl = get_next_line(*fd);
		tmp = ft_split(tmp_gnl, ' ');
		free(tmp_gnl);
		ft_fill_line(tmp, output[i], img);
		ft_free_double_c(tmp);
		i++;
	}
	return (output);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gen_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:45:47 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/26 13:50:21 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_define_width(char *str)
{
	int	i;
	int	count;

	i = 0;
	if (!str)
		return (0);
	if (str[0] != ' ')
		count = 1;
	else
		count = 0;
	while (str[i])
	{
		if ((str[i] == ' ') && (str[i + 1] != ' ') && \
			(str[i + 1] != '\0') && (str[i + 1] != '\n'))
			count++;
		i++;
	}
	return (count);
}

//Tourne une fois gnl et remet a 0 avec un fd
//definit height width et zoom initial

static int	ft_define(int *fd, t_data *img, char *av1)
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
	j = open(av1, O_RDONLY);
	close(*fd);
	*fd = j;
	img->height = i;
	img->view.zoom = (WIN_WIDTH) / (img->width + 1);
	return (i);
}

int	ft_fill_line(char **tmp, t_point *line, t_data *img)
{
	int	i;

	i = 0;
	ft_rogne(tmp);
	if (ft_strlen_double(tmp) != img->width)
	{
		return (line = NULL, -1);
	}
	while (i < img->width)
	{
		line[i].h = ft_atoi(tmp[i]);
		i++;
	}
	return (0);
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

t_point	**ft_generate_map(int *fd, t_data *img, char *av1)
{
	t_point	**output;
	char	**tmp;
	char	*tmp_gnl;
	int		i;

	i = 0;
	if (ft_define(fd, img, av1) == -1)
		return (NULL);
	output = ft_calloc(sizeof(t_point *), (img->height));
	if (!output)
		return (NULL);
	while (i < img->height)
	{
		output[i] = ft_calloc(sizeof(t_point), (img->width));
		if (!output[i])
			return (ft_free_double_t(img), NULL);
		tmp_gnl = get_next_line(*fd);
		tmp = ft_split(tmp_gnl, ' ');
		free(tmp_gnl);
		if (ft_fill_line(tmp, output[i], img) == -1)
			return (ft_free_double_c(tmp), ft_free_double_t2(output, i), NULL);
		ft_free_double_c(tmp);
		i++;
	}
	return (output);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierrebizien <pierrebizien@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:08:04 by pbizien           #+#    #+#             */
/*   Updated: 2022/12/04 18:19:29 by pierrebizie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  The  strdup()  function returns a pointer to a new string which is a 
//  duplicate of the string s.  Memory for the new string is ob‐
//  tained with malloc(3), and can be freed with free(3).

#include "libft.h"
#include <stdio.h>

char	*ft_strdup(const char *s)
{
	char	*str_dup;

	str_dup = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!str_dup)
		return (NULL);
	ft_memcpy_lft(str_dup, s, (int)ft_strlen(s));
	return (str_dup);
}

/*
int	main()
{
	char str[] = "Hello my maaaan";
	char *str2;

	str2 = ft_strdup(str);
	printf("%s", str2);
}*/
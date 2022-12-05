/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_lft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierrebizien <pierrebizien@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:02:52 by pbizien           #+#    #+#             */
/*   Updated: 2022/12/04 18:18:22 by pierrebizie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// La fonction bzero() met à 0 (octets contenant « \0 ») les n premiers octets 
// du bloc pointé par s.

#include "libft.h"
#include <stdio.h>

void	ft_bzero_lft(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}

/*
int	main()
{
	char str[] = "Hello je m'appelle Pierre";

	ft_bzero(str+5, 6);
	int	i;

	i = 0;

	while (i < 25)
	{
		printf("%c", str[i]);
		i++;
	}
	
}
*/
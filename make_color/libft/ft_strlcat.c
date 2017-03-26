/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:39:06 by egaragul          #+#    #+#             */
/*   Updated: 2016/12/07 12:53:14 by egaragul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t		i;
	size_t		j;
	size_t		a;

	a = 0;
	i = ft_strlen(dest);
	j = ft_strlen(src);
	if (n >= i)
	{
		while (src[a] && i < n - 1)
			dest[i++] = src[a++];
		dest[i] = '\0';
		return ((unsigned long)(j - a) + (unsigned long)i);
	}
	return ((unsigned long)j + (unsigned long)n);
}

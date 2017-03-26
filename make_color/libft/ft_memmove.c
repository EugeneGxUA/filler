/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:59:18 by egaragul          #+#    #+#             */
/*   Updated: 2016/12/06 11:21:41 by egaragul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;

	if (dest >= src)
	{
		i = len;
		while (i > 0)
		{
			i--;
			*((char*)dest + i) = *((char*)src + i);
		}
	}
	else
	{
		i = 0;
		while (len > i)
		{
			*((char*)dest + i) = *((char*)src + i);
			i++;
		}
	}
	return (dest);
}

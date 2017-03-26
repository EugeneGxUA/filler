/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:02:14 by egaragul          #+#    #+#             */
/*   Updated: 2016/12/05 17:48:59 by egaragul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t		i;

	i = 0;
	while (len != 0 && src[i])
	{
		dest[i] = src[i];
		i++;
		len--;
	}
	while (len != 0)
	{
		dest[i++] = '\0';
		len--;
	}
	return (dest);
}

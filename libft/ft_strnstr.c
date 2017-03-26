/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:32:40 by egaragul          #+#    #+#             */
/*   Updated: 2016/12/07 12:58:22 by egaragul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t n)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = 0;
	k = ft_strlen(small);
	if (k == 0)
		return ((char*)big);
	while (big[i] && i < n)
	{
		while (big[i + j] == small[j] && small[j] && (i + j) < n)
		{
			if (j == k - 1)
				return ((char*)big + i);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

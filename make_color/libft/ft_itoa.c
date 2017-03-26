/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:10:51 by egaragul          #+#    #+#             */
/*   Updated: 2016/12/06 15:46:49 by egaragul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_len(long long n)
{
	long long	x10;
	long long	x;

	x10 = 1;
	x = 1;
	while (x10 * 10 < n)
	{
		x10 = x10 * 10;
		x++;
	}
	return (x);
}

static int	k_what(int n)
{
	size_t	k;

	k = 0;
	if (n < 0)
		k = 1;
	return (k);
}

static char	*ft_rev(char *s, int i)
{
	int		j;
	char	c;

	j = 0;
	i--;
	while (i > j)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		i--;
		j++;
	}
	return (s);
}

char		*ft_itoa(int n)
{
	size_t		i;
	size_t		k;
	size_t		x10;
	long long	t;
	char		*str;

	i = 0;
	k = k_what(n);
	t = n;
	if (k == 1)
		t = -t;
	x10 = ft_len(t);
	str = (char*)malloc(sizeof(char) * (x10 + k + 1));
	if (str == 0)
		return (NULL);
	while (i < x10)
	{
		str[i++] = (t % 10) + '0';
		t = t / 10;
	}
	if (k == 1)
		str[i++] = '-';
	str[i] = '\0';
	ft_rev(str, i);
	return (str);
}

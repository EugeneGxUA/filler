/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:40:13 by egaragul          #+#    #+#             */
/*   Updated: 2016/12/08 17:04:18 by egaragul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_checkspace(char const *s, int i, int j)
{
	while (s[i])
		i++;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j++;
	while (s[i - 1] == ' ' || s[i - 1] == '\n' || s[i - 1] == '\t')
		i--;
	if (i > j)
		return (i - j);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*str;

	if (s == 0)
		return (NULL);
	i = 0;
	j = 0;
	str = (char*)malloc(sizeof(char) * ft_checkspace(s, 0, 0) + 1);
	if (str == 0)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[i] && j < ft_checkspace(s, 0, 0))
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}

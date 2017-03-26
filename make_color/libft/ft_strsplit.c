/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:21:11 by egaragul          #+#    #+#             */
/*   Updated: 2016/12/08 17:31:50 by egaragul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_word_len(char const *s, char c, int index)
{
	int		i;

	i = 0;
	while (s[index] != c && s[index])
	{
		index++;
		i++;
	}
	return (i);
}

static char	**ft_hard(char **str, char const *s, char c)
{
	int		i;
	int		j;
	int		argc;

	i = 0;
	j = 0;
	argc = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		str[argc] = (char*)malloc(sizeof(char) * ft_word_len(s, c, i) + 1);
		if (!str)
			return (NULL);
		if (s[i] != c && s[i])
		{
			while (s[i] != c && s[i])
				str[argc][j++] = s[i++];
			str[argc++][j] = '\0';
		}
		j = 0;
	}
	str[argc] = NULL;
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = (char**)malloc(sizeof(char*) * (ft_strdelim(s, c) + 1));
	if (!str)
		return (NULL);
	str = ft_hard(str, s, c);
	return (str);
}

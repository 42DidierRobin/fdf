/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:11:37 by rdidier           #+#    #+#             */
/*   Updated: 2015/11/30 15:36:16 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int static		ft_count_it(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] && (s[i] == c))
		i++;
	while (s[i])
	{
		j++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (j);
}

char			**ft_strsplit(char const *s, char c)
{
	int			i;
	int			j;
	int			place;
	char		**res;

	if (!s)
		return (NULL);
	i = 0;
	place = 0;
	res = (char**)malloc(sizeof(char*) * ft_count_it(s, c) + 1);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		j = 0;
		while (s[i + j] && s[i + j] != c)
			j++;
		res[place] = ft_strsub((const char*)s, (unsigned int)i, (size_t)j);
		i = i + j;
		while (s[i] && s[i] == c)
			i++;
		place++;
	}
	res[place] = 0;
	return (res);
}

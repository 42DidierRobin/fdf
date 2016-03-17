/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:03:10 by rdidier           #+#    #+#             */
/*   Updated: 2015/11/30 15:36:54 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int static			ft_count_it(char const *s)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
	{
		i++;
		res++;
	}
	i = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		res++;
		i--;
	}
	return (ft_strlen(s) - res);
}

char				*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		len;
	char	*res;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_count_it(s);
	if (len > 0)
		res = ft_strnew(len);
	else
		res = ft_strnew(0);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i++;
	}
	while (j < len)
	{
		res[j] = s[i];
		i++;
		j++;
	}
	return (res);
}

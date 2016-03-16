/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:34:44 by rdidier           #+#    #+#             */
/*   Updated: 2015/12/14 21:52:28 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!s2[i])
		return ((char*)s1);
	while (s1[i])
	{
		j = 0;
		while (s1[i + j] == s2[j])
		{
			j++;
			if (!s2[j])
				return ((char*)(s1 + i));
		}
		i++;
	}
	return (0);
}

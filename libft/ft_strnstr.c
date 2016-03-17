/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:34:44 by rdidier           #+#    #+#             */
/*   Updated: 2015/12/14 21:53:24 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		j;
	int		length;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	length = ft_strlen(s2);
	if (length == 0)
		return ((char*)s1);
	while ((s1[i] != '\0') && (i < n))
	{
		j = 0;
		while ((s1[i + j] == s2[j]) && ((i + j) < n))
		{
			if (j == (length - 1))
				return ((char*)(s1 + i));
			j++;
		}
		i++;
	}
	return (0);
}

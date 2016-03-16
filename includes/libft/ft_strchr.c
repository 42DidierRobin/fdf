/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:03:40 by rdidier           #+#    #+#             */
/*   Updated: 2015/12/14 21:52:13 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	int i;

	if (!s)
		return (NULL);
	if (c == 0)
		return ((char*)(s + ft_strlen(s)));
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char*)(s + i));
		i++;
	}
	return (0);
}

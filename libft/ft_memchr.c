/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:11:57 by rdidier           #+#    #+#             */
/*   Updated: 2015/12/14 21:59:04 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int			i;
	const char	*s2;

	if (!s)
		return (NULL);
	s2 = s;
	i = 0;
	while (n - i)
	{
		if (s2[i] == (char)c)
			return ((void*)(s + i));
		i++;
	}
	return (NULL);
}

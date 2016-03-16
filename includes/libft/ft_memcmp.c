/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:34:29 by rdidier           #+#    #+#             */
/*   Updated: 2015/12/14 22:02:44 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	unsigned char	*s1b;
	unsigned char	*s2b;

	i = 0;
	s1b = (unsigned char*)s1;
	s2b = (unsigned char*)s2;
	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (-s2b[0]);
	if (!s2)
		return (s1b[0]);
	while (n - i)
	{
		if (s1b[i] != s2b[i])
			return (s1b[i] - s2b[i]);
		i++;
	}
	return (0);
}

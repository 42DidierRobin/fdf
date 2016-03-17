/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:39:30 by rdidier           #+#    #+#             */
/*   Updated: 2015/12/14 21:45:11 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int				i;
	char			*dst2;
	const char		*src2;

	if (!dst || !src)
		return (NULL);
	dst2 = dst;
	src2 = src;
	i = 0;
	while (n - i)
	{
		if (*(src2 + i) == ((char)c))
			return (dst2 + i + 1);
		*(dst2 + i) = *(src2 + i);
		i++;
	}
	return (0);
}

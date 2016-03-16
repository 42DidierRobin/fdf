/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:00:26 by rdidier           #+#    #+#             */
/*   Updated: 2015/12/14 21:44:58 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	int			i;
	char		*dst2;
	const char	*src2;

	if (!dst || !src)
		return (NULL);
	dst2 = dst;
	src2 = src;
	i = 0;
	while (n - i)
	{
		*(dst2 + i) = *(src2 + i);
		i++;
	}
	return (dst);
}

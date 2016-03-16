/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:18:05 by rdidier           #+#    #+#             */
/*   Updated: 2015/12/14 21:59:45 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	char	*s1;
	char	*src2;

	if (!dst || !src)
		return (NULL);
	s1 = (char*)src;
	i = 0;
	src2 = (char*)malloc(sizeof(char) * len);
	while (len - i)
	{
		src2[i] = s1[i];
		i++;
	}
	s1 = ft_memcpy(dst, src2, len);
	free(src2);
	return (s1);
}

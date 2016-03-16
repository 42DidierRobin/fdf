/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:59:16 by rdidier           #+#    #+#             */
/*   Updated: 2015/12/14 21:52:02 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t n)
{
	int src_len;
	int dst_len;
	int i;

	if (!dst || !src)
		return (0);
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	i = 0;
	if ((int)n < dst_len)
		return (src_len + n);
	while ((dst_len + i + 1) < (int)n && src[i])
	{
		dst[i + dst_len] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:21:28 by rdidier           #+#    #+#             */
/*   Updated: 2015/12/14 21:44:28 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *p, int c, size_t n)
{
	int				i;
	unsigned char	*dst;

	if (!p)
		return (NULL);
	i = 0;
	dst = p;
	while (n - i)
	{
		*(dst + i) = (unsigned char)c;
		i++;
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:53:17 by rdidier           #+#    #+#             */
/*   Updated: 2016/01/14 15:36:08 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	int			i;
	int			length;
	char		*result;

	if (!s1)
		return (NULL);
	i = 0;
	length = ft_strlen(s1);
	result = ft_strnew(length);
	if (!result)
		return (0);
	while (length - i)
	{
		result[i] = s1[i];
		i++;
	}
	return (result);
}

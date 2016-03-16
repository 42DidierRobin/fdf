/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:12:29 by rdidier           #+#    #+#             */
/*   Updated: 2015/12/14 22:09:29 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	length;
	char	*res;

	if (str && f)
	{
		i = 0;
		length = ft_strlen(str);
		res = ft_strnew(length);
		while (str[i])
		{
			res[i] = f(i, str[i]);
			i++;
		}
		return (res);
	}
	return (NULL);
}

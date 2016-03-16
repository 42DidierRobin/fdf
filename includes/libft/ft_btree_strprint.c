/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_strprint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 10:00:51 by rdidier           #+#    #+#             */
/*   Updated: 2015/12/05 10:29:03 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_btree_strprint(t_btree *element)
{
	char	*str;

	str = (char*)element->content;
	if (!element)
		ft_putstr("null");
	else
	{
		ft_putchar('(');
		ft_putstr(str);
		ft_putstr(") -> ");
	}
	return (element);
}

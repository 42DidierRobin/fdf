/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 17:12:25 by rdidier           #+#    #+#             */
/*   Updated: 2015/12/14 22:09:59 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void static	ft_lstdel_rec(t_list **alst, void (*del)(void *, size_t))
{
	if ((*alst)->next)
		ft_lstdel(&(*alst)->next, del);
	ft_lstdelone(alst, del);
}

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (alst && del)
	{
		if (*alst && (*alst)->next)
			ft_lstdel_rec(alst, del);
		else if (*alst)
			ft_lstdelone(alst, del);
	}
}

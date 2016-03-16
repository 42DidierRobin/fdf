/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 17:07:41 by rdidier           #+#    #+#             */
/*   Updated: 2015/12/14 22:09:48 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*l;

	if (*alst && alst && del)
	{
		l = *alst;
		(del)(l->content, l->content_size);
		free(l);
		*alst = NULL;
	}
}

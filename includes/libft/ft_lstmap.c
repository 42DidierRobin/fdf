/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 17:19:44 by rdidier           #+#    #+#             */
/*   Updated: 2015/12/14 22:11:00 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*first;
	t_list		*new;
	t_list		*temp;
	t_list		*last;

	if (!lst || !f)
		return (NULL);
	new = f(lst);
	first = ft_lstnew(new->content, new->content_size);
	last = first;
	while (lst->next)
	{
		lst = lst->next;
		new = f(lst);
		temp = ft_lstnew(new->content, new->content_size);
		last->next = temp;
		last = temp;
	}
	return (first);
}

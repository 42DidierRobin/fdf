/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 09:13:42 by rdidier           #+#    #+#             */
/*   Updated: 2015/12/05 10:34:55 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree		*ft_btree_new(void *content, size_t content_size)
{
	t_btree	*it;

	it = (t_btree*)malloc(sizeof(struct s_list));
	if (!it)
		return (NULL);
	if (!content || (content_size == 0))
	{
		it->content = NULL;
		it->content_size = 0;
		it->right = NULL;
		it->left = NULL;
	}
	else
	{
		it->content = ft_memalloc(content_size);
		ft_memcpy(it->content, content, content_size);
		it->content_size = content_size;
		it->right = NULL;
		it->left = NULL;
	}
	return (it);
}

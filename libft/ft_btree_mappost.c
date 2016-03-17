/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_mappost.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 09:23:51 by rdidier           #+#    #+#             */
/*   Updated: 2015/12/05 10:34:15 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_btree_mappost(t_btree *root, void *(*f)(t_btree *elem))
{
	if (root)
	{
		ft_btree_mappost(root->left, f);
		ft_btree_mappost(root->right, f);
		f(root);
	}
}

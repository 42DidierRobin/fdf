/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_mapinf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 09:23:51 by rdidier           #+#    #+#             */
/*   Updated: 2015/12/14 21:57:39 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_btree_mapinf(t_btree *root, void *(*f)(t_btree *elem))
{
	if (root)
	{
		ft_btree_mapinf(root->left, f);
		f(root);
		ft_btree_mapinf(root->right, f);
	}
}

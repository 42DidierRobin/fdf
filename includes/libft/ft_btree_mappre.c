/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_mappre.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 09:23:51 by rdidier           #+#    #+#             */
/*   Updated: 2015/12/05 10:36:12 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_btree_mappre(t_btree *root, void *(*f)(t_btree *elem))
{
	if (root)
	{
		f(root);
		ft_btree_mappre(root->left, f);
		ft_btree_mappre(root->right, f);
	}
}

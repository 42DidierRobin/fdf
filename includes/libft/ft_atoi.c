/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:24:37 by rdidier           #+#    #+#             */
/*   Updated: 2015/12/14 21:55:48 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_atoi_help(const char *s)
{
	int		i;

	i = 0;
	while (s[i] > 0 && s[i] <= 32)
		i++;
	if (s[i] || ft_isdigit(s[i]) || s[i] == '-' || s[i] == '+')
		return (i);
	else
		return (-1);
}

int				ft_atoi(const char *s)
{
	int		i;
	int		neg;
	int		result;

	i = ft_atoi_help(s);
	if (i < 0 || !s)
		return (0);
	result = 0;
	if (s[i] == '-')
	{
		neg = 1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (ft_isdigit(s[i]))
	{
		result = result * 10 + (s[i] - 48);
		i++;
	}
	if (neg)
		return (-result);
	return (result);
}

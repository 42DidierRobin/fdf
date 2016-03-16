/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 09:51:07 by rdidier           #+#    #+#             */
/*   Updated: 2015/12/14 21:43:15 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void static		ft_putnbr_safe(unsigned int nbr, int fd)
{
	if (nbr < 10)
		ft_putchar_fd(nbr + '0', fd);
	else
	{
		ft_putnbr_safe(nbr / 10, fd);
		ft_putnbr_safe(nbr % 10, fd);
	}
}

void			ft_putnbr_fd(int nbr, int fd)
{
	unsigned int temp;

	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		temp = (unsigned int)(nbr * (-1));
	}
	else
		temp = (unsigned int)nbr;
	ft_putnbr_safe(temp, fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 15:29:42 by rzero             #+#    #+#             */
/*   Updated: 2018/12/12 15:29:45 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char digit;

	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n == -2147483648)
		ft_putstr_fd("2147483648", fd);
	else
	{
		if (n >= 10)
			ft_putnbr_fd((n / 10), fd);
		digit = (n % 10) + '0';
		write(fd, &digit, 1);
	}
}

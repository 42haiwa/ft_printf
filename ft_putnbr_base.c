/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <cjouenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 22:59:21 by cjouenne          #+#    #+#             */
/*   Updated: 2023/08/25 12:59:10 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	count_u_digits(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		++len;
	while (nb > 0)
	{
		nb /= 10;
		++len;
	}
	return (len);
}

int	count_digits(int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
		len += 10;
	if (nb <= 0)
	{
		nb *= -1;
		++len;
	}
	while (nb > 0)
	{
		nb /= 10;
		++len;
	}
	return (len);
}

int	count_hex_digits(unsigned long nb)
{
	int	len;

	len = 0;
	if (nb == (unsigned long)(-9223372036854775807L -1L))
		return (16);
	if (nb == 9223372036854775807L)
		return (8);
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 16;
		++len;
	}
	return (len);
}

void	ft_putnbr_base(unsigned long nb, char *base)
{
	if (!base)
		return ;
	if (nb == 9223372036854775807L)
	{
		ft_putstr_fd("ffffffff", 1);
		return ;
	}
	if (nb == (unsigned long)(-9223372036854775807L -1L))
	{
		ft_putstr_fd("0", 1);
		return ;
	}
	if ((size_t) nb < ft_strlen(base))
		ft_putchar_fd(base[nb], 1);
	if ((size_t) nb >= ft_strlen(base))
	{
		ft_putnbr_base(nb / ft_strlen(base), base);
		ft_putnbr_base(nb % ft_strlen(base), base);
	}
}

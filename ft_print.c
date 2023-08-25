/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <cjouenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:55:06 by cjouenne          #+#    #+#             */
/*   Updated: 2023/08/25 12:59:35 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char const c)
{
	ft_putchar_fd((char)c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd((char *) str, 1);
	return ((int)ft_strlen(str));
}

int	ft_print_ptr(void *ptr)
{
	unsigned long	l_ptr;

	l_ptr = (unsigned long) ptr;
	if (l_ptr == (unsigned long)(-9223372036854775807L -1L))
	{
		ft_putstr_fd("0x8000000000000000", 1);
		return (18);
	}
	if (l_ptr == (unsigned long)9223372036854775807L)
	{
		ft_putstr_fd("0x7fffffffffffffff", 1);
		return (18);
	}
	if (l_ptr == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	ft_putnbr_base((unsigned long)l_ptr, "0123456789abcdef");
	return (count_hex_digits((unsigned long)l_ptr) + 2);
}

int	ft_print_nbr(int nb)
{
	ft_putnbr_fd(nb, 1);
	return (count_digits(nb));
}

int	ft_print_u_nbr(unsigned int nb)
{
	if (nb < 10)
		ft_putchar_fd('0' + nb, 1);
	if (nb >= 10)
	{
		ft_print_u_nbr(nb / 10);
		ft_print_u_nbr(nb % 10);
	}
	return (count_u_digits(nb));
}

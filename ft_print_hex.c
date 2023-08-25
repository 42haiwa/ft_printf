/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <cjouenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 01:19:18 by cjouenne          #+#    #+#             */
/*   Updated: 2023/08/25 01:35:05 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	s_count_hex_digits(unsigned int nb)
{
	int	len;

	len = 0;
	if (!nb)
		return (1);
	while (nb)
	{
		len++;
		nb /= 16;
	}
	return (len);
}

static void	ft_putnbr_hex(unsigned int nb, int is_min)
{
	if (nb >= 16)
	{
		ft_putnbr_hex(nb / 16, is_min);
		ft_putnbr_hex(nb % 16, is_min);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd('0' + nb, 1);
		else
		{
			if (is_min)
				ft_putchar_fd('a' + nb - 10, 1);
			else
				ft_putchar_fd('A' + nb - 10, 1);
		}
	}
}

int	ft_print_hex(unsigned int nb, int is_min)
{
	if (nb == 0)
		ft_putchar_fd('0', 1);
	else
		ft_putnbr_hex(nb, is_min);
	return (s_count_hex_digits(nb));
}

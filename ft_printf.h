/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <cjouenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 22:19:00 by cjouenne          #+#    #+#             */
/*   Updated: 2023/08/25 12:56:47 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# include "libft.h"

// ft_putnbr_base.c
void	ft_putnbr_base(unsigned long nb, char *base);
int		count_hex_digits(unsigned long nb);
int		count_digits(int nb);
int		count_u_digits(unsigned int nb);

// ft_print_hex.c
int		ft_print_hex(unsigned int nb, int is_min);

// ft_print.c
int		ft_print_char(char const c);
int		ft_print_str(char *str);
int		ft_print_ptr(void *ptr);
int		ft_print_nbr(int nb);
int		ft_print_u_nbr(unsigned int nb);

// ft_printf.c
int		ft_printf(char const *format, ...);
#endif
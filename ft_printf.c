/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <cjouenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 22:18:48 by cjouenne          #+#    #+#             */
/*   Updated: 2023/08/25 13:05:01 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_percent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}

static void	ft_manage_format(char c, va_list *params, int *len)
{
	if (c == 'c')
		*len += ft_print_char((char)va_arg(*params, int));
	if (c == 's')
		*len += ft_print_str(va_arg(*params, char *));
	if (c == 'p')
		*len += ft_print_ptr(va_arg(*params, void *));
	if (c == 'd')
		*len += ft_print_nbr(va_arg(*params, int));
	if (c == 'i')
		*len += ft_print_nbr(va_arg(*params, int));
	if (c == 'u')
		*len += ft_print_u_nbr(va_arg(*params, unsigned int));
	if (c == 'x')
		*len += ft_print_hex(va_arg(*params, unsigned int), 1);
	if (c == 'X')
		*len += ft_print_hex(va_arg(*params, unsigned int), 0);
	if (c == '%')
		*len += ft_print_percent();
}

static int	ft_parse_format(char const *format, va_list *params)
{
	size_t	i;
	int		len;

	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			ft_manage_format(format[i + 1], params, &len);
			i += 2;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			++i;
			len++;
		}
	}
	return (len);
}

int	ft_printf(char const *format, ...)
{
	va_list	params;
	int		len;

	va_start(params, format);
	len = ft_parse_format(format, &params);
	va_end(params);
	return (len);
}

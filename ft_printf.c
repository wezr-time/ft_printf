/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoubtas <ymoubtas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 06:10:06 by ymoubtas          #+#    #+#             */
/*   Updated: 2026/10/31 10:24:32 by ymoubtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conversion(va_list ap, char data_type)
{
	if (data_type == 'd' || data_type == 'i')
		return (ft_putnbr_base(va_arg(ap, int), "0123456789", 10));
	if (data_type == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (data_type == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (data_type == 'x')
		return (ft_print_hex(va_arg(ap, unsigned int), data_type));
	if (data_type == 'X')
		return (ft_print_hex(va_arg(ap, unsigned int), data_type));
	if (data_type == 'p')
		return (ft_print_address(va_arg(ap, unsigned long)));
	if (data_type == '%')
		return (ft_putchar('%'));
	if (data_type == 'u')
		return (ft_putnbr_base(va_arg(ap, unsigned int), "0123456789", 10));
	return (0);
}

static int	print_format(const char *format, va_list ap)
{
	int	count;
	int	printed;
	int	i;

	count = 0;
	i = 0;
	printed = 0;
	while (format[i])
	{
		if (format[i] == '%' && !format[i + 1])
			return (-1);
		if (format[i] != '%')
			count += ft_putchar(format[i]);
		else
		{
			i++;
			printed = ft_conversion(ap, format[i]);
			if (printed == 0)
				count += ft_putchar(format[i - 1]);
			else if (printed != -1)
				count += printed;
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	count;

	if (!format || write(1, 0, 0) == -1)
		return (-1);
	count = 0;
	va_start(ap, format);
	count += print_format(format, ap);
	va_end(ap);
	return (count);
}

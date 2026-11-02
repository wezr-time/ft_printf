/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoubtas <ymoubtas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 14:10:48 by ymoubtas          #+#    #+#             */
/*   Updated: 2026/11/02 14:10:49 by ymoubtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conversion(va_list ap, char data_type)
{
	if (data_type == 'd' || data_type == 'i')
		return (ft_printnbr_base(va_arg(ap, int), "0123456789"));
	if (data_type == 'u')
		return (ft_printnbr_base(va_arg(ap, unsigned int), "0123456789"));
	if (data_type == 'x')
		return (ft_printnbr_base(va_arg(ap, unsigned int), "0123456789abcdef"));
	if (data_type == 'X')
		return (ft_printnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	if (data_type == 'c')
		return (ft_printchar(va_arg(ap, int)));
	if (data_type == 's')
		return (ft_printstr(va_arg(ap, char *)));
	if (data_type == 'p')
		return (ft_printaddress(va_arg(ap, uintptr_t)));
	if (data_type == '%')
		return (ft_printchar('%'));
	if (ft_printchar('%') < 0 || ft_printchar(data_type) < 0)
		return (-1);
	return (2);
}

static int	ft_process(const char **f, va_list ap)
{
	int		written;
	int		count;

	count = 0;
	while (**f)
	{
		if (**f == '%' && *(*f + 1) == '\0')
			return (-1);
		if (**f == '%')
			written = ft_conversion(ap, *(++(*f)));
		else
			written = ft_printchar(**f);
		if (written < 0)
			return (-1);
		count += written;
		(*f)++;
	}
	return (count);
}

int	ft_printf(const char *f, ...)
{
	va_list	ap;
	int		count;

	if (!f && write(1, 0, 0) < 0)
		return (-1);
	va_start(ap, f);
	count = ft_process(&f, ap);
	va_end(ap);
	return (count);
}

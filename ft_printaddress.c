/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoubtas <ymoubtas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 14:10:23 by ymoubtas          #+#    #+#             */
/*   Updated: 2026/11/02 14:10:27 by ymoubtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print(uintptr_t nbr, const char *src_base)
{
	int	written;
	int	count;

	count = 0;
	if (nbr >= 16)
	{
		written = ft_print(nbr / 16, src_base);
		if (written < 0)
			return (-1);
		count += written;
	}
	written = ft_printchar(src_base[nbr % 16]);
	if (written < 0)
		return (-1);
	count += written;
	return (count);
}

int	ft_printaddress(uintptr_t p)
{
	int	count;
	int	written;

	written = 0;
	if (p == 0)
		return (ft_printstr("(nil)"));
	if (ft_printstr("0x") < 0)
		return (-1);
	count = 2;
	written = ft_print(p, "0123456789abcdef");
	if (written < 0)
		return (-1);
	count += written;
	return (count);
}

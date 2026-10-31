/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoubtas <ymoubtas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 06:14:49 by ymoubtas          #+#    #+#             */
/*   Updated: 2026/10/30 06:58:56 by ymoubtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print(unsigned long nbr, char *src_base)
{
	int	count;

	count = 0;
	if (nbr < 16)
		return (ft_putchar(src_base[nbr]));
	count += ft_print(nbr / 16, src_base);
	count += ft_print(nbr % 16, src_base);
	return (count);
}

int	ft_print_address(unsigned long nbr)
{
	int	count;

	if (nbr == 0)
		return (ft_putstr("(nil)"));
	count = 0;
	count += ft_putstr("0x");
	count += ft_print(nbr, "0123456789abcdef");
	return (count);
}

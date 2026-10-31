/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoubtas <ymoubtas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 06:11:27 by ymoubtas          #+#    #+#             */
/*   Updated: 2026/10/30 06:44:39 by ymoubtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(long nbr, const char *src_base, const int base)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr < base)
		count += ft_putchar(src_base[nbr]);
	else
	{
		count += ft_putnbr_base(nbr / base, src_base, base);
		count += ft_putnbr_base(nbr % base, src_base, base);
	}
	return (count);
}

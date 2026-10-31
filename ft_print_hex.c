/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoubtas <ymoubtas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 06:14:26 by ymoubtas          #+#    #+#             */
/*   Updated: 2026/10/30 06:30:28 by ymoubtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(long nbr, char data_type)
{
	char	*src_base;

	src_base = "0123456789ABCDEF";
	if (data_type == 'x')
		src_base = "0123456789abcdef";
	return (ft_putnbr_base(nbr, src_base, 16));
}

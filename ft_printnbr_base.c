/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoubtas <ymoubtas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 14:11:02 by ymoubtas          #+#    #+#             */
/*   Updated: 2026/11/02 14:11:03 by ymoubtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_printnbr_base(long n, char *srcbase)
{
	int	count;
	int	written;
	int	base;

	count = 0;
	written = 0;
	base = ft_len(srcbase);
	if (n < 0)
	{
		if (ft_printchar('-') < 0)
			return (-1);
		count++;
		n = -n;
	}
	if (n >= base)
	{
		written = ft_printnbr_base(n / base, srcbase);
		if (written < 0)
			return (-1);
		count += written;
	}
	written = ft_printchar(srcbase[n % base]);
	if (written < 0)
		return (-1);
	return (count + written);
}

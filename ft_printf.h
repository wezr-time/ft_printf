/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoubtas <ymoubtas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 14:10:56 by ymoubtas          #+#    #+#             */
/*   Updated: 2026/11/02 14:10:57 by ymoubtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int	ft_printf(const char *f, ...);
int	ft_printchar(int c);
int	ft_printnbr_base(long n, char *srcbase);
int	ft_printstr(char *s);
int	ft_printaddress(uintptr_t p);

#endif
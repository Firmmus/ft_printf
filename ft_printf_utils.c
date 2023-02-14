/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarcon <falarcon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 03:51:04 by falarcon          #+#    #+#             */
/*   Updated: 2023/02/14 03:51:04 by falarcon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printstr(char *str, int *printed)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_printstr("(null)", printed);
		return ;
	}
	while (str[i])
		ft_printchar(str[i++], printed);
}

void	ft_printpointer(unsigned long nb, int *printed)
{
	ft_printstr("0x", printed);
	ft_printhex(nb, printed, "0123456789abcdef");
}

void	ft_printnum(int n, int *printed)
{
	long long	i;

	i = (long long)n;
	if (i < 0)
	{
		ft_printchar('-', printed);
		i = i * -1;
	}
	if (i >= 10)
	{
		ft_printnum(i / 10, printed);
		i = i % 10;
	}
	ft_printchar(i + '0', printed);
}

void	ft_printnum_unsigned(unsigned int nb, int *printed)
{
	if (nb >= 10)
	{
		ft_printnum_unsigned(nb / 10, printed);
		nb %= 10;
	}
	ft_printchar(nb + '0', printed);
}

void	ft_printhex(unsigned long long nb, int *printed, char *base)
{
	if (nb >= 16)
		ft_printhex(nb / 16, printed, base);
	ft_printchar(base[nb % 16], printed);
}

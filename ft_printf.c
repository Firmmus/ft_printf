/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarcon <falarcon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 03:41:14 by falarcon          #+#    #+#             */
/*   Updated: 2023/02/14 20:45:54 by falarcon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		i;
	int		printed;

	va_start(args, format);
	i = 0;
	printed = 0;
	while (format[i])
	{
		if (format[i] == '%')
			ft_format(format, args, ++i, &printed);
		else
			ft_printchar(format[i], &printed);
		i++;
	}
	va_end(args);
	return (printed);
}

void	ft_format(const char *str, va_list args, int i, int *printed)
{
	if (str[i] == '%')
		ft_printchar('%', printed);
	else if (str[i] == 'c')
		ft_printchar(va_arg(args, int), printed);
	else if (str[i] == 's')
		ft_printstr(va_arg(args, char *), printed);
	else if (str[i] == 'p')
		ft_printpointer(va_arg(args, unsigned long long), printed);
	else if (str[i] == 'd' || str[i] == 'i')
		ft_printnum(va_arg(args, int), printed);
	else if (str[i] == 'u')
		ft_printnum_unsigned(va_arg(args, unsigned int), printed);
	else if (str[i] == 'x')
		ft_printhex(va_arg(args, unsigned int), printed, "0123456789abcdef");
	else if (str[i] == 'X')
		ft_printhex(va_arg(args, unsigned int), printed, "0123456789ABCDEF");
}

void	ft_printchar(char c, int *printed)
{
	write(1, &c, 1);
	*printed += 1;
}

/*int	main(void)
{
	printf("Primero el caracter: %d\n", 45);

}*/

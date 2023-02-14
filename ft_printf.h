/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarcon <falarcon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 03:35:53 by falarcon          #+#    #+#             */
/*   Updated: 2023/02/14 20:49:58 by falarcon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unisdt.h>
# include <stdarg.h>

/*ft_printf.c*/
int		ft_printf(char const *format, ...);
void	ft_format(const char *str, va_list args, int i, int *printed);
void	ft_printchar(char c, int *printed);

/*ft_printf_utils.c*/
void	ft_printstr(char *str, int *printed);
void	ft_printpointer(unsigned long nb, int *printed);
void	ft_printnum(int n, int *printed);
void	ft_printnum_unsigned(unsigned int nb, int *printed);
void	ft_printhex(unsigned long long nb, int *printed, char *base);

#endif

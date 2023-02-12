# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(char const *format, ...);
void	ft_analyze_format(const char *str, va_list ap, int i, int *printed);
void	ft_printchar(char c, int *printed);
void	ft_printnum_unsigned(unsigned int nb, int *printed);
void	ft_printstr(char *str, int *printed);
void	ft_printpointer(unsigned long nb, int *printed);
void	ft_printhex(unsigned long long nb, int *printed, char *base);
void	ft_printnum(int n, int *printed);

int	main(void)
{
	printf("Primero el caracter: %d\n", 45);

}

int	ft_printf(char const *format, ...)
{
	va_list	ap;
	int		i;
	int		printed;

	va_start(ap, format);
	i = 0;
	printed = 0;
	while (format[i])
	{
		if (format[i] == '%')
			ft_analyze_format(format, ap, ++i, &printed);
		else
			ft_printchar(format[i], &printed);
		i++;
	}
	va_end(ap);
	return (printed);
}

void	ft_analyze_format(const char *str, va_list ap, int i, int *printed)
{
	if (str[i] == '%')
		ft_printchar('%', printed);
	else if (str[i] == 'c')
		ft_printchar(va_arg(ap, int), printed);
	else if (str[i] == 's')
		ft_printstr(va_arg(ap, char *), printed);
	else if (str[i] == 'p')
		ft_printpointer(va_arg(ap, unsigned long long), printed);
	else if (str[i] == 'd' || str[i] == 'i')
		ft_printnum(va_arg(ap, int), printed);
	else if (str[i] == 'u')
		ft_printnum_unsigned(va_arg(ap, unsigned int), printed);
	else if (str[i] == 'x')
		ft_printhex(va_arg(ap, unsigned int), printed, "0123456789abcdef");
	else if (str[i] == 'X')
		ft_printhex(va_arg(ap, unsigned int), printed, "0123456789ABCDEF");
}

void	ft_printchar(char c, int *printed)
{
	write(1, &c, 1);
	*printed += 1;
}

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




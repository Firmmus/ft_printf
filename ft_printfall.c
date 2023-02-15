# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(char const *format, ...);
void	ft_format(const char *str, va_list args, int i, int *printed);
void	ft_printchar(char c, int *printed);
void	ft_printnum_unsigned(unsigned int nb, int *printed);
void	ft_printstr(char *str, int *printed);
void	ft_printpointer(unsigned long nb, int *printed);
void	ft_printhex(unsigned long long nb, int *printed, char *base);
void	ft_printnum(int n, int *printed);

#include <stdio.h>

int ft_printf(const char *format, ...);

int main()
{
    char c = 'A';
    int i = 42;
    unsigned int u = 42;
    char *s = "Hello, world!";
    void *p = &s;
    char *str = NULL;

    printf("Original printf:\n");
    printf("%%c: %c\n", c);
    printf("%%d: %d\n", i);
    printf("%%i: %i\n", i);
    printf("%%u: %u\n", u);
    printf("%%s: %s\n", s);
    //printf("%s\n", str);
    printf("%%p: %p\n", p);
    printf("%%x: %x\n", u);
    printf("%%X: %X\n", u);
    printf("\n");

    printf("Custom ft_printf:\n");
    ft_printf("%%c: %c\n", c);
    ft_printf("%%d: %d\n", i);
    ft_printf("%%i: %i\n", i);
    ft_printf("%%u: %u\n", u);
    ft_printf("%%s: %s\n", s);
    ft_printf("%s\n", NULL);
    ft_printf("%%p: %p\n", p);
    ft_printf("%%x: %x\n", u);
    ft_printf("%%X: %X\n", u);
    
    return 0;
}

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




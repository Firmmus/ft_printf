#include <unistd.h>
#include <stdarg.h>

// Declare a function pointer type for the conversion functions
typedef int (*t_conv_func)(va_list);

// Declare the conversion functions
int ft_print_char(va_list args);
int ft_print_string(va_list args);
int ft_print_pointer(va_list args);
int ft_print_number(va_list args);
int ft_print_unsigned(va_list args);
int ft_print_hexadecimal(va_list args, char format);
int ft_print_percent(void);

// Create an array of function pointers for each conversion specifier
t_conv_func g_conv_funcs[] = {
    ['c'] = &ft_print_char,
    ['s'] = &ft_print_string,
    ['p'] = &ft_print_pointer,
    ['d'] = &ft_print_number,
    ['i'] = &ft_print_number,
    ['u'] = &ft_print_unsigned,
    ['x'] = &ft_print_hexadecimal,
    ['X'] = &ft_print_hexadecimal,
    ['%'] = &ft_print_percent
};

int ft_print_char(va_list args)
{
    char c;
    // Get the argument passed to the function
    c = (char)va_arg(args, int);
    ft_putchar(c);
    // Return the number of characters written
    return (1);
}

int ft_print_string(va_list args)
{
    char *s;
    int len;

    // Get the argument passed to the function
    s = va_arg(args, char*);
    len = ft_strlen(s);
    // Write the string to stdout
    write(1, s, len);
    // Return the number of characters written
    return (len);
}

int ft_print_pointer(va_list args)
{
    void *p;
    
    // Get the argument passed to the function
    p = va_arg(args, void*);
    // Write "0x" to stdout
    write(1, "0x", 2);
    ft_putnbr_base((unsigned long)p, "0123456789abcdef");
    // Return the number of characters written
    return (2 + ft_nbrlen_base((unsigned long)p, 16));
}

int ft_print_number(va_list args)
{
    int n;
    int len;

    // Get the argument passed to the function
    n = va_arg(args, int);
    len = ft_nbrlen(n);
    ft_putnbr(n);
    // Return the number of characters written
    return (len);
}

int ft_print_unsigned(va_list args)
{
    unsigned int n;
    int len;

    n = va_arg(args, unsigned int);
    len = ft_unbrlen(n);
    ft_putunbr(n);
    return (len);
}

int ft_print_hexadecimal(va_list args, char format)
{
    unsigned int n;
    char *base;
    int len;

    if (format == 'x')
        base = "0123456789abcdef";
    else
        base = "0123456789ABCDEF";
    n = va_arg(args, unsigned int);
    len = ft_nbrlen_base(n, 16);
    ft_putnbr_base(n, base);
    return (len);
}

int ft_print_percent(va_list args)
{
    (void)args;
    ft_putchar('%');
    return (1);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int i;
    int len;
    t_func formats[] = {
        ['c'] = &ft_print_char,
        ['s'] = &ft_print_string,
        ['p'] = &ft_print_pointer,
        ['d'] = &ft_print_number,
        ['i'] = &ft_print_number,
        ['u'] = &ft_print_unsigned,
        ['x'] = &ft_print_hexadecimal,
        ['X'] = &ft_print_hexadecimal,
        ['%'] = &ft_print_percent
    };

    va_start(args, format);
    i = 0;
    len = 0;
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (formats[(int)format[i]])
                len += formats[(int)format[i]](args, format[i]);
            else
                len += ft_putchar(format[i]);
        }
        else
            len += ft_putchar(format[i]);
        i++;
    }
    va_end(args);
    return (len);
}


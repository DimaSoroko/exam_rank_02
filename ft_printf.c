
// #include <unistd.h>
// #include <stdarg.h>

// int	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// 	return (1);
// }

// int	ft_putstr(char *str)
// {
// 	int	len;

// 	len = 0;
// 	if (!str)
// 		str = "(null)";
// 	while (*str)
// 		len += write(1, str++, 1);
// 	return (len);
// }

// int	ft_putnbr(int nb)
// {
// 	long long	n;
// 	int			len;

// 	len = 0;
// 	n = nb;
// 	if (n < 0)
// 	{
// 		len += write(1, "-", 1);
// 		n = -n;
// 	}
// 	if (n > 9)
// 	{
// 		len += ft_putnbr(n / 10);
// 		len += ft_putnbr(n % 10);
// 	}
// 	else
// 		len += ft_putchar(n + 48);
// 	return (len);
// }

// int	ft_puthex(unsigned int n)
// {
// 	int	len;

// 	len = 0;
// 	if (n > 15)
// 	{
// 		len += ft_puthex(n / 16);
// 		len += ft_puthex(n % 16);
// 	}
// 	else if (n > 9)
// 		len += ft_putchar(n + 87);
// 	else
// 		len += ft_putchar(n + 48);
// 	return (len);
// }

// int	ft_printf(const char *format, ...)
// {
// 	int			i;
// 	int			len;
// 	va_list		ptr;

// 	len = 0;
// 	i = -1;
// 	va_start(ptr, format);
// 	while (format[++i])
// 	{
// 		if (format[i] != '%')
// 			len += write(1, &format[i], 1);
// 		else if (format[i] == '%' && format[i + 1])
// 		{
// 			i++;
// 			if (format[i] == 's')
// 				len += ft_putstr(va_arg(ptr, char *));
// 			else if (format[i] == 'x')
// 				len += ft_puthex(va_arg(ptr, unsigned int));
// 			else if (format[i] == 'd')
// 				len += ft_putnbr(va_arg(ptr, int));
// 		}
// 	}
// 	va_end(ptr);
// 	return (len);
// }


// #include <stdio.h>
// int main(void)
// {
// 	char *str = "hello";
// 	int digit = 0;
// 	unsigned int hex_x = -128;

// 	ft_printf("-------------------------------------\n");
// 	ft_printf("|    My ft_printf implimentation    |\n");
// 	ft_printf("-------------------------------------\n");
// 	ft_printf("String is: %s\n", str);
// 	ft_printf("Digit is: %d\n", digit);
// 	ft_printf("Hexadecimal x is: %x\n", hex_x);

// 	ft_printf("\n");

// 	printf("-------------------------------------\n");
// 	printf("|            Real printf            |\n");
// 	printf("-------------------------------------\n");
// 	printf("String is: %s\n", str);
// 	printf("Digit is: %d\n", digit);
// 	printf("Hexadecimal x is: %x\n", hex_x);
// 	return 0;
// }



/////////////////////////////////////////////////////////////////////////////

// #include <unistd.h>
// #include <stdarg.h>

// int ft_putchar(char c)
// {
//     return write(1, &c, 1);
// }

// int ft_putstr(char *s)
// {
//     int ret = 0;
//     while (*s)
//         ret += ft_putchar(*s++);
//     return ret;
// }

// #define hex "0123456789abcdef"
// int ft_putnbr(long long n, int base)
// {
//     int ret = 0;

//     if (n < 0)
//     {
//         ret += write(1, "-", 1);
//         n *= -1;
//     }
//     if (n >= base)
//         ret += ft_putnbr(n/base, base);
//     ret += ft_putchar(hex[n%base]);
//     return ret;
// }

// int print(char *f, va_list ap)
// {
//     int ret = 0;
//     char c;

//     while (*f)
//     {
//         c = *f++;
//         if (c != '%')
//             ret += ft_putchar(c);
//         else
//         {
//             c = *f++;
//             if (c == 'c')
//                 ret += ft_putchar((char)va_arg(ap, int));
//             if (c == 's')
//                 ret += ft_putstr(va_arg(ap, char *));
//             if (c == 'd')
//                 ret += ft_putnbr((long long)va_arg(ap, int), 10);
//             if (c == 'x')
//                 ret += ft_putnbr((long long)va_arg(ap, unsigned int), 16);
//         }
//     }
//     return ret;
// }

// int ft_printf(char *f, ...)
// {
//     va_list ap;
//     int ret = 0;

//     va_start(ap, f);
//     ret += print(f, ap);
//     va_end(ap);
//     return ret;
// }


// #include <limits.h>
// #include <stdio.h>
// int main()
// {
//     int f, s;
//     f = ft_printf("%s %c %d %d %x\n", "hello", 'X', INT_MAX, INT_MIN, UINT_MAX);
//     s =    printf("%s %c %d %d %x\n", "hello", 'X', INT_MAX, INT_MIN, UINT_MAX);
//     printf("%d | %d\n", f, s);
// }


///////////////////////////////TEST/////////////////////////////

#include <unistd.h>
#include <stdarg.h>
#define hex "0123456789abcdef"

int ft_putchar(char c)
{
    return (write(1, &c, 1));
}

int ft_putstr(char *str)
{
    int ret = 0;
    while(*str)
        ret += ft_putchar(*str++);
    return (ret);
}

int ft_putnbr (long long n, int base)
{
    int ret = 0;
    if (n < 0)
    {
        ret += write(1, "-", 1);
        n *= -1;
    }
    if (n >= base)
        ret = ft_putnbr(n/base, base);
    ret += ft_putchar(hex[n%base]);
    return (ret);
}

int print (char *f, va_list ap)
{
    int ret = 0;
    char c;
    while (*f)
    {
        c = *f++;
            if(c != '%')
                ret += ft_putchar(c);
            else
            {
                c = *f++;
                if (c == 'c')
                    ret += ft_putchar((char)va_arg(ap,int));
                if (c == 's')
                    ret += ft_putstr(va_arg(ap, char*));
                if (c == 'd')
                    ret += ft_putnbr((long long) va_arg(ap, int),10);
                if (c == 'x')
                    ret += ft_putnbr((long long)va_arg(ap, unsigned int),16);
            }
    }
    return (ret);
}

int ft_printf (char *f, ...)
{
    va_list ap;
    int ret = 0;
    va_start(ap, f);
    ret += print(f, ap);
    va_end(ap);
    return (ret);
}

#include <stdio.h>
int main(void)
{
	char c = 'c';
    char *str = "hello";
	int digit = 0;
	unsigned int hex_x = -128;

	ft_printf("-------------------------------------\n");
	ft_printf("|    My ft_printf implimentation    |\n");
	ft_printf("-------------------------------------\n");
	ft_printf("Char0 is: %c\n", c);
    ft_printf("String is: %s\n", str);
	ft_printf("Digit is: %d\n", digit);
	ft_printf("Hexadecimal x is: %x\n", hex_x);

	ft_printf("\n");

	printf("-------------------------------------\n");
	printf("|            Real printf            |\n");
	printf("-------------------------------------\n");
    printf("Char0 is: %c\n", c);\
	printf("String is: %s\n", str);
	printf("Digit is: %d\n", digit);
	printf("Hexadecimal x is: %x\n", hex_x);
	return 0;
}

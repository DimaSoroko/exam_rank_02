
#include <unistd.h>
#include <stdarg.h>
#define hex "0123456789abcdef"

int ft_putchar(char c)
{
    return write(1, &c, 1);
}

int ft_putstr(char *str)
{
    int ret = 0;
    if(!str)
    {
        write(1, "(null)", 1);
        ret += 6;
    }
    else
    {
        while(*str)
        ret += ft_putchar(*str++);
    }
    return ret;
}

int ft_putnbr(long long n, int base)
{
    int ret = 0;
    if (n < 0)
        {
            ret += ft_putchar('-');
            n *= -1;
        }
    if (n >= base)
        ret += ft_putnbr(n/base, base);
    ret += ft_putchar(hex[n%base]);
    return ret;
}

int print(char *f, va_list ap)
{
    int ret = 0;
    char c;
    while(*f)
    {
        c = *f++;
        if(c != '%')
            ret += ft_putchar(c);
        else
        {
            c = *f++;
            if(c == 'c')
                ret += ft_putchar((char)va_arg(ap, int));
            if(c == 's')
                ret += ft_putstr(va_arg(ap, char*));
            if(c == 'd')
                ret += ft_putnbr((long long)va_arg(ap, int),10);
            if(c == 'x')
                ret += ft_putnbr((long long)va_arg(ap, unsigned int), 16);
        }
    }
    return ret;
}

int ft_printf(char *f, ...)
{
    int ret = 0;
    va_list ap;
    va_start(ap, f);
    ret += print(f, ap);
    va_end(ap);
    return ret;
}

// #include <stdio.h>
// int main(void)
// {
// 	char c = 'c';
//         char *str = "hello";
// 	int digit = 0;
// 	unsigned int hex_x = -128;

// 	ft_printf("-------------------------------------\n");
// 	ft_printf("|    My ft_printf implimentation    |\n");
// 	ft_printf("-------------------------------------\n");
// 	ft_printf("Char is: %c\n", c);
//         ft_printf("String is: %s\n", str);
// 	ft_printf("Digit is: %d\n", digit);
// 	ft_printf("Hexadecimal x is: %x\n", hex_x);

// 	ft_printf("\n");

// 	printf("-------------------------------------\n");
// 	printf("|            Real printf            |\n");
// 	printf("-------------------------------------\n");
//         printf("Char is: %c\n", c);\
// 	printf("String is: %s\n", str);
// 	printf("Digit is: %d\n", digit);
// 	printf("Hexadecimal x is: %x\n", hex_x);
// 	return 0;
// }

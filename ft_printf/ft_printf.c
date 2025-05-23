
#include <unistd.h>
#include <stdarg.h>

int ft_putnbr(int nbr)
{
	int len = 0;
	long n = nbr;
	if (n < 0)
	{
		len += write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		len += ft_putnbr( n / 10);
	}
	len += write(1, &"0123456789"[n % 10], 1);
	return (len);
}

int ft_puthex(unsigned int n)
{
	int len = 0;
	if (n > 15)
	{
		len += ft_puthex( n / 16);
	}
	len += write(1, &"0123456789abcdef"[n % 16], 1);
	return (len);
}
int ft_putstr(char *str)
{
	int len = 0;
	if (!str)
	{
		str = "(null)";
	}
	while (*str)
	{
		len += write(1, str, 1);
		str++;
	}
	return (len);
}

int ft_printf(const char *str, ...)
{
	va_list arg;
	int len = 0;
	va_start(arg, str);

	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			str++;
			if (*str == 'd')
			{
				len += ft_putnbr(va_arg(arg, int));
			}
			else if (*str == 's')
			{
				len += ft_putstr(va_arg(arg, char *));
			}
			else if (*str == 'x')
			{
				len += ft_puthex(va_arg(arg, unsigned int));
			}
		}
		else
			len += write(1, str, 1);
		str++;
	}
	va_end(arg);
	return (len);
}
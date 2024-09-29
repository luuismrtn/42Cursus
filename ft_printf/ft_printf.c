
#include "ft_printf.h"

static char	ft_check_char(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (c);
	return (0);
}

static void	ft_puthex_fd(unsigned int n, int fd, int upper)
{
	char	*base;

	if (upper == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
		ft_puthex_fd(n / 16, fd, upper);
	ft_putchar_fd(base[n % 16], fd);
}

static void	ft_putptr_fd(void *ptr, int fd)
{
	ft_putstr_fd("0x", fd);
	ft_puthex_fd((unsigned long)ptr, fd, 0);
}

static int	ft_print(char c, va_list args)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'p')
		ft_putptr_fd(va_arg(args, void *), 1);
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		ft_putnbr_fd(va_arg(args, unsigned int), 1);
	else if (c == 'x')
		ft_puthex_fd(va_arg(args, unsigned int), 1, 0);
	else if (c == 'X')
		ft_puthex_fd(va_arg(args, unsigned int), 1, 1);
	else if (c == '%')
		ft_putchar_fd('%', 1);
	else
		return (0);
	return (1);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		i;

	va_start(args, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && ft_check_char(format[i + 1]) != 0)
		{
			i++;
			if (ft_print(format[i], args) == 0)
				return (0);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
		}
		i++;
	}
	va_end(args);
	return (0);
}


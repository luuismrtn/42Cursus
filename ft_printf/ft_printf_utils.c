/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:02:14 by lumartin          #+#    #+#             */
/*   Updated: 2024/09/30 17:25:43 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_putstr_fd("-2147483648", fd);
		return (count);
	}
	if (n < 0)
	{
		count += ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n > 9)
		count += ft_putnbr_fd(n / 10, fd);
	count += ft_putchar_fd(n % 10 + '0', fd);
	return (count);
}


int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
		count += ft_putchar_fd(s[i++], fd);
	return (count);
}

int	ft_puthex_fd(unsigned int n, int fd, int upper)
{
	char	*base;
	int		count;

	count = 0;
	if (upper == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_puthex_fd(n / 16, fd, upper);
	count += ft_putchar_fd(base[n % 16], fd);
	return (count);
}

int	ft_putptr_fd(void *ptr, int fd)
{
	int				count;
	unsigned long	ptr_value;

	count = 0;
	ptr_value = (unsigned long)ptr;
	count += ft_putstr_fd("0x", fd);
	count += ft_puthex_fd(ptr_value, fd, 0);
	return (count);
}



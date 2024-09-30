/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:30:00 by mcarnere          #+#    #+#             */
/*   Updated: 2024/09/30 17:08:12 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
# include <limits.h>
#include "ft_printf.h"

int	main()
{
	int num = INT_MIN;
    char ch = 'A';
    unsigned int hex = 0xABCD;
	unsigned int hexl = 0xABCD;
    int *ptr = &num;
	char *str = "Hello, world!";
	unsigned int unum = UINT_MAX;
// NORMAL TESTS CASES
	// Test case 1: Printing a string
	printf("%d\n", ft_printf("Hello, world!\n"));
	printf("%d\n", printf("Hello, world!\n"));

	// Test case 2: Printing an integer
	printf("%d\n", ft_printf("The answer is %i %d\n", num, 42));
	printf("%d\n", printf("The answer is %i %d\n", num, 42));

	// Test case 3: Printing a character
	printf("%d\n", ft_printf("The character is %c\n", ch));
	printf("%d\n", printf("The character is %c\n", ch));

	// Test case 4: Printing a hexadecimal number
	printf("%d\n", ft_printf("The hexadecimal number is %X\n", hex));
	printf("%d\n", printf("The hexadecimal number is %X\n", hex));

	// Test case 5: Printing a lowercase hexadecimal number
	printf("%d\n", ft_printf("The lowercase hexadecimal number is %x\n", hexl));
	printf("%d\n", printf("The lowercase hexadecimal number is %x\n", hexl));

	// Test case 6: Printing a pointer
	printf("%d\n", ft_printf("The pointer is %p\n", ptr));
	printf("%d\n", printf("The pointer is %p\n", ptr));

	// Test case 7: Printing a string from a pointer
	printf("%d\n", ft_printf("The string is %s\n", str));
	printf("%d\n", printf("The string is %s\n", str));

	// Test case 8: Printing an unsigned integer
	printf("%d\n", ft_printf("The unsigned integer is %u\n", unum));
	printf("%d\n", printf("The unsigned integer is %u\n", unum));

	// Test case 9: Printing a percentage sign
	printf("%d\n", ft_printf("The percentage sign is %%\n"));
	printf("%d\n", printf("The percentage sign is %%\n"));

	// Test case 10: Printing everything together
	printf("%d\n", ft_printf("The answer is %%%i%X %% %x %p%s %u %c\n",
	num, hex, hex, ptr, str, unum, ch));
	printf("%d\n", printf("The answer is %%%i%X %% %x %p%s %u %c\n",
	num, hex, hex, ptr, str, unum, ch));

	//Test case 11: Trying to print null with %s & %p
	char *null = NULL;
	printf("%d\n", ft_printf("The string is %s, the pointer is %p\n", null, NULL));
	printf("%d\n", printf("The string is %s, the pointer is %p\n", null, NULL));

//PACO TESTS

	char *s2 = "Mussum Ipsum, cacilds vidis litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus.";

	printf("%d\n", printf("%s", ""));
	printf("%d\n", printf(" %s", ""));
	printf("%d\n", printf("%s ", ""));
	printf("%d\n", printf(" %s ", ""));
	printf("%d\n", printf(" %s %s ", "", "-"));
	printf("%d\n", printf(" %s %s ", " - ", ""));
	printf("%d\n", printf(" %s %s %s %s %s", " - ", "", "4", "", s2));
	printf("%d\n", printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 "));

	printf("%d\n", ft_printf("%s", ""));
	printf("%d\n", ft_printf(" %s", ""));
	printf("%d\n", ft_printf("%s ", ""));
	printf("%d\n", ft_printf(" %s ", ""));
	printf("%d\n", ft_printf(" %s %s ", "", "-"));
	printf("%d\n", ft_printf(" %s %s ", " - ", ""));
	printf("%d\n", ft_printf(" %s %s %s %s %s", " - ", "", "4", "", s2));
	printf("%d\n", ft_printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 "));

// ERROR TEST CASES
	// Test case 12: Trying to print a string with other specifiers
	ft_printf("The string is %s%c%X%x%d%u%p\n", str, str, str, str, str, str, str);

	// Test case 13: Trying to format nonexistent arguments
	ft_printf("They are %s%%%c%X%x%d%u%p\n");
	
	// Test case 14: Trying to print a something with %p
	ft_printf("The string is %p %p %p %p %p %p %p\n", num, hex, hex, ptr, str, unum, ch);

	//Test case 15: Using % and no specifier
	ft_printf("The string is %j refe\n", ch);
	printf("The string is %j refe\n", str);


	//Test case 16: Using % at the end of the string
	ft_printf("%");
	printf("%");

	// Test case 17: Segfault
	//ft_printf("The string is %s\n", ch);
	//printf("The string is %s\n", ch);
	
    return (0);
}
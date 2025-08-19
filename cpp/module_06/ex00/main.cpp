/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:08:11 by lumartin          #+#    #+#             */
/*   Updated: 2025/08/19 20:27:15 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "./inc/ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
        return (1);
    }

    ScalarConverter::convert(argv[1]);

    /*
    ScalarConverter::convert("?"); // Char: ?
    std::cout << std::endl;
    ScalarConverter::convert("42");  // Int: 42
    std::cout << std::endl;
    ScalarConverter::convert("424242");  // Int: 424242
    std::cout << std::endl;
    ScalarConverter::convert("4.2f"); // Float: 4,2
    std::cout << std::endl;
    ScalarConverter::convert("-4.2"); // Double: -4.2
    std::cout << std::endl;
    ScalarConverter::convert("42."); // Double: 1.
    std::cout << std::endl;
    ScalarConverter::convert("4.2"); // Double: 4.2
    std::cout << std::endl;
    ScalarConverter::convert("0x42"); // Invalid input
    std::cout << std::endl;
    ScalarConverter::convert("+inf"); // Inf
    */

    return (0);
}

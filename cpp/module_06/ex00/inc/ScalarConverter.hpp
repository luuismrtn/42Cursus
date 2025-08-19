/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 19:55:41 by lumartin          #+#    #+#             */
/*   Updated: 2025/08/19 21:01:53 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <cstdlib>
#include <cstdio>
#include <cmath>

enum types
{
    INVALID,
    CHAR,
    INT,
    FLOAT,
    DOUBLE
};

class ScalarConverter
{
    public :
        static void convert(std::string literal);

    private :
        ScalarConverter(void);
        ScalarConverter(ScalarConverter const & copy);
        ~ScalarConverter(void);

        ScalarConverter & operator =(ScalarConverter const & src);

        static void printChar(const char c);
        static void printInt(const int nb);
        static void printFloat(const float nb);
        static void printDouble(const double nb);

        static char stringToChar(std::string const & literal);
        static int stringToInt(std::string const & literal);
        static float stringToFloat(std::string const & literal);
        static double stringToDouble(std::string const & literal);
};

bool isInt(std::string literal);

bool isDouble(std::string literal);

bool isFloat(std::string literal);

#endif
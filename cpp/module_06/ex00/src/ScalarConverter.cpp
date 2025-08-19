/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 19:56:41 by lumartin          #+#    #+#             */
/*   Updated: 2025/08/19 21:02:03 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &copy)
{
    *this = copy;
    return;
}

ScalarConverter::~ScalarConverter(void)
{
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
    if (this != &src)
    {
        return (*this);
    }

    return (*this);
}

bool isInt(std::string literal)
{
    std::stringstream sstr(literal);
    int a;

    sstr >> a;
    if (!sstr.fail() && sstr.eof())
        return (true);
    return (false);
}

bool isDouble(std::string literal)
{
    std::stringstream sstr(literal);
    double a;

    sstr >> a;
    if (!sstr.fail() && sstr.eof())
        return (true);
    return (false);
}

bool isFloat(std::string literal)
{
    if (literal[literal.length() - 1] == 'f')
        literal = literal.erase(literal.length() - 1);

    std::stringstream sstr(literal);
    float a;

    sstr >> a;
    if (!sstr.fail() && sstr.eof())
        return (true);
    return (false);
}

void ScalarConverter::printChar(const char c)
{
    std::cout << "Char: ";
    if (c < 32 || c > 126)
        std::cout << "Non displayable";
    else
        std::cout << "'" << c << "'";
    std::cout << std::endl;
    return;
}

void ScalarConverter::printInt(const int nb)
{
    std::cout << "Int: ";
    std::cout << nb << std::endl;
    return;
}

void ScalarConverter::printFloat(const float nb)
{
    std::cout << "Float: ";
    std::cout << nb;
    if (nb != std::numeric_limits<float>::infinity() && nb != -std::numeric_limits<float>::infinity() && (nb - floor(nb)) <= 0.0f)
        std::cout << ".0";
    std::cout << "f" << std::endl;
    return;
}

void ScalarConverter::printDouble(const double nb)
{
    std::cout << "Double: ";
    std::cout << nb;
    if (nb != std::numeric_limits<double>::infinity() && nb != -std::numeric_limits<double>::infinity() && (nb - floor(nb)) <= 0.0f)
        std::cout << ".0";
    std::cout << std::endl;
    return;
}

char ScalarConverter::stringToChar(std::string const &literal)
{
    std::istringstream sstr(literal);
    char c;

    sstr >> c;
    if (literal[0] == ' ')
        c = ' ';
    return (c);
}

int ScalarConverter::stringToInt(std::string const &literal)
{
    std::istringstream sstr(literal);
    int nb;

    sstr >> nb;
    return (nb);
}

float ScalarConverter::stringToFloat(std::string const &literal)
{
    std::istringstream sstr(literal);
    float nb;

    sstr >> nb;
    if (sstr.fail())
    {
        if (literal == "+inff")
            nb = std::numeric_limits<float>::infinity();
        else if (literal == "-inff")
            nb = -std::numeric_limits<float>::infinity();
        else if (literal == "nanf")
            nb = std::numeric_limits<float>::quiet_NaN();
    }
    return (nb);
}

double ScalarConverter::stringToDouble(std::string const &literal)
{
    std::istringstream sstr(literal);
    double nb;

    sstr >> nb;
    if (sstr.fail())
    {
        if (literal == "+inf")
            nb = std::numeric_limits<double>::infinity();
        else if (literal == "-inf")
            nb = -std::numeric_limits<double>::infinity();
        else if (literal == "nan")
            nb = std::numeric_limits<double>::quiet_NaN();
    }
    return (nb);
}

int getType(std::string literal)
{
    int type = 0;
    if (literal.size() == 1 && !isdigit(literal[0]))
        type = CHAR;
    else if (literal == "-inff" || literal == "+inff" || literal == "nanf")
        type = FLOAT;
    else if (literal == "-inf" || literal == "+inf" || literal == "nan")
        type = DOUBLE;
    else if (literal.find('.') != std::string::npos)
    {
        if (isDouble(literal))
            type = DOUBLE;
        else if (isFloat(literal))
            type = FLOAT;
    }
    else if (isInt(literal))
        type = INT;
    else
        type = INVALID;
    return (type);
}

void ScalarConverter::convert(std::string literal)
{
    int type = getType(literal);

    switch (type)
    {
        case INVALID:
            std::cout << "Invalid input!" << std::endl;
            break;
        case CHAR:
        {
            char c = stringToChar(literal);
            printChar(c);
            printInt(static_cast<int>(c));
            printFloat(static_cast<float>(c));
            printDouble(static_cast<double>(c));
            break;
        }
        case INT:
        {
            int nb = stringToInt(literal);
            printChar(static_cast<char>(nb));
            printInt(nb);
            printFloat(static_cast<float>(nb));
            printDouble(static_cast<double>(nb));
            break;
        }
        case FLOAT:
        {
            float nb = stringToFloat(literal);
            if (literal == "+inff" || literal == "-inff" || literal == "nanf")
            {
                std::cout << "Char: impossible" << std::endl;
                std::cout << "Int: impossible" << std::endl;
            }
            else
            {
                printChar(static_cast<char>(nb));
                printInt(static_cast<int>(nb));
            }
            printFloat(nb);
            printDouble(static_cast<double>(nb));
            break;
        }
        case DOUBLE:
        {
            double nb = stringToDouble(literal);
            if (literal == "+inf" || literal == "-inf" || literal == "nan")
            {
                std::cout << "Char: impossible" << std::endl;
                std::cout << "Int: impossible" << std::endl;
            }
            else
            {
                printChar(static_cast<char>(nb));
                printInt(static_cast<int>(nb));
            }
            printFloat(static_cast<float>(nb));
            printDouble(nb);
            break;
        }
    }
}

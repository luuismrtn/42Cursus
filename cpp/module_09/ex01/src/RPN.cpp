/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:39:04 by lumartin          #+#    #+#             */
/*   Updated: 2025/10/23 17:23:25 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) : _operands(other._operands) {}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        _operands = other._operands;
    }
    return *this;
}

int RPN::evaluate(const std::string &expression)
{
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
    {
        if (myAtoi(token) != 50)
        {
            if (myAtoi(token) > 9)
                throw invalidOperand();

            _operands.push(myAtoi(token));
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (_operands.size() < 2)
                throw wrongOperands();

            int right = _operands.top();
            _operands.pop();
            int left = _operands.top();
            _operands.pop();
            int result;

            if (token == "+")
                result = left + right;
            else if (token == "-")
                result = left - right;
            else if (token == "*")
                result = left * right;
            else if (token == "/")
            {
                if (right == 0)
                    throw divisionZero();
                result = left / right;
            }

            _operands.push(result);
        }
        else
        {
            throw invalidToken();
        }
    }

    if (_operands.size() != 1)
        throw invalidExpression();

    return _operands.top();
}

int RPN::myAtoi(std::string str)
{
    int result = 0;
    bool negative = false;
    bool started = false;
    int i = 0;

    if (str.find('.') != std::string::npos)
        return 50;

    if (str.empty() || (str[0] != '+' && str[0] != '-' && (str[0] < '0' || str[0] > '9')))
        return 50;

    while (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
        {
            negative = !negative;
        }
        i++;
    }

    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        started = true;
        i++;
    }

    if (!started)
        return 50;
    return result * (negative ? -1 : 1);
}

const char *RPN::invalidOperand::what() const throw()
{
    return "Invalid number.";
}

const char *RPN::invalidExpression::what() const throw()
{
    return "Invalid operand in expression.";
}

const char *RPN::wrongOperands::what() const throw()
{
    return "Wrong number of operands for operation.";
}

const char *RPN::divisionZero::what() const throw()
{
    return "Division by zero.";
}

const char *RPN::invalidToken::what() const throw()
{
    return "Invalid token in expression.";
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:38:55 by lumartin          #+#    #+#             */
/*   Updated: 2025/10/23 17:19:19 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <cctype>

class RPN
{
private:
    std::stack<int> _operands;
    int myAtoi(std::string str);

public:
    RPN();
    ~RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);

    int evaluate(const std::string &expression);

    class invalidOperand : public std::exception
    {
        public:
            const char *what() const throw();
    };

    class invalidExpression : public std::exception
    {
        public:
            const char *what() const throw();
    };

    class wrongOperands : public std::exception
    {
        public:
            const char *what() const throw();
    };

    class divisionZero : public std::exception
    {
        public:
            const char *what() const throw();
    };

    class invalidToken : public std::exception
    {
        public:
            const char *what() const throw();
    };
};

#endif
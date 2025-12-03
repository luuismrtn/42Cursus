/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:38:55 by lumartin          #+#    #+#             */
/*   Updated: 2025/12/04 00:21:20 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <climits>

class RPN
{
private:
    std::stack<long> _operands;
    long myAtoi(std::string str);

public:
    RPN();
    ~RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);

    long evaluate(const std::string &expression);

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

    class outInteger : public std::exception
    {
        public:
            const char *what() const throw();
    };
};

#endif

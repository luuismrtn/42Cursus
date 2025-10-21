/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:20:37 by lumartin          #+#    #+#             */
/*   Updated: 2025/10/21 21:17:02 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <stdexcept>

class BitcoinExchange
{
    private:
        std::map<std::string, float> exchangeRates;

        void loadExchangeRates(const std::string &filename);
        std::string toString(std::string date, float value, float result);
        bool isValidDate(const std::string &date);
        bool isValidValue(float value);

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(BitcoinExchange const &copy);
        BitcoinExchange &operator=(BitcoinExchange const &rhs);

        void fileReader(const std::string &filename);

        class fileException : public std::exception
        {
            public:
                const char *what() const throw();
        };

        class firstLineException : public std::exception
        {
            public:
                const char *what() const throw();
        };

        class dataBaseException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

#endif

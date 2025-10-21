/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:21:07 by lumartin          #+#    #+#             */
/*   Updated: 2025/10/21 21:35:27 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    loadExchangeRates("data.csv");
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy)
{
    *this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src)
{
    if (this != &src)
    {
        this->exchangeRates = src.exchangeRates;
    }
    return *this;
}

void BitcoinExchange::loadExchangeRates(const std::string &filename)
{
    std::ifstream file(filename.c_str());

    if (!file.is_open())
        throw fileException();

    std::string line;
    std::getline(file, line);

    if (line.empty())
        throw fileException();

    while (std::getline(file, line))
    {
        std::string date, exchangeRateStr;
        float rate = 0.00;

        std::stringstream ss(line);
        std::getline(ss, date, ',');
        std::getline(ss, exchangeRateStr, '\n');

        std::istringstream iss(exchangeRateStr);
        iss >> rate;

        this->exchangeRates[date] = rate;
    }
    file.close();
}

void BitcoinExchange::fileReader(const std::string &filename)
{
    std::ifstream file(filename.c_str());

    if (!file.is_open())
        throw fileException();

    std::string line;
    std::getline(file, line);

    if (line != "date | value")
        throw firstLineException();

    std::string date;
    float value = 0.0;

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string valueStr;

        std::getline(ss, date, '|');
        std::getline(ss, valueStr, '\n');


        valueStr = valueStr.erase(0, valueStr.find_first_not_of(" "));

        std::istringstream iss(valueStr);
        iss >> value;

        date = date.erase(date.find_last_not_of(" ") + 1);

        if (date.empty())
        {
            std::cout << "Error: date have to exist" << date << std::endl;
            continue;
        }

        if (!isValidDate(date))
        {
            std::cout << "Error: bad date input => " << date << std::endl;
            continue;
        }

        if (valueStr.empty())
        {
            std::cout << "Error: value have to exist" << std::endl;
            continue;
        }

        if (!isValidValue(value))
        {
            if (value < 0)
            {
                std::cout << "Error: not a positive number." << std::endl;
                continue;
            }
            else
            {
                std::cout << "Error: too large a number." << std::endl;
                continue;
            }
        }

        std::map<std::string, float>::iterator it = this->exchangeRates.find(date);
        if (it != this->exchangeRates.end())
        {
            std::cout << toString(date, value, value * it->second) << std::endl;
        }
        else
        {
            it = this->exchangeRates.lower_bound(date);
            if (it == this->exchangeRates.begin())
            {
                std::cout << "Error: no exchange rate available for date " << std::endl;
                continue;
            }
            --it;
            float result = value * it->second;
            std::cout << toString(date, value, result) << std::endl;
        }
    }
}

std::string BitcoinExchange::toString(std::string date, float value, float result)
{
    std::ostringstream oss;
    oss << date << " => " << value << " = " << result;
    return oss.str();
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    std::istringstream yearStream(date.substr(0, 4));
    std::istringstream monthStream(date.substr(5, 2));
    std::istringstream dayStream(date.substr(8, 2));

    int year, month, day;

    if (!(yearStream >> year) || !(monthStream >> month) || !(dayStream >> day))
        return false;

    if (month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;

    if (month == 2)
    {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (isLeap ? 29 : 28))
            return false;
    }

    return true;
}

bool BitcoinExchange::isValidValue(float value)
{
    return value >= 0 && value <= 1000;
}

const char *BitcoinExchange::fileException::what() const throw()
{
    return "could not open file.";
}

const char *BitcoinExchange::firstLineException::what() const throw()
{
    return "first line is not valid.";
}

const char *BitcoinExchange::dataBaseException::what() const throw()
{
    return "database file is not valid.";
}

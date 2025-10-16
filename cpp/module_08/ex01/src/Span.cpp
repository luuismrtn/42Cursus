/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 19:19:46 by lumartin          #+#    #+#             */
/*   Updated: 2025/10/16 16:00:35 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"
#include <climits>

Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span &other) : _N(other._N), _vec(other._vec) {}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _N = other._N;
        _vec = other._vec;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
    if (_vec.size() >= _N)
        throw SpanFullException();
    _vec.push_back(number);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (std::distance(begin, end) + _vec.size() > _N)
        throw SpanFullException();
    _vec.insert(_vec.end(), begin, end);
}

int Span::shortestSpan() const
{
    if (_vec.size() < 2)
        throw NotEnoughNumbersException();

    std::vector<int> sortedVec = _vec;
    std::sort(sortedVec.begin(), sortedVec.end());

    int minSpan = INT_MAX;
    for (size_t i = 1; i < sortedVec.size(); ++i)
    {
        int span = sortedVec[i] - sortedVec[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan() const
{
    if (_vec.size() < 2)
        throw NotEnoughNumbersException();

    int minElem = *std::min_element(_vec.begin(), _vec.end());
    int maxElem = *std::max_element(_vec.begin(), _vec.end());

    return maxElem - minElem;
}

const char *Span::SpanFullException::what() const throw()
{
    return "Span is full. Cannot add more numbers.";
}

const char *Span::NotEnoughNumbersException::what() const throw()
{
    return "Not enough numbers to find a span.";
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 18:18:49 by lumartin          #+#    #+#             */
/*   Updated: 2025/09/11 19:57:05 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <iterator>

class NotFoundException : public std::exception
{
public:
    virtual const char *what() const throw()
    {
        return "Value not found in the container";
    }
};

template <typename T>
typename T::iterator easyfind(T &c, int value)
{
    typename T::iterator it = std::find(c.begin(), c.end(), value);
    if (it == c.end())
    {
        throw NotFoundException();
    }
    return it;
}

#endif
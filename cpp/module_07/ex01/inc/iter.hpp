/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 18:25:47 by lumartin          #+#    #+#             */
/*   Updated: 2025/10/16 16:52:37 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T>
void iter(T *array, const std::size_t length, void (*func)(const T &))
{
    for (std::size_t i = 0; i < length; ++i)
    {
        func(array[i]);
    }
}

template <typename T>
void iter(T *array, const std::size_t length, void (*func)(T &))
{
    for (std::size_t i = 0; i < length; ++i)
    {
        func(array[i]);
    }
}

#endif

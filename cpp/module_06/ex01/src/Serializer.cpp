/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 20:36:59 by lumartin          #+#    #+#             */
/*   Updated: 2025/08/19 21:01:41 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

Serializer::Serializer(void)
{
}

Serializer::Serializer(const Serializer &src)
{
    *this = src;
}

Serializer::~Serializer(void)
{
}

Serializer &Serializer::operator=(const Serializer &src)
{
    if (this != &src)
    {
        return (*this);
    }
    return (*this);
}

uintptr_t Serializer::serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}

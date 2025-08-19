/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 20:35:53 by lumartin          #+#    #+#             */
/*   Updated: 2025/08/19 20:40:52 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>
#include <string>

typedef struct s_data
{
	int id;
	std::string name;
} Data;

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer &src);
        virtual ~Serializer(void);
		
        Serializer &operator=(const Serializer &src);

    public:
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
};

#endif

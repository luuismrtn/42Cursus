/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:08:11 by lumartin          #+#    #+#             */
/*   Updated: 2025/08/19 20:44:21 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/Serializer.hpp"

int main (void)
{
    Data data;

    data.id = 42;
	data.name = "Eval";

	uintptr_t raw = Serializer::serialize(&data);

    std::cout << "Serialized data: " << raw << std::endl;
    
	Data *ptr = Serializer::deserialize(raw);

    std::cout << "Deserialized data: " << std::endl;
    std::cout << "ID: " << ptr->id << std::endl;
    std::cout << "Name: " << ptr->name << std::endl;

    return 0;
}

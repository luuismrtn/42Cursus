/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 20:36:59 by lumartin          #+#    #+#             */
/*   Updated: 2025/08/19 21:01:02 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

Base::~Base(void)
{
    return;
}

Base * generate(void)
{
    int random = rand() % 3;

    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& checker1 = dynamic_cast<A&>(p);
		std::cout<<"Type A"<<std::endl;
		(void)checker1;
	}
	catch(const std::exception& e)
	{
		try
		{
			B& checker2 = dynamic_cast<B&>(p);
			std::cout<<"Type B"<<std::endl;
			(void)checker2;
		}
		catch(const std::exception& e)
		{
			try
			{
				C& checker3 = dynamic_cast<C&>(p);
				std::cout<<"Type C"<<std::endl;
				(void)checker3;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}

	}
}

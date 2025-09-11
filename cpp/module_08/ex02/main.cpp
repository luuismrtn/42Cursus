/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 19:20:13 by lumartin          #+#    #+#             */
/*   Updated: 2025/09/11 21:46:57 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "./inc/MutantStack.hpp"

#include <list>

int main()
{
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
    std::cout << "------------------" << std::endl;
    {
        std::list<int> mlist;
        mlist.push_back(5);
        mlist.push_back(17);
        std::cout << mlist.back() << std::endl;
        mlist.pop_back();
        std::cout << mlist.size() << std::endl;
        mlist.push_back(3);
        mlist.push_back(5);
        mlist.push_back(737);
        mlist.push_back(0);
        std::list<int>::iterator l_it = mlist.begin();
        std::list<int>::iterator l_ite = mlist.end();
        ++l_it;
        --l_it;
        while (l_it != l_ite)
        {
            std::cout << *l_it << std::endl;
            ++l_it;
        }
    }
    std::cout << "------------------" << std::endl;
    {
        MutantStack<double> mstack;
        mstack.push(5.5);
        mstack.push(17.17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        mstack.push(42.5);
        mstack.push(3.14);
        mstack.push(2.71);
        mstack.push(0.0);
        mstack.pop();
        mstack.top();
        std::cout << "Size: " << mstack.size() << std::endl;

        MutantStack<double>::iterator it = mstack.begin();
        MutantStack<double>::iterator ite = mstack.end();

        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
}

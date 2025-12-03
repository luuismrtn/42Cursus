/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:41:51 by lumartin          #+#    #+#             */
/*   Updated: 2025/12/03 17:07:53 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <time.h>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <cmath>

#include <stdio.h>

class PmergeMe
{
private:
    std::vector<int> vec;
    std::deque<int> deq;

    std::vector<int> fordJohnsonVector(std::vector<int>& input);
    std::deque<int>  fordJohnsonDeque(std::deque<int>& input);
    
    unsigned int jacobsthal(unsigned int n);

public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void parseInput(int argc, char **argv);
    void sortAndTime();
    
    void printContainers() const; 
};

#endif

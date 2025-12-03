/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:41:51 by lumartin          #+#    #+#             */
/*   Updated: 2025/12/03 16:29:21 by lumartin         ###   ########.fr       */
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

class PmergeMe
{
private:
    std::vector<int> vec;
    std::deque<int> deq;

    void mergeInsertVector(int left, int right);
    void mergeInsertDeque(int left, int right);
    void insertionSortVector(int left, int right);
    void insertionSortDeque(int left, int right);

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

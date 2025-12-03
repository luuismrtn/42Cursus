/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:41:48 by lumartin          #+#    #+#             */
/*   Updated: 2025/12/03 17:11:58 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : vec(other.vec), deq(other.deq) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        vec = other.vec;
        deq = other.deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseInput(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
    {
        std::istringstream iss(argv[i]);
        int number;
        if (!(iss >> number) || number < 0)
        {
            throw std::invalid_argument("Error: Invalid input. Only non-negative integers are allowed.");
        }
        vec.push_back(number);
        deq.push_back(number);
    }
}

void PmergeMe::printContainers() const
{
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::sortAndTime()
{
    struct timespec start, end;
    
    std::cout << "Before: ";
    printContainers();

    // --- VECTOR ---
    clock_gettime(CLOCK_MONOTONIC, &start);
    vec = fordJohnsonVector(vec);
    clock_gettime(CLOCK_MONOTONIC, &end);

    double vectorTime = (end.tv_sec - start.tv_sec) * 1000000.0 +
                        (end.tv_nsec - start.tv_nsec) / 1000000.0;

    // --- DEQUE ---
    clock_gettime(CLOCK_MONOTONIC, &start);
    deq = fordJohnsonDeque(deq);
    clock_gettime(CLOCK_MONOTONIC, &end);

    double dequeTime = (end.tv_sec - start.tv_sec) * 1000000.0 +
                       (end.tv_nsec - start.tv_nsec) / 1000000.0;

    std::cout << "After:  ";
    printContainers();

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : "
              << std::fixed << std::setprecision(5) << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque  : "
              << std::fixed << std::setprecision(5) << dequeTime << " us" << std::endl;
}

// ------------------------------------------------------------------------- //
// ------------------------- IMPLEMENTACIÓN VECTOR ------------------------- //
// ------------------------------------------------------------------------- //

unsigned int PmergeMe::jacobsthal(unsigned int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

std::vector<int> PmergeMe::fordJohnsonVector(std::vector<int> &input)
{
    if (input.size() <= 1)
        return input;

    bool hasStraggler = (input.size() % 2 != 0);
    int straggler = 0;
    if (hasStraggler)
    {
        straggler = input.back();
        input.pop_back();
    }

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < input.size(); i += 2)
    {
        if (input[i] > input[i + 1])
            pairs.push_back(std::make_pair(input[i + 1], input[i]));
        else
            pairs.push_back(std::make_pair(input[i], input[i + 1]));
    }

    std::vector<int> largerElements;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        largerElements.push_back(pairs[i].second);
    }

    std::vector<int> mainChain = fordJohnsonVector(largerElements);

    std::vector<int> pend;

    pend.resize(mainChain.size());
    for (size_t i = 0; i < mainChain.size(); ++i)
    {
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (pairs[j].second == mainChain[i])
            {
                pend[i] = pairs[j].first;
                pairs[j].second = -1;
                break;
            }
        }
    }

    mainChain.insert(mainChain.begin(), pend[0]);

    size_t nPend = pend.size();
    size_t insertedCount = 1;

    int jacobIndex = 3;

    while (insertedCount < nPend)
    {
        unsigned int nextJacob = jacobsthal(jacobIndex);

        unsigned int limit = nextJacob;
        if (limit > nPend)
            limit = nPend;

        for (unsigned int i = limit; i > 0; --i)
        {
            int currentPendIdx = i - 1;
            unsigned int prevJacob = jacobsthal(jacobIndex - 1);
            if (i <= prevJacob)
                continue;

            int valToInsert = pend[currentPendIdx];

            std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), valToInsert);
            mainChain.insert(pos, valToInsert);

            insertedCount++;
        }
        jacobIndex++;
    }

    if (hasStraggler)
    {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    return mainChain;
}

// ------------------------------------------------------------------------- //
// ------------------------- IMPLEMENTACIÓN DEQUE -------------------------- //
// ------------------------------------------------------------------------- //

std::deque<int> PmergeMe::fordJohnsonDeque(std::deque<int> &input)
{
    if (input.size() <= 1)
        return input;

    bool hasStraggler = (input.size() % 2 != 0);
    int straggler = 0;
    if (hasStraggler)
    {
        straggler = input.back();
        input.pop_back();
    }

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < input.size(); i += 2)
    {
        if (input[i] > input[i + 1])
            pairs.push_back(std::make_pair(input[i + 1], input[i]));
        else
            pairs.push_back(std::make_pair(input[i], input[i + 1]));
    }

    std::deque<int> largerElements;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        largerElements.push_back(pairs[i].second);
    }

    std::deque<int> mainChain = fordJohnsonDeque(largerElements);

    std::deque<int> pend;
    pend.resize(mainChain.size());

    for (size_t i = 0; i < mainChain.size(); ++i)
    {
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (pairs[j].second == mainChain[i])
            {
                pend[i] = pairs[j].first;
                pairs[j].second = -1;
                break;
            }
        }
    }

    mainChain.push_front(pend[0]);

    size_t nPend = pend.size();
    size_t insertedCount = 1;
    int jacobIndex = 3;

    while (insertedCount < nPend)
    {
        unsigned int nextJacob = jacobsthal(jacobIndex);
        unsigned int limit = nextJacob;
        if (limit > nPend)
            limit = nPend;
        unsigned int prevJacob = jacobsthal(jacobIndex - 1);

        for (unsigned int i = limit; i > 0; --i)
        {
            if (i <= prevJacob)
                continue;

            int currentPendIdx = i - 1;
            int valToInsert = pend[currentPendIdx];

            std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), valToInsert);
            mainChain.insert(pos, valToInsert);
            insertedCount++;
        }
        jacobIndex++;
    }

    if (hasStraggler)
    {
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    return mainChain;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:41:48 by lumartin          #+#    #+#             */
/*   Updated: 2025/12/03 16:29:25 by lumartin         ###   ########.fr       */
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

void PmergeMe::sortAndTime()
{
    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);
    mergeInsertVector(0, vec.size() - 1);
    clock_gettime(CLOCK_MONOTONIC, &end);
    double vectorTime = (end.tv_sec - start.tv_sec) * 1000000.0 +
                        (end.tv_nsec - start.tv_nsec) / 100000.0;

    clock_gettime(CLOCK_MONOTONIC, &start);
    mergeInsertDeque(0, deq.size() - 1);
    clock_gettime(CLOCK_MONOTONIC, &end);
    double dequeTime = (end.tv_sec - start.tv_sec) * 1000000.0 +
                       (end.tv_nsec - start.tv_nsec) / 100000.0;

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : "
              << std::fixed << std::setprecision(5) << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque  : "
              << std::fixed << std::setprecision(5) << dequeTime << " us" << std::endl;
}

void PmergeMe::printContainers() const
{
    std::cout << "Vector: ";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Deque: ";
    for (size_t i = 0; i < deq.size(); ++i)
    {
        std::cout << deq[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::insertionSortVector(int left, int right)
{
    for (int i = left + 1; i <= right; ++i)
    {
        int key = vec[i];
        int j = i - 1;
        while (j >= left && vec[j] > key)
        {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = key;
    }
}

void PmergeMe::insertionSortDeque(int left, int right)
{
    for (int i = left + 1; i <= right; ++i)
    {
        int key = deq[i];
        int j = i - 1;
        while (j >= left && deq[j] > key)
        {
            deq[j + 1] = deq[j];
            --j;
        }
        deq[j + 1] = key;
    }
}

void PmergeMe::mergeInsertVector(int left, int right)
{
    if (right - left <= 10)
    {
        insertionSortVector(left, right);
        return;
    }
    int mid = left + (right - left) / 2;
    mergeInsertVector(left, mid);
    mergeInsertVector(mid + 1, right);

    std::vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right)
    {
        if (vec[i] <= vec[j])
        {
            temp[k++] = vec[i++];
        }
        else
        {
            temp[k++] = vec[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = vec[i++];
    }
    while (j <= right)
    {
        temp[k++] = vec[j++];
    }
    for (i = left, k = 0; i <= right; ++i, ++k)
    {
        vec[i] = temp[k];
    }
}

void PmergeMe::mergeInsertDeque(int left, int right)
{
    if (right - left <= 10)
    {
        insertionSortDeque(left, right);
        return;
    }
    int mid = left + (right - left) / 2;
    mergeInsertDeque(left, mid);
    mergeInsertDeque(mid + 1, right);

    std::deque<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right)
    {
        if (deq[i] <= deq[j])
        {
            temp[k++] = deq[i++];
        }
        else
        {
            temp[k++] = deq[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = deq[i++];
    }
    while (j <= right)
    {
        temp[k++] = deq[j++];
    }
    for (i = left, k = 0; i <= right; ++i, ++k)
    {
        deq[i] = temp[k];
    }
}

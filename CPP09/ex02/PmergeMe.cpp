/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 00:57:12 by malaamir          #+#    #+#             */
/*   Updated: 2026/02/19 02:08:27 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {} // default constructor
PmergeMe::PmergeMe(const PmergeMe &other) : vec(other.vec), deq(other.deq) {} // copy constructor
PmergeMe &PmergeMe::operator=(const PmergeMe &other) // copy assignment operator
{
	if (this != &other)
	{
		vec = other.vec;
		deq = other.deq;
	}
	return *this;
}
PmergeMe::~PmergeMe() {} // destructor


//Utils: jacobsthal numbers generator
// Returns specific indices: 1, 3, 2, 5, 4, 11... for optimized binary insertion
std::vector<int> PmergeMe::generateJacobsthal(size_t n) {
    std::vector<int> jacob;
    
    // Standard Jacobsthal numbers: 0, 1, 1, 3, 5, 11...
    jacob.push_back(1);
    jacob.push_back(3);

    // Generate indices
    while (jacob.back() < (int)n) {
        size_t last = jacob.size() - 1;
        jacob.push_back(jacob[last] + 2 * jacob[last - 1]);
    }

    std::vector<int> seq;
    size_t last_val = 1;
    
    // Build sequence: 3, 2 -> 5, 4 -> 11, 10...
    for (size_t i = 0; i < jacob.size(); ++i) {
        int current = jacob[i];
        if (current > (int)n) current = n;
        
        for (int k = current; k > (int)last_val; --k)
            seq.push_back(k); // Just push. No search needed.
            
        last_val = current;
    }
    return seq;
}

// =========================================================
//                 VECTOR IMPLEMENTATION
// =========================================================

void PmergeMe::sortVector()
{
    clock_t start = clock();
    fordJohnsonVector(vec);
    clock_t end = clock();
    double time = double(end - start) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : " << time << " us" << std::endl;
}

void PmergeMe::fordJohnsonVector(std::vector<int> &sequence) {
    if (sequence.size() <= 1) return;

    // 1. Handle Straggler
    int straggler = -1;
    bool has_straggler = false;
    if (sequence.size() % 2 != 0) {
        has_straggler = true;
        straggler = sequence.back();
        sequence.pop_back();
    }

    // 2. PAIRING (Store as Pairs to keep the link!)
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < sequence.size(); i += 2) {
        if (sequence[i] > sequence[i + 1])
            pairs.push_back(std::make_pair(sequence[i + 1], sequence[i])); // {Loser, Winner}
        else
            pairs.push_back(std::make_pair(sequence[i], sequence[i + 1]));
    }

    // 3. RECURSION (Sort the Winners)
    std::vector<int> winners;
    for (size_t i = 0; i < pairs.size(); ++i)
        winners.push_back(pairs[i].second);

    fordJohnsonVector(winners); // Recursive call on WINNERS

    // 4. REBUILD (Re-associate pairs after sort)
    std::vector<int> sorted_sequence = winners;
    std::vector<int> losers;

    // Put the first loser at the start (it's smaller than the first winner)
    for (size_t i = 0; i < pairs.size(); ++i) {
        if (pairs[i].second == sorted_sequence[0]) {
            sorted_sequence.insert(sorted_sequence.begin(), pairs[i].first);
            break; 
        }
    }

    // Collect the rest of the losers
    for (size_t i = 1; i < winners.size(); ++i) {
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (pairs[j].second == winners[i]) {
                losers.push_back(pairs[j].first);
                break;
            }
        }
    }

    // 5. INSERTION (Using Jacobsthal Order)
    // You MUST use the Jacobsthal generator here
    std::vector<int> order = generateJacobsthal(losers.size());
    
    for (size_t i = 0; i < order.size(); ++i) {
        int idx = order[i] - 1;
        if (idx < (int)losers.size()) {
            binaryInsertionVector(sorted_sequence, losers[idx]);
        }
    }

    // 6. Straggler
    if (has_straggler) {
        binaryInsertionVector(sorted_sequence, straggler);
    }

    sequence = sorted_sequence;
}

void PmergeMe::binaryInsertionVector(std::vector<int> &sorted, int value)
{
    std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(pos, value);
}

// =========================================================
//                 DEQUE IMPLEMENTATION
// =========================================================

void PmergeMe::sortDeque()
{
    clock_t start = clock();
    fordJohnsonDeque(deq);
    clock_t end = clock();
    double time = double(end - start) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque  : " << time << " us" << std::endl;
}
void PmergeMe::fordJohnsonDeque(std::deque<int> &sequence)
{
    if (sequence.size() <= 1)
        return;

    int straggler = -1;
    bool has_straggler = (sequence.size() % 2 != 0);
    if (has_straggler)
    {
        straggler = sequence.back();
        sequence.pop_back();
    }

    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < sequence.size(); i += 2)
    {
        if (sequence[i] > sequence[i + 1])
            pairs.push_back(std::make_pair(sequence[i + 1], sequence[i]));
        else
            pairs.push_back(std::make_pair(sequence[i], sequence[i + 1]));
    }

    std::deque<int> winners;
    for (size_t i = 0; i < pairs.size(); ++i)
        winners.push_back(pairs[i].second);

    fordJohnsonDeque(winners); // Recursive call

    std::deque<int> sorted_sequence = winners;
    std::deque<int> losers;

    for (size_t i = 0; i < pairs.size(); ++i)
    {
        if (pairs[i].second == sorted_sequence[0])
        {
            sorted_sequence.insert(sorted_sequence.begin(), pairs[i].first);
            break;
        }
    }

    for (size_t i = 1; i < winners.size(); ++i)
    {
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (pairs[j].second == winners[i])
            {
                losers.push_back(pairs[j].first);
                break;
            }
        }
    }

    std::vector<int> insert_order = generateJacobsthal(losers.size());

    for (size_t i = 0; i < insert_order.size(); ++i)
    {
        int index = insert_order[i] - 1;
        if (index >= (int)losers.size())
            continue;

        int value_to_insert = losers[index];
        binaryInsertionDeque(sorted_sequence, value_to_insert);
    }

    if (has_straggler)
    {
        binaryInsertionDeque(sorted_sequence, straggler);
    }

    sequence = sorted_sequence;
}

void PmergeMe::binaryInsertionDeque(std::deque<int> &sorted, int value)
{
    std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(pos, value);
}

// =========================================================
//                 MAIN EXECUTION
// =========================================================

void PmergeMe::processInput(int ac, char **av)
{
    // 1. Parsing
    for (int i = 1; i < ac; ++i)
    {
        std::string s = av[i];
        for (size_t j = 0; j < s.length(); ++j)
        {
            if (!isdigit(s[j]))
            {
                std::cerr << "Error" << std::endl;
                std::exit(1);
            }
        }
        long val = std::atol(s.c_str());
        if (val <= 0 || val > 2147483647)
        {
            std::cerr << "Error" << std::endl;
            std::exit(1);
        }
        vec.push_back(static_cast<int>(val));
        deq.push_back(static_cast<int>(val));
    }

    // 2. Print Unsorted
    std::cout << "Before: ";
    size_t limit = vec.size() > 5 ? 5 : vec.size();
    for (size_t i = 0; i < limit; ++i)
        std::cout << vec[i] << " ";
    if (vec.size() > 5)
        std::cout << "[...]";
    std::cout << std::endl;

    // 3. Sort & Time
    sortVector();
    sortDeque();

    // 4. Print Sorted
    std::cout << "After:  ";
    for (size_t i = 0; i < limit; ++i)
        std::cout << vec[i] << " ";
    if (vec.size() > 5)
        std::cout << "[...]";
    std::cout << std::endl;
}
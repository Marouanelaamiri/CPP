/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 00:57:17 by malaamir          #+#    #+#             */
/*   Updated: 2026/02/19 02:14:03 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <iomanip>

class PmergeMe
{
private:
	std::vector<int> vec;
	std::deque<int> deq;

	// vector
	void sortVector(); // main function to sort vector and time it
	void fordJohnsonVector(std::vector<int> &sequence); // recursive implementation of Ford-Johnson for vector
	void binaryInsertionVector(std::vector<int> &sorted, int value); // binary insertion for vector
	// deque
	void sortDeque();
	void fordJohnsonDeque(std::deque<int> &sequence);
	void binaryInsertionDeque(std::deque<int> &sorted, int value);

	// generate jacobsthal numbers up to n
	std::vector<int> generateJacobsthal(size_t size);

public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	void processInput(int ac, char **av);
};

#endif
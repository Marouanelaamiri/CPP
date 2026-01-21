/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:50:56 by malaamir          #+#    #+#             */
/*   Updated: 2026/01/21 15:19:02 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	std::srand(std::time(NULL));

	std::cout << "--- Test 1: Subject Example ---" << std::endl;
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest:  " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n--- Test 2: Performance (10,000 items) ---" << std::endl;
	try
	{
		std::vector<int> largeVec(10000);
		std::generate(largeVec.begin(), largeVec.end(), std::rand);

		// std::vector<int> largeVec;
		// for (int i = 0; i < 10000; ++i)
		// 	largeVec.push_back(std::rand());

		Span bigSpan(10000);
		bigSpan.addNumber(largeVec.begin(), largeVec.end());

		std::cout << "Shortest Span: " << bigSpan.shortestSpan() << std::endl;
		std::cout << "Longest Span:  " << bigSpan.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n--- Test 3: Overflow Edge Cases ---" << std::endl;
	try
	{
		Span spEdge(5);
		spEdge.addNumber(INT_MAX);
		spEdge.addNumber(INT_MIN);

		std::cout << "Max: " << INT_MAX << std::endl;
		std::cout << "Min: " << INT_MIN << std::endl;

		unsigned int res = spEdge.longestSpan();
		std::cout << "Calculated Distance: " << res << std::endl;

		if (res == 4294967295)
			std::cout << "Test Passed: Correctly handled full integer range." << std::endl;
		else
			std::cout << "Test Failed: Overflow or logic error." << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n--- Test 4: Iterator Compatibility (std::list) ---" << std::endl;
	try
	{
		std::list<int> myList;
		myList.push_back(20);
		myList.push_back(10);
		myList.push_back(40);
		myList.push_back(30);

		Span listSpan(10);
		listSpan.addNumber(myList.begin(), myList.end());

		std::cout << "Shortest Span: " << listSpan.shortestSpan() << std::endl;
		std::cout << "Longest Span:  " << listSpan.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
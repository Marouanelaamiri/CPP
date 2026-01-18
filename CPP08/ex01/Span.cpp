/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:51:21 by malaamir          #+#    #+#             */
/*   Updated: 2026/01/18 18:14:03 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N(0) {}
Span::Span(unsigned int n) : N(n) {}
Span::Span(const Span &other) : N(other.N), vec(other.vec) {}
Span &Span::operator=(const Span &others)
{
	if (this != &others)
	{
		N = others.N;
		vec = others.vec;
	}
	return (*this);
}

Span::~Span() {}

void Span::addNumber(int number)
{
	if (vec.size() >= N)
		throw std::exception();
	vec.push_back(number);
}

unsigned int Span::shortestSpan()
{
	if (vec.size() < 2)
		throw std::exception();
	std::vector<int> sortedVec = vec;
	std::sort(sortedVec.begin(), sortedVec.end());

	long minSpan = LONG_MAX;
	for (size_t i = 1; i < sortedVec.size(); ++i)
	{
		long val1 = static_cast<long>(sortedVec[i]);
		long val2 = static_cast<long>(sortedVec[i - 1]);

		long span = val1 - val2;
		if (span < minSpan)
			minSpan = span;
	}
	return static_cast<unsigned int>(minSpan);
}

unsigned int Span::longestSpan()
{
	if (vec.size() < 2)
		throw std::exception();
	std::vector<int>::iterator minval = std::min_element(vec.begin(), vec.end());
	std::vector<int>::iterator maxval = std::max_element(vec.begin(), vec.end());

	long max = static_cast<long>(*maxval);
	long min = static_cast<long>(*minval);
	long span = max - min;
	return static_cast<unsigned int>(span);
}
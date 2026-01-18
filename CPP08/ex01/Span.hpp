/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:51:11 by malaamir          #+#    #+#             */
/*   Updated: 2026/01/18 17:07:50 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <ctime>
#include <list>
#include <vector>
#include <exception>
#include <algorithm>
#include <climits>

class Span
{
private:
	unsigned int N;
	std::vector<int> vec;

public:
	Span();
	Span(unsigned int n);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void addNumber(int number);

	template <typename T>
	void addNumber(T begin, T end)
	{
		for (T it = begin; it != end; ++it)
		{
			if (vec.size() >= N)
				throw std::exception();
			vec.push_back(*it);
		}
	}

	unsigned int shortestSpan();
	unsigned int longestSpan();
};

#endif
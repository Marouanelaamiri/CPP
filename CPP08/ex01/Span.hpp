/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:51:11 by malaamir          #+#    #+#             */
/*   Updated: 2026/01/17 12:54:36 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
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

	int shortestSpan();
	int longestSpan();

	class SpanFullException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Span is full. Cannot add more numbers.";
		}
	};

	class NotEnoughNumbersException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Not enough numbers to calculate a span.";
		}
	};
};

#endif
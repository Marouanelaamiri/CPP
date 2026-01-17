/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:51:21 by malaamir          #+#    #+#             */
/*   Updated: 2026/01/17 12:55:54 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N(0) {}
Span::Span(unsigned int n) : N(n) {}
Span::Span(const Span &other) : N(other.N), vec(other.vec) {}
Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		N = other.N;
		vec = other.vec;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{

}

int shortestSpan()
{
	
}

int longestSpan()
{
	
}
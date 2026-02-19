/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 00:29:07 by malaamir          #+#    #+#             */
/*   Updated: 2026/02/19 00:50:36 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RPN.hpp"

RPN::RPN() {} // default constructor
RPN::~RPN() {} // destructor
RPN::RPN(const RPN &other) : operands(other.operands) {} // copy constructor
RPN &RPN::operator=(const RPN &other) // copy assignment operator
{
	if (this != &other)
		operands = other.operands;
	return *this;
}

bool RPN::isOperator(char c) const
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

void RPN::performOperation(char op)
{
	if(operands.size() < 2)
		throw std::runtime_error("Error: not enough operands for operation");
	int val2 = operands.top(); operands.pop();
	int val1 = operands.top(); operands.pop();
	int result = 0;
	
	switch (op)
	{
	case '+':
		result = val1 + val2;
		break;
	case '-':
		result = val1 - val2;
		break;
	case '*':
		result = val1 * val2;
		break;
	case '/':
		if (val2 == 0)
			throw std::runtime_error("Error: division by zero");
		result = val1 / val2;
		break;
	}
	operands.push(result);
}

void RPN::run(const std::string &expression)
{
	for (size_t i = 0; i < expression.length(); ++i)
	{
		char c = expression[i];
		if (std::isspace(c))
			continue;
		else if (std::isdigit(c))
			operands.push(c - '0'); // convert char digit to int
			// Subject constraint: numbers < 10.
            // This implies we handle single digits.
            // If the next char is also a digit, it might be > 9 (error per subject constraints logic).
            // For safety, we just take the single digit.
		else if (isOperator(c))
			performOperation(c);
		else
			throw std::runtime_error(std::string("Error: invalid character '"));
	}
	if (operands.size() != 1)
		throw std::runtime_error("Error: invalid RPN expression");
	
	std::cout << operands.top() << std::endl; // output the final result
	
}
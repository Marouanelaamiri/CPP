/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 00:29:19 by malaamir          #+#    #+#             */
/*   Updated: 2026/02/19 00:48:36 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <exception>
#include <cstdlib> // for atoi	

class RPN
{
	private:
		std::stack<int> operands; // stack to hold operands
		bool isOperator(char c) const; // helper to check if char is operator
		void performOperation(char op); // helper to perform operation on top two operands
	
	public:
		RPN(); // constructor
		~RPN(); // destructor
		RPN(const RPN &other); // copy constructor
		RPN &operator=(const RPN &other); // copy assignment operator

		void run (const std::string &expression); // main function to process RPN expression
};

#endif
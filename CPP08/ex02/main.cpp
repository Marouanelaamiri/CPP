/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:47:43 by malaamir          #+#    #+#             */
/*   Updated: 2026/01/21 15:45:08 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	std::cout << "----- Subject Test -----" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	// itearator test
	++it;
	--it;
	
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "----- std::list Comparison -----" << std::endl;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);

	std::cout << lst.back() << std::endl;
	lst.pop_back();
	std::cout << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator lit = lst.begin();
	std::list<int>::iterator lite = lst.end();

	// itearator test
	++lit;
	--lit;

	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}

	std::cout << "----- Const iterator -----" << std::endl;

	const MutantStack<int> cmstack = mstack;
	MutantStack<int>::const_iterator cit = cmstack.begin();
	MutantStack<int>::const_iterator cite = cmstack.end();

	// itearator test
	++cit;
	--cit;

	while (cit != cite)
	{
		std::cout << *cit << std::endl;
		++cit;
	}

	return 0;
}
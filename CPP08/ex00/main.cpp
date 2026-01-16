/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:04:46 by malaamir          #+#    #+#             */
/*   Updated: 2026/01/16 14:25:26 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);

	std::vector<int>::iterator res = easyfind(vec, 20);

	if (res == vec.end())
		std::cerr << "Error: element not found!" << std::endl;
	else
		std::cout << "found value: " << *res << std::endl;

	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(15);
	lst.push_back(25);
	
	std::list<int>::iterator lres = easyfind(lst, 5);
	
	if (lres == lst.end())
		std::cerr << "Error: element not found on list!" << std::endl;
	else
		std::cout << "found value in list: " << *lres << std::endl;
		
	return 0;
}
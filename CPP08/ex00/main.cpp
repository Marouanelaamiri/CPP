/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:04:46 by malaamir          #+#    #+#             */
/*   Updated: 2025/12/26 19:40:55 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::cout << "----- Testing with std::vector -----" << std::endl;
	{
		int array[] = {10, 20, 30, 40, 50};
		std::vector<int> vec(array , array + 5);
		try
		{
			std::vector<int>::iterator it = easyfind(vec, 30);
			std::cout << "Found: " << *it << std::endl;
		}
		catch (const NotFoundException& e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			std::vector<int>::iterator it = easyfind(vec, 60);
			std::cout << "Found: " << *it << std::endl;
		}
		catch (const NotFoundException& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\n----- Testing with std::list -----" << std::endl;
	{
		std::list<int> lst;
		lst.push_back(5);
		lst.push_back(15);
		lst.push_back(25);
		lst.push_back(35);
		
		try
		{
			std::list<int>::iterator it = easyfind(lst, 25);
			std::cout << "Found: " << *it << std::endl;
			// for (std::list<int>::iterator iter = lst.begin(); iter != lst.end(); ++iter)
			// 	std::cout << *iter << " " << std::endl;
		}
		catch (const NotFoundException& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "List contents after first search:" << std::endl;
		try
		{
			std::list<int>::iterator it = easyfind(lst, 100);
			std::cout << "Found: " << *it << std::endl;
			// for (std::list<int>::iterator iter = lst.begin(); iter != lst.end(); ++iter)
			// 	std::cout << *iter << " " << std::endl;
		}
		catch (const NotFoundException& e)
		{
			std::cout << e.what() << std::endl;	
		}
	}
}
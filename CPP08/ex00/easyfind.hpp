/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:05:03 by malaamir          #+#    #+#             */
/*   Updated: 2025/12/26 19:28:50 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <exception>
#include <iostream>
#include <vector>
#include <list>
#include <deque>

class NotFoundException : public std::exception
{
public:
    virtual const char* what() const throw()
    {
        return "Element not found";
    }
};

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator found = std::find(container.begin(), container.end(), value);
	if (found == container.end())
		throw NotFoundException();
	return found;
}
#endif
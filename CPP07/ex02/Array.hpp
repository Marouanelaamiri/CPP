/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:59:01 by malaamir          #+#    #+#             */
/*   Updated: 2025/12/18 17:16:21 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
private:
	T *data;
	unsigned int _size;

public:
	Array();
	Array(unsigned int n);
	Array(const Array &other);
	Array &operator=(const Array &other);
	~Array();

	T &operator[](unsigned int index);
	const T &operator[](unsigned int index) const;

	unsigned int size() const;
};

#include "Array.tpp"

#endif

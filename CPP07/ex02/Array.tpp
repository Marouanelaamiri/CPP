#include "Array.hpp"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:05:26 by malaamir          #+#    #+#             */
/*   Updated: 2025/12/15 15:17:27 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T>
Array<T>::Array() : data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) :_size(n)
{
	if (n > 0)
	{
		data = new T[n]();; //// The () initializes elements to default (0 for ints)
	}
	else
	{
		data = NULL;
	}
}

template <typename T>
Array<T>::Array(const Array& other) :_size(other._size)
{
	if (_size > 0)
	{
		data = new T[_size]; // allocate new memory
		for (unsigned int i = 0; i < _size; i++)
		{
			data[i] = other.data[i]; // copy values one by one
		}
	}
	else
	{
		data = NULL;
	}
}



template <typename T>
Array<T>::~Array() { delete[] data; }

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this == &other)
		return *this;
	if (data)
		delete[] data;

	_size = other._size; //
	if (_size > 0)
	{
		data = new T[_size];
		for(unsigned int i = 0; i < _size; i++)
		{
			data[i] = other.data[i];
		}
	}
	else
	{
		data = NULL;
	}
	return *this;
}


template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::exception();
	return data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::exception();
	return data[index];
}

template <typename T>
unsigned int Array<T>::size() const { return _size; }

#endif
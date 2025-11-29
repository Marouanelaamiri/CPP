/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:30:55 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/29 18:03:53 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer &other) { (void)other; }
Serializer &Serializer::operator=(const Serializer &other)
{
	(void(other));
	return *this;
}
Serializer::~Serializer() {}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);// Interpret the bits of the pointer as an integer
}
uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);// Interpret the bits of the integer as a pointer
}

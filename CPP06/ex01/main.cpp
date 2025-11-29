/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:47:56 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/29 18:05:43 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data data;
	data.num = 42;
	data.type = "an int";

	std::cout << "Original Object Address: " << &data << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	Data *ptrdata = Serializer::deserialize(raw);
	
	std::cout << "Deserialized Pointer:    " << ptrdata << std::endl;

	std::cout << "the num is: " << ptrdata->num << " and its type is: " << ptrdata->type << std::endl;
}

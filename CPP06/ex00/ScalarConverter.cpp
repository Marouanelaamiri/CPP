/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 14:32:57 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/29 16:55:46 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter &other){(void)other;}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}
ScalarConverter::~ScalarConverter(){}

void ScalarConverter::convert(std::string ls)
{
	double value = 0.0; // we use double so we dont lose data
	char *endptr = NULL ; // we use it as an offset for strtodouble
	
	// detect chars 
	if (ls.length() == 1 && !std::isdigit(ls[0]))
		value = static_cast<double>(ls[0]);
	else
	{
	//here we parse the number if it has any garbage value like this :(42xzf)
		value = std::strtod(ls.c_str(), &endptr);
	
	// we validate the number for float case , float number has to end with f and only f
	if(*endptr != '\0')
		if(std::string(endptr) != "f")
		{
			std::cout << "char: impossible" <<std::endl;
			std::cout << "int: impossible" <<std::endl;
			std::cout << "float: impossible" <<std::endl;
			std::cout << "double: impossible" <<std::endl;
			return;
		}
	}
	// we print char
	std::cout << "char : ";
	// we check limits of assci and NaN , inf 
	if(value != value || value < 0 || value > 127) // value != value detects NaN
		std::cout << "impossible";
	// we check if its a nonprintable
	else if (!std::isprint(static_cast<char>(value)))
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(value) << "'";
	std::cout << std::endl;
	
	// we print int
	
	std::cout << "int: ";
	// we check for NaN and inf , or overflow
	if (value != value || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(value);
	std::cout << std::endl ;
	
	// we print float
	
	std::cout << "float: " << std::fixed << std::setprecision(1);
	std::cout << static_cast<float>(value)<< "f" << std::endl;

	// we print double 

	std::cout << "double: " << std::fixed << std::setprecision(1);
	std::cout << value << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:01:10 by malaamir          #+#    #+#             */
/*   Updated: 2025/12/01 16:31:34 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
        ScalarConverter::convert(argv[1]); // we are using :: to access a static method , like namespace behavior
    else
        std::cout << "try: ./ScalarConverter + literal(10 ,a ,10.0f)" << std::endl;
    return 0;
}
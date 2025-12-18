/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:42:18 by malaamir          #+#    #+#             */
/*   Updated: 2025/12/18 15:52:36 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"



int main() {
    // 1. Without parentheses (Default Initialization)
    // This technically has an "indeterminate value" (garbage).
    // Note: Some modern compilers might zero it out anyway for safety, 
    // but the C++ standard says it is undefined.
    int *garbage = new int; 

    // 2. With parentheses (Value Initialization)
    // This GUARANTEES the value is 0.
    int * clean = new int(); 

    std::cout << "Pointer without (): " << *garbage << " (Might be garbage)" << std::endl;
    std::cout << "Pointer with ():    " << *clean <<   " (Guaranteed 0)" << std::endl;

    // Clean up
    delete garbage;
    delete clean;

    return 0;
}

// int main()
// {
//     std::cout << "---- Basic tests ----" << std::endl;

//     Array<int> a(5);
//     for (unsigned int i = 0; i < a.size(); i++)
//         a[i] = i * 10;

//     std::cout << "Array a contents:" << std::endl;
//     for (unsigned int i = 0; i < a.size(); i++)
//         std::cout << "a[" << i << "] = " << a[i] << std::endl;

//     std::cout << "\n---- Copy constructor ----" << std::endl;
//     Array<int> b(a);

//     std::cout << "Array b contents (copy of a):" << std::endl;
//     for (unsigned int i = 0; i < b.size(); i++)
//         std::cout << "b[" << i << "] = " << b[i] << std::endl;

//     std::cout << "\n---- Assignment operator ----" << std::endl;
//     Array<int> c;
//     c = a;

//     std::cout << "Array c contents (copy of a):" << std::endl;
//     for (unsigned int i = 0; i < c.size(); i++)
//         std::cout << "c[" << i << "] = " << c[i] << std::endl;

//     std::cout << "\n---- Bounds checking ----" << std::endl;
//     try 
//     {
//         std::cout << a[99] << std::endl;
//     }
//     catch (std::exception &e) 
//     {
//         std::cout << "Exception caught: " << e.what() << std::endl;
//     }

//     std::cout << "\n---- String Array ----" << std::endl;
//     Array<std::string> s(3);
//     s[0] = "Hello";
//     s[1] = "World";
//     s[2] = "!!";

//     for (unsigned int i = 0; i < s.size(); i++)
//         std::cout << "s[" << i << "] = " << s[i] << std::endl;

//     return 0;
// }

// // #include <iostream>
// // #include <cstdlib>
// // #include <ctime>
// // #include "Array.hpp"

// // #define MAX_VAL 750
// // int main(int, char **)
// // {
// // 	Array<int> numbers(MAX_VAL);
// // 	int *mirror = new int[MAX_VAL];
// // 	srand(time(NULL));
// // 	for (int i = 0; i < MAX_VAL; i++)
// // 	{
// // 		const int value = rand();
// // 		numbers[i] = value;
// // 		mirror[i] = value;
// // 	}
// // 	// SCOPE
// // 	{
// // 		Array<int> tmp = numbers;
// // 		Array<int> test(tmp);
// // 	}

// // 	for (int i = 0; i < MAX_VAL; i++)
// // 	{
// // 		if (mirror[i] != numbers[i])
// // 		{
// // 			std::cerr << "didn't save the same value!!" << std::endl;
// // 			return 1;
// // 		}
// // 	}
// // 	try
// // 	{
// // 		numbers[-2] = 0;
// // 	}
// // 	catch (const std::exception &e)
// // 	{
// // 		std::cerr << e.what() << '\n';
// // 	}
// // 	try
// // 	{
// // 		numbers[MAX_VAL] = 0;
// // 	}
// // 	catch (const std::exception &e)
// // 	{
// // 		std::cerr << e.what() << '\n';
// // 	}

// // 	for (int i = 0; i < MAX_VAL; i++)
// // 	{
// // 		numbers[i] = rand();
// // 	}
// // 	delete[] mirror; //
// // 	return 0;
// // }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 18:25:55 by malaamiri         #+#    #+#             */
/*   Updated: 2025/12/18 17:16:25 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

// class Awesome
// {
// public:
//     Awesome(void) : _n(42) { return; } // Default value 42
//     int get(void) const { return this->_n; }
// private:
//     int _n;
// };

// // Stream operator for Awesome
// std::ostream & operator<<(std::ostream & o, Awesome const & rhs) {
//     o << rhs.get();
//     return o;
// }

// // A GENERIC print function template
// template<typename T>
// void print(T const & x) {
//     std::cout << x << std::endl;
//     return;
// }

// int main() {
//     // 1. Test with primitive int array
//     int tab[] = { 0, 1, 2, 3, 4 };
//     // Call iter with the 'print' template instantiated for int
//     iter(tab, 5, print<int>);

//     // 2. Test with complex Awesome array
//     Awesome tab2[5]; // Creates 5 Awesome objects (all 42)
//     // Call iter with the 'print' template instantiated for Awesome
//     iter(tab2, 5, print<Awesome>);

//     return 0;
// }

// TEST FUNCTION 1: Takes Non-Const Reference (Modifies the value)
void addOne(int &n)
{
	n++;
}

// TEST FUNCTION 2: Takes Const Reference (Only reads the value)
void printInt(const int &n)
{
	std::cout << n << " ";
}
template <typename T_type>
void printAny(const T_type &value)
{
	std::cout << value << " ";
}

int main()
{
	std::cout << "=== TEST 1: Int Array (Modification) ===" << std::endl;
	int arr[] = {1, 2, 3, 4, 5};

	std::cout << "Original: ";
	::iter(arr, 5, printInt); // Context: Mutable array, Read-only function
	std::cout << std::endl;

	// Apply modification
	::iter(arr, 5, addOne); // Context: Mutable array, Modifying function

	std::cout << "Modified: ";
	::iter(arr, 5, printInt);
	std::cout << std::endl;

	std::cout << "\n=== TEST 2: Const Int Array (Read-Only) ===" << std::endl;
	const int c_arr[] = {10, 20, 30};

	std::cout << "Values: ";
	// Context: Const array, Read-only function
	// If your template was wrong, this line would fail to compile.
	::iter(c_arr, 3, printInt);
	std::cout << std::endl;

	// this wont compile because c_arr is const
	// ::iter(c_arr, 3, addOne);
	// std::cout << std::endl;

	// std::cout << "Modified: ";
	// ::iter(arr, 3, printInt);
	// std::cout << std::endl;

	std::cout << "\n=== TEST 3: Const String Array (Read-Only) ===" << std::endl;

	const std::string str_arr[] = {"Hello", "World", "!"};
	std::cout << "Values: ";
	::iter(str_arr, 3, printAny<std::string>);
	std::cout << std::endl;

	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:17:54 by malaamiri         #+#    #+#             */
/*   Updated: 2025/12/15 13:26:49 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

class Awesome
{
public:
	Awesome(void) : _n(0) {} // Default constructor
	Awesome(int n) : _n(n) {} // Parameterized constructor

	Awesome &operator=(Awesome &a)
	{
		_n = a._n;
		return *this;
	}

	bool operator==(Awesome const &rhs) const { return (this->_n == rhs._n); }
	bool operator!=(Awesome const &rhs) const { return (this->_n != rhs._n); }
	// bool operator>(Awesome const &rhs) const { return (this->_n > rhs._n); }
	bool operator<(Awesome const &rhs) const { return (this->_n < rhs._n); }
	bool operator>=(Awesome const &rhs) const { return (this->_n >= rhs._n); }
	bool operator<=(Awesome const &rhs) const { return (this->_n <= rhs._n); }

	int get_n() const { return _n; }

private:
	int _n;
};

std::ostream &operator<<(std::ostream &o, const Awesome &a)
{
	o << a.get_n();
	return o;
}

//Why this class? Standard types like int have built-in comparison logic.
//This Awesome class forces your template to use the operator> and operator<
//defined inside the class. If your template was hardcoded or incorrect,
//this code would fail to compile.

int main(void)
{
	Awesome a(2), b(4);
	std::cout << "Before swap: " << a << " " << b << std::endl; // Expected: 2 4
	::swap(a, b);												// Swaps internal values (a becomes 4, b becomes 2)
	std::cout << "After swap: " << a << " " << b << std::endl;	// Expected: 4 2

	std::cout << "Max int: " << ::max(a, b) << std::endl; // Expected: 4 (since a is now 4)
	std::cout << "Min int: " << ::min(a, b) << std::endl; // Expected: 2 (since b is now 2)

	return (0);
}

// int main(void)
// {
// 	int a = 2;
// 	int b = 3;
// 	std::cout << "Initial values:" << std::endl;
// 	std::cout << "a = " << a << ", b = " << b << std::endl;
// 	// we are using :: to ensure we use OUR swap, not std::swap
// 	::swap(a, b);
// 	std::cout << "After swap:" << std::endl;
// 	std::cout << "a = " << a << ", b = " << b << std::endl;
// 	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
// 	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

// 	std::string c = "chaine1";
// 	std::string d = "chaine2";
// 	std::cout << "Initial values:" << std::endl;
// 	std::cout << "c = " << c << ", d = " << d << std::endl;
// 	::swap(c, d);
// 	std::cout << "After swap:" << std::endl;
// 	std::cout << "c = " << c << ", d = " << d << std::endl;
// 	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
// 	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

// 	float e = 4.2f;
// 	float f = 2.4f;
// 	std::cout << "Initial values:" << std::endl;
// 	std::cout << "e =" << e << ", f = " << f << std::endl;
// 	::swap(e, f);
// 	std::cout << "After swap:" << std::endl;
// 	std::cout << "e =" << e << ", f = " << f << std::endl;
// 	std::cout << "min( e, f ) = " << ::min(e, f) << std::endl;
// 	std::cout << "max( e, f ) = " << ::max(e, f) << std::endl;

// 	return 0;
// }
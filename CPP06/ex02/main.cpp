/*	 ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:26:54 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/30 17:28:00 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>	 // rand, srand
#include <ctime>	 // time
#include <exception> // std::exception

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	int i = std::rand() % 3;

	if (i == 0)
	{
		std::cout << "Generated: A" << std::endl;
		return new class A();
	}
	else if (i == 1)
	{
		std::cout << "Generated: B" << std::endl;
		return new class B();
	}
	else
	{
		std::cout << "Generated: C" << std::endl;
		return new class C();
	}
}
void identify(Base* p)
{
    // Attempt 1: Is it A?
    if (dynamic_cast<A*>(p) != NULL) 
    {
        std::cout << "A" << std::endl;
    }
    // Attempt 2: Is it B?
    else if (dynamic_cast<B*>(p) != NULL)
    {
        std::cout << "B" << std::endl;
    }
    // Attempt 3: Is it C?
    else if (dynamic_cast<C*>(p) != NULL)
    {
        std::cout << "C" << std::endl;
    }
}

// How it works internally:

// The program looks at the memory address p.

// It follows the vptr to the internal type info.

// It checks: "Does this type inherit from A?"

// If Yes: Returns the address.

// If No: Returns 0 (NULL).

void identify(Base& p)
{
    // Probe 1: Force it to be A
    try 
    {
        (void)dynamic_cast<A&>(p); // Cast to Reference
        std::cout << "A" << std::endl;
        return; // Success! We are done.
    }
    catch (std::exception &e) {
		// EMPTY: "It wasn't A. I don't care why. Just let me try B."
	} // It wasn't A. Swallow the error and continue.

    // Probe 2: Force it to be B
    try 
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (std::exception &e) {}

    // Probe 3: Force it to be C
    try 
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (std::exception &e) {}
}

// Why (void)? The compiler might warn you: "Value computed is not used." Casting to void silences this warning
// because we don't care about the result variable; we only care if the line succeeded or threw an exception.


int main()
{
	std::srand(std::time(NULL));

	for (int i = 0; i < 5; i++)
	{
		std::cout << "Test " << i + 1 << ":" << std::endl;

		Base *p = generate();

		std::cout << "  Pointer version: ";
		identify(p);

		std::cout << "  Reference version: ";
		identify(*p);

		delete p;
		std::cout << std::endl;
	}

	return 0;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:42:18 by malaamir          #+#    #+#             */
/*   Updated: 2025/12/15 15:50:34 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>  
#include "Array.hpp"

#define MAX_VAL 750

// --- AUXILIARY CLASS FOR COMPLEX TYPE TEST ---
class Awesome {
    public:
        Awesome() : _n(0) {}
        Awesome(int n) : _n(n) {}
        bool operator==(const Awesome& rhs) const { return (this->_n == rhs._n); }
        bool operator!=(const Awesome& rhs) const { return (this->_n != rhs._n); }
        int get() const { return _n; }
    private:
        int _n;
};
// Stream operator for printing
std::ostream& operator<<(std::ostream& o, const Awesome& a) {
    o << a.get();
    return o;
}

// --- MAIN TEST ---
int main(int, char**)
{
    std::cout << "=====================================================" << std::endl;
    std::cout << "       TEST 1: STANDARD MANDATORY INT TEST           " << std::endl;
    std::cout << "=====================================================" << std::endl;

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    
    // Seed random number generator
    srand(time(NULL));

    // 1. Fill arrays with random values
    std::cout << "[+] Filling array with " << MAX_VAL << " random values..." << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    // 2. SCOPE TEST (Deep Copy)
    std::cout << "[+] Testing Deep Copy (Scope Check)..." << std::endl;
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        // Destructors for 'tmp' and 'test' are called here. 
        // If shallow copy was used, 'numbers' would be corrupted.
    }

    // 3. Verify values match mirror
    std::cout << "[+] Verifying integrity of original array..." << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "[-] FAIL: didn't save the same value!!" << std::endl;
            delete [] mirror;
            return 1;
        }
    }
    std::cout << "[OK] Integrity check passed." << std::endl;


    // 4. Exception Tests
    std::cout << "\n[+] Testing Exceptions..." << std::endl;
    try {
        std::cout << "    - Accessing index -2: ";
        numbers[-2] = 0;
    } catch(const std::exception& e) {
        std::cout << "[OK] Caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "    - Accessing index MAX_VAL: ";
        numbers[MAX_VAL] = 0;
    } catch(const std::exception& e) {
        std::cout << "[OK] Caught: " << e.what() << std::endl;
    }

    // Clean up mirror
    delete [] mirror;


    std::cout << "\n=====================================================" << std::endl;
    std::cout << "       TEST 2: COMPLEX TYPES (Class Awesome)         " << std::endl;
    std::cout << "=====================================================" << std::endl;

    // Create Array of Objects
    Array<Awesome> awesomeArray(5);
    
    // Write values
    for (unsigned int i = 0; i < awesomeArray.size(); i++) {
        awesomeArray[i] = Awesome(i * 10);
    }

    // Read and verify
    std::cout << "[+] Values in Awesome Array: ";
    bool awesomeOk = true;
    for (unsigned int i = 0; i < awesomeArray.size(); i++) {
        std::cout << awesomeArray[i] << " ";
        if (awesomeArray[i].get() != (int)(i * 10)) awesomeOk = false;
    }
    std::cout << std::endl;
    
    if (awesomeOk) std::cout << "[OK] Complex Types work." << std::endl;
    else std::cerr << "[-] Complex Types FAILED." << std::endl;


    std::cout << "\n=====================================================" << std::endl;
    std::cout << "       TEST 3: CONST CORRECTNESS                     " << std::endl;
    std::cout << "=====================================================" << std::endl;

    try {
        // Create a const instance
        const Array<int> constNumbers(5);
        
        // This should use the "const T& operator[]"
        std::cout << "[+] Reading from const array (index 0): " << constNumbers[0] << std::endl;
        
        // Uncommenting the next line should cause a COMPILATION ERROR if written correctly
        // constNumbers[0] = 5; 
        
        std::cout << "[OK] Const access successful." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "[-] Error in const test: " << e.what() << std::endl;
    }
    
    // Empty array test
    Array<int> emptyArr;
    std::cout << "[+] Empty array size: " << emptyArr.size() << std::endl;

    return 0;
}

// #include <iostream>
// #include <cstdlib>
// #include <ctime>
// #include "Array.hpp"

// #define MAX_VAL 750
// int main(int, char **)
// {
// 	Array<int> numbers(MAX_VAL);
// 	int *mirror = new int[MAX_VAL];
// 	srand(time(NULL));
// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		const int value = rand();
// 		numbers[i] = value;
// 		mirror[i] = value;
// 	}
// 	// SCOPE
// 	{
// 		Array<int> tmp = numbers;
// 		Array<int> test(tmp);
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		if (mirror[i] != numbers[i])
// 		{
// 			std::cerr << "didn't save the same value!!" << std::endl;
// 			return 1;
// 		}
// 	}
// 	try
// 	{
// 		numbers[-2] = 0;
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	try
// 	{
// 		numbers[MAX_VAL] = 0;
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		numbers[i] = rand();
// 	}
// 	delete[] mirror; //
// 	return 0;
// }
#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <ctime>
#include <list>
#include <vector>
#include <exception>
#include <algorithm>
#include <climits>

class Span
{
private:
	unsigned int N;         // The maximum capacity (limit) of the container
	std::vector<int> vec;   // The contiguous memory engine that stores our integers

public:
	Span();                                 // Default constructor: Initializes an empty vessel
	Span(unsigned int n);                  // Parameterized constructor: Sets the storage limit
	Span(const Span &other);               // Copy constructor: Performs a deep copy of the vector
	Span &operator=(const Span &other);    // Assignment operator: Ensures safe deep-copying between existing objects
	~Span();                                // Destructor: Automatically releases heap memory via RAII

	void addNumber(int number);             // Adds a single integer; throws if vessel is full

	// Template must be in the header so the compiler can generate code for any iterator type
	template <typename T>
	void addNumber(T begin, T end)
	{
		// std::distance calculates steps between iterators; O(1) for vectors, O(N) for lists
		long distance = std::distance(begin, end);

		// Guard: Check if adding this range would exceed our capacity N
		if (vec.size() + distance > N)
			throw std::exception();

		// vec.insert is highly optimized: it reallocates once and copies the entire range
		vec.insert(vec.end(), begin, end);
	}

	unsigned int shortestSpan();            // Finds the smallest gap between any two numbers
	unsigned int longestSpan();             // Finds the gap between the absolute Min and Max
};

#endif

#include "Span.hpp"

// Default constructor: Initializes limit to 0
Span::Span() : N(0) {}

// Parameterized constructor: Reserves the capacity 'n'
Span::Span(unsigned int n) : N(n) {}

// Copy constructor: Copies the limit and clones the internal vector data (Deep Copy)
Span::Span(const Span &other) : N(other.N), vec(other.vec) {}

// Assignment operator: Guards against self-assignment and performs a deep copy
Span &Span::operator=(const Span &others)
{
	if (this != &others)
	{
		N = others.N;
		vec = others.vec; // Vector's operator= handles memory allocation and copying
	}
	return (*this);
}

// Destructor: Vector's internal memory is freed automatically when it goes out of scope
Span::~Span() {}

// Adds a single number; checks size first to prevent overflow of the limit N
void Span::addNumber(int number)
{
	if (vec.size() >= N)
		throw std::exception(); // Throws standard exception if we attempt to exceed N
	vec.push_back(number);      // Adds element to the end of the contiguous block
}

unsigned int Span::shortestSpan()
{
	// A span requires at least two points to exist; otherwise, throw
	if (vec.size() < 2)
		throw std::exception();

	// We copy the vector because sorting would destroy the user's original data order
	std::vector<int> sortedVec = vec;

	// Sort the copy: O(N log N). This puts the closest numbers next to each other
	std::sort(sortedVec.begin(), sortedVec.end());

	// Use long to prevent overflow during subtraction (e.g., INT_MAX - INT_MIN)
	long minSpan = LONG_MAX;

	// Iterate once through the sorted list: O(N)
	for (size_t i = 1; i < sortedVec.size(); ++i)
	{
		long val1 = static_cast<long>(sortedVec[i]);
		long val2 = static_cast<long>(sortedVec[i - 1]);

		long span = val1 - val2; // Calculate the gap between neighbors
		if (span < minSpan)
			minSpan = span;      // Update if a smaller gap is found
	}
	return static_cast<unsigned int>(minSpan); // Return as unsigned int per subject requirements
}

unsigned int Span::longestSpan()
{
	// Cannot have a span with fewer than two numbers
	if (vec.size() < 2)
		throw std::exception();

	// std::min/max_element are linear scans (O(N)); faster than sorting for this task
	std::vector<int>::iterator minval = std::min_element(vec.begin(), vec.end());
	std::vector<int>::iterator maxval = std::max_element(vec.begin(), vec.end());

	// Cast to long: Distance between INT_MAX and INT_MIN is ~4.2 billion, fits in long
	long max = static_cast<long>(*maxval);
	long min = static_cast<long>(*minval);
	long span = max - min; // The largest possible gap is always Max minus Min

	return static_cast<unsigned int>(span); // Result is naturally positive and returned as unsigned
}

#include "Span.hpp"

int main()
{
	// Seed the random number generator with current time for varied test data
	std::srand(std::time(NULL));

	// TEST 1: The standard test provided in the project PDF
	std::cout << "--- Test 1: Subject Example ---" << std::endl;
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest:  " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// TEST 2: Performance test using the Range Iterator template
	std::cout << "\n--- Test 2: Performance (10,000 items) ---" << std::endl;
	try
	{
		std::vector<int> largeVec;
		for (int i = 0; i < 10000; ++i)
			largeVec.push_back(std::rand()); // Fill a temporary vector with random noise

		Span bigSpan(10000);
		// This uses the template to add 10,000 items in a single, efficient call
		bigSpan.addNumber(largeVec.begin(), largeVec.end());

		std::cout << "Shortest Span: " << bigSpan.shortestSpan() << std::endl;
		std::cout << "Longest Span:  " << bigSpan.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// TEST 3: Testing the boundaries of the 'int' type
	std::cout << "\n--- Test 3: Overflow Edge Cases ---" << std::endl;
	try
	{
		Span spEdge(5);
		spEdge.addNumber(INT_MAX); // 2,147,483,647
		spEdge.addNumber(INT_MIN); // -2,147,483,648

		std::cout << "Max: " << INT_MAX << std::endl;
		std::cout << "Min: " << INT_MIN << std::endl;

		unsigned int res = spEdge.longestSpan();
		std::cout << "Calculated Distance: " << res << std::endl;

		// If result is > INT_MAX, it means we correctly calculated the 4 billion span
		if (res > static_cast<unsigned int>(INT_MAX))
			std::cout << "No overflow occurred in longestSpan calculation." << std::endl;
		else
			std::cout << "Overflow occurred!" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// TEST 4: Compatibility with non-contiguous containers
	std::cout << "\n--- Test 4: Iterator Compatibility (std::list) ---" << std::endl;
	try
	{
		std::list<int> myList; // Linked list (nodes scattered in memory)
		myList.push_back(20);
		myList.push_back(10);
		myList.push_back(40);
		myList.push_back(30);

		Span listSpan(10);
		std::cout << "Adding numbers from a std::list..." << std::endl;
		// Proves the template can walk through a list and insert into our vector
		listSpan.addNumber(myList.begin(), myList.end());

		std::cout << "Shortest Span: " << listSpan.shortestSpan() << std::endl;
		std::cout << "Longest Span:  " << listSpan.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0; // The Knight returns home; all memory is cleared by destructors
}
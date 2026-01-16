/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:05:03 by malaamir          #+#    #+#             */
/*   Updated: 2026/01/16 14:29:59 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <list>


// Returns an iterator. 
// If successful: returns iterator to value.
// If failed: returns iterator to end().
template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	return std::find(container.begin(), container.end(), value);
}
#endif

// container.begin() pushes the memory address of the first integer onto the stack.

// container.end() pushes the memory address of the "one-past-the-end" slot onto the stack.

// std::find enters a loop.

// It compares the value at the current address.

// It increments the address by 4 bytes (if int).

// If it hits the end address, it returns that end address to signal failure.




// The Algorithm: std::find (Under the Hood)
template<typename InputIterator, typename T>
InputIterator find(InputIterator first, InputIterator last, const T& val)
{
    // The Loop
    while (first != last) {
        if (*first == val)  // Dereference and Compare
            return first;   // Found it! Return the iterator (pointer)
        ++first;            // Move pointer to next address (sizeof(T))
    }
    return last; // Returned end() because we hit the limit
}

// The Iterators: Simplified Vector Iterator
template <typename T>
struct VectorIterator {
    T* _ptr; // The ONLY data member

    // Overloading operators to fake pointer behavior
    T& operator*() { return *_ptr; }           // Dereference
    VectorIterator& operator++() { _ptr++; return *this; } // Increment
    bool operator!=(const VectorIterator& rhs) { return _ptr != rhs._ptr; }
};

// Containers: std::vector (Under the Hood)
template <typename T>
class vector {
    T* _start;          // Pointer to the first element
    T* _finish;         // Pointer to the first EMPTY slot (size)
    T* _end_of_storage; // Pointer to the end of allocated RAM (capacity)
};

// The hidden struct inside std::list
template <typename T>
struct Node {
    T value;          // The actual data (e.g., int, string)
    Node* next;       // Pointer to the NEXT node
    Node* prev;       // Pointer to the PREVIOUS node
};

template <typename T>
class list {
    Node<T>* _head;   // Pointer to the first node
    Node<T>* _tail;   // Pointer to the last node
    size_t   _size;   // Tracks count (so .size() is fast)
};
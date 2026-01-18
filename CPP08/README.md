what are containers : Data structures that store and organize data(vector, list ,map ...)
Containers are template classes that manage collections of objects. They provide different performance characteristics and interfaces for various use cases.
what are Iterators : Objects that traverse container elements (like smart pointers)
what are algorithms : generic functions that work with iterators (find, sort, copy)

Container selection :
vector : dynamic array , random access , cache freindly
list : Linked lists , stable iterators, efficient due insertion/deletion
map : Sorted associative containers , logharithmic operations
stack : adapter containers, specific access patterns

Iterators Catefories :
input/output : single-pass , read/write operations.
forward : multi-pass , forward traversal.
bidrectional : forward and backward traversal.
random access : arithmetic operations, direct positioning .

Algorithm types :
non-modifying : find, count, search, equal.
modifying : copy, transform, replace, fill.
sorting : sort ...
set operations : merge, union , intersection.

### Sequence Containers

Store elements in a specific order.

### Associative Containers

Store elements in a sorted order based on keys.

### Container Adapters

Provide different interfaces to existing containers.

## Iterators

Iterators are objects that traverse container elements, acting like generalized pointers. They provide a uniform interface for accessing container elements.

begin(): Returns an iterator to the first element.

end(): Returns an iterator to the theoretical element AFTER the last element. (Never dereference end()).

Simplified Vector Iterator :
template <typename T>
struct VectorIterator {
    T* _ptr; // The ONLY data member

    // Overloading operators to fake pointer behavior
    T& operator*() { return *_ptr; }           // Dereference
    VectorIterator& operator++() { _ptr++; return *this; } // Increment
    bool operator!=(const VectorIterator& rhs) { return _ptr != rhs._ptr; }
};

### Algorithms

Algorithms are function templates that perform operations on containers through iterators. They’re generic and work with any compatible container.

### Function Objects and Predicates

Function objects (functors) are objects that can be called like functions. They're often used with algorithms.

### 1. Choose the Right Container

### Use vector for general-purpose arrays

std::vector<int> scores;
scores.reserve(expectedSize);  // Pre-allocate when size is known

### Use list for frequent insertion/deletion
std::list<Task> taskQueue;

### Use map for key-value lookups
std::map<std::string, Customer> customerDb;

### Use set for unique, sorted collections
std::set<int> uniqueIds;


Method (obj.run()): used when the object is a "Noun" (Car, User, Bank) that has many behaviors.

Functor (obj()): used when the object is a "Verb" (Comparator, Printer, Filter) wrapped in a class so it can store memory (state).

Functors are simply Objects wearing a "Function Mask".

By overloading operator(), you tell the compiler: "Treat this object as if it were a function."

The Choice: Named Function vs. Functor
You asked: "We can either create functions and call them on an object, or create a functor for that object?"

What is a Functor?
A Functor (or "Function Object") is simply a Class that behaves like a Function.

You create it by defining a class and overloading the operator() (the parenthesis operator). This allows you to "call" the object just like you would call a normal function.



"An iterator is an object that encapsulates a pointer to an element inside a container. It overloads operators like * (dereference) and ++ (increment) to provide a uniform interface for traversing different types of containers without exposing their underlying memory structure."

The Hierarchy:

Container: Holds the data (std::vector).

Iterator: Points to the data (std::vector::iterator).

Algorithm: Manipulates the data using the iterator (std::find).


std::vector (The Array)
Concept: A smart array that resizes itself. It is the default container you should use 90% of the time.

Memory: One single block of contiguous memory on the Heap.

Key Feature: Pointer Arithmetic works. &v[1] is exactly &v[0] + sizeof(T).


std::list (The Chain)
Concept: A Doubly Linked List. Every element is a separate object on the Heap.

Memory: Scattered allocations linked by next and prev pointers.

Key Feature: Stability. Inserting or deleting an element never invalidates pointers to other elements, because the other nodes don't move in memory.

std::map (The Tree)Concept: A dictionary (Key-Value pairs). It keeps elements Sorted by Key automatically.Memory: A Tree structure (specifically a Red-Black Tree).Key Feature: Search Speed. Finding an element takes $O(\log N)$ time (Binary Search steps), which is much faster than a linear scan $O(N)$ for huge datasets.

std::stack (The Wrapper)
Concept: LIFO (Last In, First Out). Think of a stack of plates. You can only touch the top one.

Memory: It doesn't have its own memory logic. It wraps another container (default: std::deque).

Key Feature: Restricted Interface. It deliberately hides iterators. No begin(), no end(), no [].

I want to access the 1000th element instantly. -> Use vector.

I need to delete elements from the middle while iterating. -> Use list.

I need to find a User by their Name. -> Use map.

I need to ensure data is processed strictly in reverse order of arrival. -> Use stack.



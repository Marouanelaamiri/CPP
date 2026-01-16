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


std::vector
std::list
std::map
std::stack
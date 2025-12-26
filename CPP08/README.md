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



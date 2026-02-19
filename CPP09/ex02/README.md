Steps of the Algorithm
Pairing and Sorting: Pair up consecutive indices and sort each pair in ascending order.
Merge Sort Pairs: Sort these pairs based on the first (larger) value in each pair.
Generate Sequences: Create a sorted sequence with the larger numbers from each pair and another sequence with the smaller ones.
Jacobsthal Sequence: Generate a Jacobsthal sequence for insertion.
Insertion Sort: Use the Jacobsthal sequence to perform insertion sort.



The Order Matters (Jacobsthal Sequence):
Instead of inserting Losers one by one, we insert them in a specific order defined by Jacobsthal Numbers (1, 3, 5, 11, 21...). This order optimizes Binary Search.

Why? It maximizes the efficiency of std::lower_bound (Binary Search) by picking elements that split the remaining search space effectively. // need understanding



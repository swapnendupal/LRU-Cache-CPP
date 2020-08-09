# LRU-Cache-CPP

Implementation of LRU (Least Recently Used) cache using the Standard Template Library (STL) of C++.

## Requirements:
  * G++ (or GCC) compiler
  * STL Library
  * List and HashMap

## Idea:

Cache memory is the one closest to CPU as it has the lowest access time (higher speed), but at the same time its cost is very high and the size is very low. Cache memory can be implemented using various processes and Least Recently Used (LRU) is one of them. 
To get the idea about LRU cache, visit https://en.wikipedia.org/wiki/Cache_replacement_policies#LRU.

To make the best use of cache, one has to make sure that search, insert and delete operations for it are very fast (O(1) -- constant time). 
Thus, the data structures that can be used to implement LRU are **Doubly Linked List (DLL)** and **Hash Map**. 
DLL supports delete operation in constant time, unlike Singly Linked List. The hash maps supports search, insert, delete at constant time and hence, are used to store the addresses of the keys. 

For further referece, watch this video **Implement LRU Cache** - https://www.youtube.com/watch?v=akFRa58Svug



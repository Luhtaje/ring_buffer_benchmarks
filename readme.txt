Sub directories of this  contains benchmark programs to test the thesis project of a dynamic ring buffer in C++.
The benchmarks are meant to test heap memory usage with valgrind massif and some performance bencmark tool. (To be decided)
These benchmarks have been written to primarily test the time performance of these containers and secondarily the memory usage will be logged and analyzed.
The topics have been chosen by listing the pro's and con's of each container and picking up the most common characteristics. 
In other words the benchmarks test what the existing containers are good or bad in.

Current topics to test the containers are:
Accessing elements: Random access

Buffer memory footprint: Empty buffer, large buffer.

Buffer reallocation: Logarithmic test for size.


DISADVANTAGES OF VECTOR:
- Reallocation, if buffer gets full a reallocation is needed.
- Insertions/Deletions to middle of vector can take super long amounts of time in larger containers.

DISADVANTAGES OF DEQUE:
- Due to not having continguous memory, iterating might not be that cache friendly.
- Slightly larger overhead.
- Insertions/ deletions in middle. (Somewhat faster than vector.)

DISADVANTAGES OF LIST:
- Memory overhead, every element needs additional linkage (prev and next pointer) information.
- Non-contiguous memory, slower to iterate through 
- No random access.
- Slighty more complex API?
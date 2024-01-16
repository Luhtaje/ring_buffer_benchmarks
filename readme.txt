Sub directories of this  contains benchmark programs to test the thesis project of a dynamic ring buffer in C++.
The benchmarks are meant to test heap memory usage with valgrind massif and time performance with google benchmark.
These benchmarks have been written to primarily test the time performance of these containers and secondarily the memory usage will be logged and analyzed.
The topics have been chosen by listing the pro's and con's of each container and picking up the most common characteristics. 
In other words the benchmarks test what the existing containers are good or bad in.


# Project Build Guide

This project utilizes CMake and includes git submodules. Follow these steps to build and run the project:

1. **Clone the Project and Update Submodules:**

   ```
   git clone --recurse-submodules <repository-url>
   ```

   Alternatively, you can initialize and uptade the submodules separately
   
   ```
   git submodule init
   git submodule update
   ```

Currently the build process covers only the dirty_tests

2. **CD into dirty_tests**
   ```
   cd ring_buffer_benchmarks/dirty_tests
   ```

3. **Get the ring_buffer header**

    To enfore that the tests are ran with latest ringbuffer, the header is not included in this repository automatically.
    You can find the header file in https://github.com/Luhtaje/dynamic

    copy the ring_buffer.hpp to

    ```
    ring_buffer_benchmarks/dirty_tests/include/
    ```


4. **Build the project**

    ```
    mkdir build
    cd build
    cmake ..
    (make)
    ```

Build outputs to /tests

5. **RunTests**

    ```
    cd tests
    ./dirty_benchmark
    ```


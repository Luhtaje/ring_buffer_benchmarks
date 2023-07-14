# Start from a base image with the necessary build tools
FROM ubuntu:20.04

# Install necessary build tools
RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y \
    build-essential \
    valgrind \
    && rm -rf /var/lib/apt/lists/*

# Create a directory to hold the source code
WORKDIR /src

# Copy all files in the current directory on the host
# into the /src directory in the image
COPY . .

# Build the benchmark program
RUN g++ -std=c++14 -g -o element_access_ringbuffer element_access_ringbuffer.cpp
RUN g++ -std=c++14 -g -o element_access_vector element_access_vector.cpp
RUN g++ -std=c++14 -g -o element_access_deque element_access_deque.cpp
RUN g++ -std=c++14 -g -o element_access_list element_access_list.cpp

# Default command to run the benchmark under Valgrind and output results to a file
CMD valgrind --tool=massif --massif-out-file=/output/massif.out ./element_access_ringbuffer && \
valgrind --tool=massif --massif-out-file=/output/massif.out.vector ./element_access_vector && \
valgrind --tool=massif --massif-out-file=/output/massif.out.vector ./element_access_deque && \
valgrind --tool=massif --massif-out-file=/output/massif.out.vector ./element_access_list
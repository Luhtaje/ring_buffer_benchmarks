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
RUN g++ -std=c++14 -g -O3 -o buffer buffer.cpp
RUN g++ -std=c++14 -g -O3 -o vector vector.cpp
RUN g++ -std=c++14 -g -O3 -o list list.cpp
RUN g++ -std=c++14 -g -O3 -o deque deque.cpp


# Default command to run the benchmark under Valgrind and output results to a file
CMD valgrind --tool=massif --massif-out-file=/output/massif.out.memory.empty.buffer ./buffer && \
valgrind --tool=massif --massif-out-file=/output/massif.out.memory.empty.vector ./vector && \
valgrind --tool=massif --massif-out-file=/output/massif.out.memory.empty.list ./list && \
valgrind --tool=massif --massif-out-file=/output/massif.out.memory.empty.deque ./deque

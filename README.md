# VirtualMemory

## Table of Contents
- [Introduction](#introduction)
- [Build and Run](#build-and-run)
- [Possible Output](#possible-output)
- [How does this work](#how-does-this-work)

## Introduction
This project benchmarks memory access patterns using large vectors. It measures sequential and random access times for big vector sizes (1GB to 4GB), helping to illustrate the effect of memory swapping on performance.

## Build and Run
To clone and run this project, ensure you have [Git](https://git-scm.com) and [CMake](https://cmake.org/) installed. Use the following commands:

```bash
# Clone this repository
$ git clone https://github.com/Hayk10002/VirtualMemory

# Navigate to the repository
$ cd VirtualMemory

# Generate build files
$ cmake -DCMAKE_BUILD_TYPE=Release -S . -B build

# Build the project
$ cmake --build build --config Release

# Run the executable with the desired vector size
$ your/path/to/exe/main.exe {iteration_count} {vector_max_size}
# Example: .../main.exe 5000000 1073741824 <- 1024 * 1024 * 1024
```

## Possible Output
Example output for inputs 5000000 1073741824:

```
Vector     size:   67.11M elements
Sequential time:     14ms
Random     time:    156ms

Vector     size:  134.22M elements
Sequential time:     13ms
Random     time:    177ms

Vector     size:  201.33M elements
Sequential time:     13ms
Random     time:    171ms

Vector     size:  268.44M elements
Sequential time:     13ms
Random     time:    174ms

Vector     size:  335.54M elements
Sequential time:     13ms
Random     time:    177ms

Vector     size:  402.65M elements
Sequential time:     13ms
Random     time:    205ms

Vector     size:  469.76M elements
Sequential time:     13ms
Random     time:    204ms

Vector     size:  536.87M elements
Sequential time:     11ms
Random     time:    214ms

Vector     size:  603.98M elements
Sequential time:     13ms
Random     time:    268ms

Vector     size:  671.09M elements
Sequential time:     14ms
Random     time:    238ms

Vector     size:  738.20M elements
Sequential time:     13ms
Random     time:    254ms

Vector     size:  805.31M elements
Sequential time:     14ms
Random     time:    250ms

Vector     size:  872.42M elements
Sequential time:     13ms
Random     time:    269ms

Vector     size:  939.52M elements
Sequential time:     13ms
Random     time:    268ms

Vector     size: 1006.63M elements
Sequential time:     12ms
Random     time:    278ms

Vector     size: 1073.74M elements
Sequential time:     13ms
Random     time:    273ms
```

## How does this work
The benchmark results show that sequential access times remain consistently low across all tested vector sizes, while random access times increase as the vector size grows. Notably, random access time jumps significantly at around 400M elements (from ~177ms to ~205ms) and again at 600M elements (from ~214ms to ~268ms). These jumps indicate the point where the system starts swapping memory to disk due to insufficient physical RAM, causing slower access times. This demonstrates how random access performance is affected by memory swapping, while sequential access remains largely unaffected.
# cpp-memory-pool

A simple custom memory pool allocator written in C++ to understand how dynamic memory allocation works under the hood.

This project implements two versions:

- **memory_pool_v1.cpp** — Manual allocation and deallocation using raw pointers.
- **memory_pool_v2.cpp** — RAII-based allocator using `std::unique_ptr` and a custom deleter.

---

# What Is a Memory Pool?

A memory pool is a technique where a large block of memory is allocated once and then divided into smaller chunks as needed.

Instead of repeatedly calling:

```cpp
new
delete
```

the program requests memory from a preallocated buffer.

Conceptually:

```text
+--------------------------------------------------+
|                  Memory Pool                     |
+--------------------------------------------------+

allocate(64)  -> returns first free chunk
allocate(32)  -> returns next free chunk
deallocate()  -> returns chunk to pool
```

---

# Why Use a Memory Pool?

Traditional heap allocations can be expensive because the allocator must:

- Search for free memory
- Maintain allocation metadata
- Interact with the operating system
- Handle fragmentation

A memory pool reduces this overhead by reusing memory that has already been reserved.

Benefits:

- Faster allocations
- Reduced heap fragmentation
- Predictable memory usage
- Useful in game engines, embedded systems, and high-performance applications

---

# Features

## Version 1

- Preallocated memory buffer
- Free-list allocator
- Out-of-memory detection
- Double-free detection
- Manual deallocation

Example:

```cpp
MemoryPool pool(1024);

void* ptr = pool.allocate(128);

pool.deallocate(ptr);
```

---

## Version 2

Uses modern C++ RAII.

Memory is automatically returned to the pool when the smart pointer goes out of scope.

Example:

```cpp
MemoryPool pool(1024);

{
    auto ptr = pool.allocate(128);
}
```

No explicit deallocation required.

---

# Internal Design

Each allocation contains a small header before the user memory:

```text
+--------------+------------------+
| BlockHeader  | User Memory      |
+--------------+------------------+
               ^
               Returned pointer
```

The header stores information such as:

- Block size
- Allocation state
- Links used by the free list

The allocator maintains a linked list of available blocks.

---

# Building

Compile Version 1:

```bash
g++ -std=c++20 memory_pool_v1.cpp -o pool_v1
```

Run:

```bash
./pool_v1
```

Compile Version 2:

```bash
g++ -std=c++20 memory_pool_v2.cpp -o pool_v2
```

Run:

```bash
./pool_v2
```

---

# Benchmark

Test Machine:

- Windows 11
- g++ (C++20)
- Release build (-O2)

Benchmark:

100,000 allocations of 64-byte blocks.

| Allocator   | Time |
| ----------- | ---- |
| new/delete  | TBD  |
| Memory Pool | TBD  |

To reproduce:

```cpp
const int N = 100000;

for (int i = 0; i < N; i++)
{
    void* p = pool.allocate(64);
    pool.deallocate(p);
}
```

Replace the table values with your actual benchmark measurements.

---

# Future Improvements

- Block splitting
- Block coalescing
- Better alignment support
- Thread safety
- STL allocator compatibility
- Performance benchmarking suite

---

# Learning Objectives

This project was built to practice:

- Heap memory management
- Pointer arithmetic
- Linked lists
- RAII
- Smart pointers
- Custom deleters
- Memory allocator design

It is intended as an educational project rather than a production-ready allocator.

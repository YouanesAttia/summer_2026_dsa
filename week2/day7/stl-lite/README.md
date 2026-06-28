# STL-Lite

A lightweight implementation of several C++ Standard Template Library (STL) containers for learning data structures and algorithms.

## Containers

### `Vector`

A dynamic array that automatically resizes as elements are added.

Supported operations include:

- `push_back`
- `pop_back`
- `operator[]`
- `size`
- `empty`

---

### `Stack`

A Last-In, First-Out (LIFO) container built on top of the custom `Vector`.

Supported operations include:

- `push`
- `pop`
- `top`
- `size`
- `empty`

---

### `Queue`

A First-In, First-Out (FIFO) container implemented using the custom `DoublyLinkedList`.

Supported operations include:

- `push`
- `pop`
- `front`
- `back`
- `size`
- `empty`

---

### `DoublyLinkedList`

A doubly linked list where each node stores pointers to both the previous and next node.

Supported operations include:

- `push_front`
- `push_back`
- `pop_front`
- `pop_back`
- `find`
- `insert_at`
- `delete_at`
- `hasCycle`
- `makeCycle`

---

## Time Complexity

| Operation       |       Vector       |  Stack   |  Queue   |      DoublyLinkedList      |
| --------------- | :----------------: | :------: | :------: | :------------------------: |
| Access by index |      **O(1)**      |    —     |    —     |          **O(n)**          |
| Push front      |      **O(n)**      |    —     |    —     |          **O(1)**          |
| Push back       | **Amortized O(1)** | **O(1)** | **O(1)** |          **O(n)**          |
| Pop front       |      **O(n)**      |    —     | **O(1)** |          **O(1)**          |
| Pop back        |      **O(1)**      | **O(1)** |    —     |          **O(n)**          |
| Find            |      **O(n)**      |    —     |    —     |          **O(n)**          |
| Insert at index |      **O(n)**      |    —     |    —     |          **O(n)**          |
| Delete at index |      **O(n)**      |    —     |    —     |          **O(n)**          |
| Front           |         —          |    —     | **O(1)** |          **O(1)**          |
| Back            |         —          |    —     | **O(1)** |          **O(n)**          |
| Top             |         —          | **O(1)** |    —     |             —              |
| Empty           |      **O(1)**      | **O(1)** | **O(1)** |          **O(1)**          |
| Size            |      **O(1)**      | **O(1)** | **O(1)** | **O(n)** _(unless stored)_ |

---

## Building

```bash
mkdir build
cd build

cmake ..
make
```

---

## Running Tests

Run all tests:

```bash
ctest
```

To display the output from failing tests:

```bash
ctest --output-on-failure
```

You can also run each test executable individually:

```bash
./test_vector
./test_stack
./test_queue
./test_ll
```

---

## Project Structure

```
stl-lite/
│
├── include/
│   ├── vector.hpp
│   ├── stack.hpp
│   ├── queue.hpp
│   └── linked_list.hpp
│
├── tests/
│   ├── test_vector.cpp
│   ├── test_stack.cpp
│   ├── test_queue.cpp
│   └── test_ll.cpp
│
├── CMakeLists.txt
└── README.md
```

---

## Requirements

- C++17 or later
- CMake 3.14+
- GoogleTest (automatically downloaded using `FetchContent`)

#include <iostream>
#include <vector>
#include <cstddef>
#include <cassert>

using namespace std;

class MemoryPool
{
private:
    struct Node
    {
        size_t size;
        Node *next;
    };
    char *buffer;
    size_t poolSize;
    Node *freeList;

public:
    MemoryPool(size_t bytes)
        : poolSize(bytes)
    {
        buffer = new char[poolSize];

        freeList = reinterpret_cast<Node *>(buffer);
        freeList->size = poolSize;
        freeList->next = nullptr;
    }

    ~MemoryPool()
    {
        delete[] buffer;
    }
    void *allocate(size_t bytes)
    {
        Node *prev = nullptr;
        Node *current = freeList;

        while (current)
        {
            if (current->size >= bytes + sizeof(Node))
            {
                char *allocatedMemory =
                    reinterpret_cast<char *>(current);

                size_t remaining =
                    current->size - bytes;

                Node *newBlock =
                    reinterpret_cast<Node *>(
                        allocatedMemory + bytes);

                newBlock->size = remaining;
                newBlock->next = current->next;

                if (prev)
                    prev->next = newBlock;
                else
                    freeList = newBlock;

                return allocatedMemory;
            }

            prev = current;
            current = current->next;
        }

        return nullptr;
    }

    void deallocate(void *ptr, size_t bytes)
    {
        if (!ptr)
            return;

        Node *block =
            reinterpret_cast<Node *>(ptr);

        block->size = bytes;
        block->next = freeList;

        freeList = block;
    }

    void printFreeList() const
    {
        const Node *current = freeList;

        while (current)
        {
            std::cout
                << "[size=" << current->size << "] -> ";

            current = current->next;
        }

        std::cout << "null\n";
    }
};

int main()
{
    MemoryPool pool(1024);

    void *a = pool.allocate(128);
    void *b = pool.allocate(256);

    std::cout << "After allocations:\n";
    pool.printFreeList();

    pool.deallocate(a, 128);

    std::cout << "After deallocation:\n";
    pool.printFreeList();

    if (b)
        std::cout << "Allocation successful\n";

    return 0;
}
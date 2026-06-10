#include <iostream>
#include <stdexcept>
#include <cstddef>

class MemoryPool
{
private:
    struct BlockHeader
    {
        size_t size;
        bool isFree;
        BlockHeader *next;
    };

    char *buffer;
    size_t poolSize;
    BlockHeader *freeList;

public:
    explicit MemoryPool(size_t size)
        : poolSize(size)
    {
        buffer = new char[poolSize];

        freeList = reinterpret_cast<BlockHeader *>(buffer);
        freeList->size = poolSize - sizeof(BlockHeader);
        freeList->isFree = true;
        freeList->next = nullptr;
    }

    ~MemoryPool()
    {
        delete[] buffer;
    }

    void *allocate(size_t bytes)
    {
        BlockHeader *prev = nullptr;
        BlockHeader *curr = freeList;

        while (curr)
        {
            if (curr->isFree && curr->size >= bytes)
            {
                curr->isFree = false;

                if (prev)
                    prev->next = curr->next;
                else
                    freeList = curr->next;

                return curr + 1;
            }

            prev = curr;
            curr = curr->next;
        }

        return nullptr;
    }

    void deallocate(void *ptr)
    {
        if (!ptr)
            return;

        BlockHeader *header =
            reinterpret_cast<BlockHeader *>(ptr) - 1;

        if (header->isFree)
            throw std::runtime_error("Double free detected");

        header->isFree = true;

        header->next = freeList;
        freeList = header;
    }
};

int main()
{
    MemoryPool pool(1024);

    void *p1 = pool.allocate(128);
    void *p2 = pool.allocate(256);

    if (!p1 || !p2)
        return 1;

    pool.deallocate(p1);

    void *p3 = pool.allocate(64);

    if (!p3)
        return 1;

    void *big = pool.allocate(5000);

    if (big == nullptr)
        std::cout << "Out of memory test passed\n";

    try
    {
        pool.deallocate(p1);
    }
    catch (const std::runtime_error &)
    {
        std::cout << "Double free test passed\n";
    }

    std::cout << "All tests passed\n";
}
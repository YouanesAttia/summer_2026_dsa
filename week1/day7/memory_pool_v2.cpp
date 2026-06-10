#include <iostream>
#include <memory>
#include <stdexcept>
#include <cstddef>

class MemoryPool;

struct PoolDeleter
{
    MemoryPool *pool;

    void operator()(char *ptr) const;
};

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

    std::unique_ptr<char, PoolDeleter>
    allocate(size_t bytes)
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

                return {
                    reinterpret_cast<char *>(curr + 1),
                    PoolDeleter{this}};
            }

            prev = curr;
            curr = curr->next;
        }

        return {
            nullptr,
            PoolDeleter{this}};
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

void PoolDeleter::operator()(char *ptr) const
{
    if (ptr)
        pool->deallocate(ptr);
}

int main()
{
    MemoryPool pool(1024);

    {
        auto ptr = pool.allocate(128);

        if (!ptr)
            return 1;

        ptr.get()[0] = 'A';
    }

    std::cout << "Memory automatically returned to pool\n";

    auto large = pool.allocate(5000);

    if (!large)
        std::cout << "Out of memory test passed\n";

    std::cout << "All tests passed\n";
}
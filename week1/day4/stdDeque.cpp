#include <iostream>
#include <deque>

int main()
{
    std::deque<int> dq;

    // Add 100 elements so we definitely have multiple blocks
    for (int i = 0; i < 100; ++i)
    {
        dq.push_back(i);
    }

    int *previous_address = nullptr;
    int elements_in_current_block = 0;
    int block_count = 1;

    std::cout << "Starting Block 1..." << std::endl;

    for (int i = 0; i < dq.size(); ++i)
    {
        int *current_address = &dq[i];

        // If this isn't the first element, check if it's next to the previous one
        if (previous_address != nullptr)
        {
            // In memory, the next 'int' should be exactly 1 'int-size' away
            if (current_address != (previous_address + 1))
            {
                // MEMORY JUMP DETECTED!
                std::cout << "  -> Block " << block_count << " had " << elements_in_current_block << " elements." << std::endl;
                block_count++;
                elements_in_current_block = 0;
                std::cout << "Starting Block " << block_count << "..." << std::endl;
            }
        }

        elements_in_current_block++;
        previous_address = current_address;
    }

    std::cout << "  -> Block " << block_count << " had " << elements_in_current_block << " elements." << std::endl;

    return 0;
}
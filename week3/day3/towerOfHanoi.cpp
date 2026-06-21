#include <iostream>

void towerOfHanoi(int n, int from, int aux, int to)
{
    if (n > 0)
    {
        towerOfHanoi(n - 1, from, to, aux);
        std::cout << "From " << from << " to " << to << std::endl;
        towerOfHanoi(n - 1, aux, from, to);
    }
}

int main()
{
    towerOfHanoi(3, 1, 2, 3);
}
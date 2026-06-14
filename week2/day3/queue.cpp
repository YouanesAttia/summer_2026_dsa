#include <iostream>
#include <stdexcept>

template <class T>
class Queue
{
private:
    int size;
    T *arr;
    int frontIndex;
    int rearIndex;
    int count;

public:
    Queue(int n = 10) : size(n), arr(new T[size]), frontIndex(-1), rearIndex(-1), count(0) {}

    ~Queue() { delete[] arr; }

    bool isempty() const
    {
        return count == 0;
    }

    bool isfull() const
    {
        return count == size;
    }

    int getcapacity() const
    {
        return size;
    }

    int getsize() const
    {
        return count;
    }

    void enqueue(const T &val)
    {
        if (!isfull())
        {
            rearIndex = ++rearIndex % size;
            arr[rearIndex] = val;
            count++;
        }
        else
        {
            throw std::runtime_error("Queue is full");
        }
    }

    T dequeue()
    {
        if (isempty())
        {
            throw std::runtime_error("Queue is empty");
        }
        else
        {
            count--;
            frontIndex = ++frontIndex % size;
            return (arr[frontIndex]);
        }
    }

    T &front()
    {
        if (isempty())
            throw std::runtime_error("Queue is empty");

        return arr[(frontIndex + 1) % size];
    }

    void print() const
    {
        for (int i = 1; i <= count; ++i)
        {
            int index = (frontIndex + i) % size;
            std::cout << arr[index] << ' ';
        }

        std::cout << '\n';
    }
};

int main()
{
    Queue<int> q(5);

    std::cout << "==== Test 1: Empty Queue ====\n";
    std::cout << std::boolalpha;
    std::cout << "Empty: " << q.isempty() << '\n';
    std::cout << "Full : " << q.isfull() << '\n';
    std::cout << "Size : " << q.getsize() << '\n';

    std::cout << "\n==== Test 2: Fill Queue ====\n";
    for (int i = 1; i <= 5; ++i)
    {
        q.enqueue(i * 10);
        q.print();
    }

    std::cout << "Empty: " << q.isempty() << '\n';
    std::cout << "Full : " << q.isfull() << '\n';

    std::cout << "\n==== Test 3: Front ====\n";
    std::cout << "Front = " << q.front() << '\n';

    std::cout << "\n==== Test 4: Dequeue Two Elements ====\n";
    std::cout << q.dequeue() << '\n';
    std::cout << q.dequeue() << '\n';
    q.print();

    std::cout << "\n==== Test 5: Circular Behaviour ====\n";
    q.enqueue(60);
    q.print();

    q.enqueue(70);
    q.print();

    std::cout << "\n==== Test 6: Remove Everything ====\n";
    while (!q.isempty())
    {
        std::cout << "Removed: " << q.dequeue() << '\n';
        q.print();
    }

    std::cout << "\n==== Test 7: Dequeue From Empty ====\n";
    try
    {
        q.dequeue();
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }

    std::cout << "\n==== Test 8: Front Of Empty ====\n";
    try
    {
        std::cout << q.front() << '\n';
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }

    std::cout << "\n==== Test 9: Overfill Queue ====\n";
    try
    {
        for (int i = 1; i <= 6; ++i)
        {
            q.enqueue(i);
            q.print();
        }
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }

    std::cout << "\n==== Test 10: Mixed Operations ====\n";
    Queue<int> q2(3);

    q2.enqueue(1);
    q2.enqueue(2);
    q2.print();

    std::cout << q2.dequeue() << '\n';

    q2.enqueue(3);
    q2.print();

    q2.enqueue(4);
    q2.print();

    std::cout << "Front = " << q2.front() << '\n';

    return 0;
}

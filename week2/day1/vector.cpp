#include <iostream>
#include <stdexcept>
#include <utility>

template <class T>
class Vector
{
private:
    int _size;
    int _capacity;
    T *v;

public:
    Vector()
    {
        _size = 0;
        _capacity = 1;
        v = new T[_capacity];
    }

    Vector(int c) : _capacity(c), _size(0)
    {
        v = new T[_capacity];
    }

    ~Vector()
    {
        delete[] v;
    }

    Vector(const Vector<T> &other)
    {
        _size = other._size;
        _capacity = other._capacity;
        v = new T[_capacity];
        for (int i = 0; i < _size; i++)
        {
            v[i] = other.v[i];
        }
    }

    Vector(Vector<T> &&other) noexcept
    {
        _size = other._size;
        _capacity = other._capacity;
        v = other.v;
        other.v = nullptr;
        other._size = 0;
        other._capacity = 0;
    }

    void push_back(const T &x)
    {
        if (_capacity == _size)
        {
            _capacity *= 2;
            T *v2 = new T[_capacity];
            for (int i = 0; i < _size; i++)
            {
                v2[i] = v[i];
            }
            delete[] v;
            v = v2;
        }
        v[_size] = x;
        _size++;
    }

    T pop_back()
    {
        if (_size == 0)
            throw std::out_of_range("Vector is empty");
        _size--;
        return v[_size];
    }

    T &operator[](const int &index)
    {
        if (index >= _size)
            throw std::out_of_range("Index out of range");
        return v[index];
    }

    Vector &operator=(const Vector &other)
    {
        if (this != &other)
        {
            delete[] v;
            _size = other._size;
            _capacity = other._capacity;
            v = new T[_capacity];
            for (int i = 0; i < _size; i++)
            {
                v[i] = other.v[i];
            }
        }
        return *this;
    }

    Vector &operator=(Vector &&other) noexcept
    {
        if (this != &other)
        {
            delete[] v;

            v = other.v;
            _size = other._size;
            _capacity = other._capacity;

            other.v = nullptr;
            other._size = 0;
            other._capacity = 0;
        }
        return *this;
    }

    int getsize()
    {
        return _size;
    }

    int getcapacity()
    {
        return _capacity;
    }
};

int main()
{
    try
    {
        std::cout << "--- Testing Basics ---" << std::endl;
        Vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);

        std::cout << "Size: " << vec.getsize() << " (Expected 3)" << std::endl;
        std::cout << "Capacity: " << vec.getcapacity() << " (Expected 4)" << std::endl;
        std::cout << "Element at index 1: " << vec[1] << " (Expected 20)" << std::endl;

        std::cout << "\n--- Testing Copy Constructor (Deep Copy) ---" << std::endl;
        Vector<int> vecCopy = vec; // Calls Copy Constructor
        vec[0] = 100;              // Change original
        std::cout << "Original[0]: " << vec[0] << " (Changed to 100)" << std::endl;
        std::cout << "Copy[0]: " << vecCopy[0] << " (Should still be 10)" << std::endl;

        std::cout << "\n--- Testing Move Semantics ---" << std::endl;
        std::cout << "Before Move - vec size: " << vec.getsize() << std::endl;
        Vector<int> vecMoved = std::move(vec); // Calls Move Constructor
        std::cout << "After Move - vecMoved size: " << vecMoved.getsize() << std::endl;
        std::cout << "After Move - original vec size: " << vec.getsize() << " (Should be 0)" << std::endl;

        std::cout << "\n--- Testing pop_back ---" << std::endl;
        int popped = vecMoved.pop_back();
        std::cout << "Popped: " << popped << " (Expected 30)" << std::endl;
        std::cout << "New size: " << vecMoved.getsize() << " (Expected 2)" << std::endl;

        std::cout << "\n--- Testing Assignment Operators ---" << std::endl;
        Vector<int> vecAssign;
        vecAssign = vecMoved; // Copy Assignment
        std::cout << "Assigned size: " << vecAssign.getsize() << " (Expected 2)" << std::endl;

        std::cout << "\n--- Testing Exception Handling ---" << std::endl;
        try
        {
            std::cout << "Attempting to access index 10..." << std::endl;
            std::cout << vecAssign[10] << std::endl;
        }
        catch (const std::out_of_range &e)
        {
            std::cout << "Caught expected error: " << e.what() << std::endl;
        }

        std::cout << "\n--- Testing Template with Strings ---" << std::endl;
        Vector<std::string> sVec;
        sVec.push_back("Hello");
        sVec.push_back("World");
        std::cout << sVec[0] << " " << sVec[1] << "!" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
    }

    return 0;
}
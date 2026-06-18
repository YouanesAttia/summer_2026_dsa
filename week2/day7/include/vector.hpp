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

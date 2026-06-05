#include <iostream>
using namespace std;

template <class T>
class unique_ptr
{
public:
    constexpr void reset()
    {
        delete data;
        data = nullptr;
    }
    constexpr unique_ptr() = default;
    constexpr unique_ptr(T *data_) : data(data_) {}
    constexpr ~unique_ptr() { reset(); }

    constexpr unique_ptr(unique_ptr &&other) : data(exchange(other.data, nullptr)) {}
    constexpr unique_ptr &operator=(unique_ptr &&other)
    {
        reset();
        data = exchange(other.data, nullptr);
    }

    unique_ptr(const unique_ptr &) = delete;
    unique_ptr &operator=(const unique_ptr &) = delete;

private:
    T *data = nullptr;
};
#include <iostream>
#include <stdexcept>

template <class T>
class singlyLinkedList
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node(T d) : data(d), next(nullptr) {}
    };
    Node *head;

public:
    singlyLinkedList()
    {
        head = nullptr;
    }

    singlyLinkedList(T d) : head(new Node(d)) {}

    ~singlyLinkedList()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push_front(const T d)
    {
        Node *n = new Node(d);
        n->next = head;
        head = n;
    }

    void push_back(const T d)
    {
        Node *n = new Node(d);
        if (head == nullptr)
        {
            head = n;
            return;
        }
        Node *tmp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = n;
    }

    void insert(const T d, const int pos)
    {
        if (head == nullptr)
            throw std::range_error("List is Empty");

        if (pos == 0)
        {
            push_front(d);
            return;
        }

        Node *p = head;
        for (int i = 0; i < pos; i++)
        {
            p = p->next;
        }
        if (p == nullptr)
            throw std::range_error("Not a valid position");

        if (p->next == nullptr && p != nullptr)
        {
            push_back(d);
            return;
        }

        Node *n = new Node(d);
        Node *q = p->next;
        p->next = n;
        n->next = q;
    }

    void pop_front()
    {
        if (head == nullptr)
            throw std::range_error("List is Empty");

        if (head->next == nullptr)
        {
            delete head;
            return;
        }

        node *p = head;
        head = head->next;
        delete p;
    }

    T frontData()
    {
        return head->data;
    }

    Node *frontNode()
    {
        return head;
    }

    void pop_back()
    {
        if (head == nullptr)
            throw std::range_error("List is Empty");

        if (head->next == nullptr)
        {
            delete head;
            return;
        }

        Node *p = head;
        Node *q = nullptr;
        while (temp->next != nullptr)
        {
            q = p;
            p = p->next;
        }
        delete p;
        q->next == nullptr;
    }

    Node *find(const T &d)
    {
        if (head == nullptr)
            throw std::range_error("List is Empty");

        Node *p = head;
        while (p != nullptr)
        {
            if (p->data == d)
                return p;
            else
                p = p->next;
        }
        return p;
    }

    void deleteByValue(const T val)
    {
        if (head == nullptr)
            throw std::range_error("List is Empty");

        if (head->data == val)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *p = head;
        Node *q = nullptr;

        while (p != nullptr && p->data != val)
        {
            q = p;
            p = p->next;
        }

        if (p == nullptr)
        {
            throw std::runtime_error("Value not found in the list");
        }

        q->next = p->next;
        delete p;
    }

    bool empty() const
    {
        return head == nullptr;
    }

    void reverse()
    {
        if (head == nullptr || head->next == nullptr)
            return;

        Node *p = nullptr;
        Node *q = head;
        Node *r = nullptr;

        while (q != nullptr)
        {
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }

        head = p;
    }
};

template <class T>
class Vector
{
private:
    int capacity;
    int size;
    T *v;

public:
    Vector() : size(0), capacity(1), v(new T[capacity]) {}
    Vector(size_type c) : size(0), capacity(c), v(new T[capacity])
    {
        for (int i = 0; i < capacity; i++)
            v[i] = -1;
    }
    Vector(size_type n, const T &value) : size(0), capacity(n), v(new T[capacity])
    {
        for (int i = 0; i < capacity; i++)
            v[i] = value;
    }
    Vector(const vector &other)
    {
        size = other.size;
        capacity = other.capacity;
        v = new T[capacity];
        for (int i = 0; i < size; i++)
        {
            v[i] = other.v[i];
        }
    }
    Vector(Vector<T> &&other) noexcept
    {
        size = other.size;
        capacity = other.capacity;
        v = other.v;
        other.v = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    ~Vector()
    {
        delete[] v;
    }

    void push_back(T val)
    {
        if (size == capacity)
        {
            capacity = capacity * 2;
            T *v2 = new T[capacity];
            for (int i = 0; i < size; i++)
            {
                v2[i] = v[i];
            }
            delete[] v;
            v = v2;
        }
        v[size++] = val;
    }

    void pop_back()
    {
        if (!size)
        {
            size--;
        }
        else
        {
            throw std::range_error("Vector is Empty");
        }

        if (size * 2 <= capacity)
        {
            capacity = capacity / 2 T *v2 = new T[capacity];
            for (int i = 0; i < size; i++)
            {
                v2[i] = v[i];
            }
            delete[] v;
            v = v2;
        }
    }

    T at(int idx)
    {
        if (idx >= size)
            throw std::range_error("Out of range");

        return v[idx];
    }

    T front()
    {
        if (size == 0)
            throw std::range_error("Vector is Empty");

        return v[0];
    }

    T back()
    {
        if (size == 0)
            throw std::range_error("Vector is Empty");

        return v[size - 1];
    }

    int getsize()
    {
        return size;
    }

    int getcapacity()
    {
        return capacity;
    }

    bool empty()
    {
        return size == 0;
    }

    T &operator[](const int &index)
    {
        if (index >= size)
            throw std::out_of_range("Index out of range");
        return v[index];
    }

    Vector &operator=(const Vector &other)
    {
        if (this != &other)
        {
            delete[] v;
            size = other.size;
            capacity = other.capacity;
            v = new T[capacity];
            for (int i = 0; i < size; i++)
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
            size = other.size;
            capacity = other.capacity;

            other.v = nullptr;
            other.size = 0;
            other.capacity = 0;
        }
        return *this;
    }
};
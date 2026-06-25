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
    Vector(const Vector &other)
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
        if (size == 0)
        {
            throw std::range_error("Vector is Empty");
        }
        else
        {
            size--;
        }

        if (size * 2 <= capacity)
        {
            capacity = capacity / 2;
            T *v2 = new T[capacity];
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

template <class T>
class DoublyLinkedList
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node *prev;
        Node(T d) : data(d), next(nullptr), prev(nullptr) {}
    };
    Node *head;

public:
    DoublyLinkedList()
    {
        head = nullptr;
    }

    DoublyLinkedList(T d) : head(new Node(d)) {}

    ~DoublyLinkedList()
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
        if (head != nullptr)
        {
            head->prev = n;
        }
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
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        tmp->next = n;
        n->prev = tmp;
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
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        if (p == nullptr)
            throw std::range_error("Not a valid position");

        Node *n = new Node(d);
        n->next = p->next;
        n->prev = p;
        if (p->next != nullptr)
        {
            p->next->prev = n;
        }
        p->next = n;
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

        Node *p = head;
        head = head->next;
        if (head)
            head->prev = nullptr;
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
        while (p->next != nullptr)
        {
            q = p;
            p = p->next;
        }
        delete p;
        q->next = nullptr;
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

        Node *curr = head;
        while (curr != nullptr && curr->data != val)
        {
            curr = curr->next;
        }

        if (curr == nullptr)
            throw std::runtime_error("Value not found");

        if (curr == head)
        {
            pop_front();
        }
        else
        {
            curr->prev->next = curr->next;
            if (curr->next != nullptr)
            {
                curr->next->prev = curr->prev;
            }
            delete curr;
        }
    }

    bool empty() const
    {
        return head == nullptr;
    }
};

template <class T>
class Stack
{
private:
    Vector<T> v;
    int top_;

public:
    Stack(int n) : v(n), top_(-1) {}
    void push(const T &val)
    {
        v.push_back(val);
        top_++;
    }
    void pop()
    {
        v.pop_back();
        top_--;
    }
    T top()
    {
        if (isEmpty())
            throw std::out_of_range("Stack is Empty");

        return v[top_];
    }
    bool isEmpty()
    {
        return top_ == -1;
    }
    T peek(int pos)
    {
        int index = top_ - pos + 1;
        if (index < 0 || index > top_)
        {
            throw std::out_of_range("Invalid Position");
        }
        return v[index];
    }
};

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
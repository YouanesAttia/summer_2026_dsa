#include <iostream>
#include <stdexcept>

template <class T>
class DoublyLinkedList
{
private:
    struct node
    {
        T data;
        node *prev;
        node *next;
        node(T a) : data(a), prev(nullptr), next(nullptr) {}
    };
    node *first;

public:
    DoublyLinkedList() : first(nullptr) {}

    ~DoublyLinkedList()
    {
        while (first != nullptr)
        {
            node *temp = first;
            first = first->next;
            delete temp;
        }
    }

    void push_front(T a)
    {
        node *t = new node(a);

        if (first)
        {
            first->prev = t;
            t->next = first;
        }

        first = t;
    }

    void push_back(T a)
    {
        node *t = new node(a);
        if (!first)
        {
            first = t;
        }
        else
        {
            node *p = first;
            while (p->next != nullptr)
            {
                p = p->next;
            }
            p->next = t;
            t->prev = p;
        }
    }

    T pop_front()
    {
        if (first == nullptr)
        {
            throw std::runtime_error("List is empty");
        }
        if (first->next == nullptr)
        {
            T val = first->data;
            delete first;
            first = nullptr;
            return val;
        }
        else
        {
            node *p = first;
            T val = first->data;
            first = first->next;
            delete p;
            first->prev = nullptr;
            return val;
        }
    }

    T pop_back()
    {
        if (first == nullptr)
        {
            throw std::runtime_error("List is empty");
        }
        if (first->next == nullptr)
        {
            T val = first->data;
            delete first;
            first = nullptr;
            return val;
        }
        else
        {
            node *q = nullptr;
            node *p = first;

            while (p->next != nullptr)
            {
                q = p;
                p = p->next;
            }
            T val = p->data;
            delete p;
            q->next = nullptr;
            return val;
        }
    }

    node *find(const T &value)
    {
        node *current = first;

        while (current != nullptr)
        {
            if (current->data == value)
            {
                return current;
            }

            current = current->next;
        }

        return nullptr;
    }

    void print() const
    {
        node *current = first;

        while (current != nullptr)
        {
            std::cout << current->data << " <-> ";
            current = current->next;
        }

        std::cout << "nullptr\n";
    }

    void insert_at(size_t index, const T &value)
    {
        if (index == 0)
        {
            push_front(value);
            return;
        }

        node *current = first;
        size_t pos = 0;

        while (current != nullptr && pos < index)
        {
            current = current->next;
            ++pos;
        }

        if (current == nullptr)
        {
            if (pos == index)
            {
                push_back(value);
                return;
            }

            throw std::out_of_range("Index out of range");
        }

        node *n = new node(value);

        n->prev = current->prev;
        n->next = current;

        current->prev->next = n;
        current->prev = n;
    }

    void delete_at(size_t index)
    {
        if (first == nullptr)
        {
            throw std::out_of_range("List is empty");
        }

        if (index == 0)
        {
            pop_front();
            return;
        }

        node *current = first;
        size_t pos = 0;

        while (current != nullptr && pos < index)
        {
            current = current->next;
            ++pos;
        }

        if (current == nullptr)
        {
            throw std::out_of_range("Index out of range");
        }

        if (current->next == nullptr)
        {
            pop_back();
            return;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;

        delete current;
    }

    bool hasCycle()
    {
        node *slow = first;
        node *fast = first;
        while (true)
        {
            if (slow == nullptr)
                return false;

            slow = slow->next;

            if (fast == nullptr)
                return false;

            fast = fast->next;

            if (fast == nullptr)
                return false;

            fast = fast->next;

            if (slow == fast)
                return true;
        }
    }

    bool hasCycle2()
    {
        node *slow = first;
        node *fast = first;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }

        return false;
    }

    void makeCycle()
    {
        if (first == nullptr)
            return;

        node *last = first;

        while (last->next != nullptr)
            last = last->next;

        last->next = first;
        first->prev = last;
    }

    node *findMiddle(node *head)
    {
        if (head == nullptr)
            return nullptr;

        node *slow = head;
        node *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};
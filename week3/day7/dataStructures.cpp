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
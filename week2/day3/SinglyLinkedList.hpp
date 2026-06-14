#include <iostream>
#include <stdexcept>

template <typename T>
class SinglyLinkedList
{
private:
    struct Node
    {
        T data;
        Node *next;

        Node(const T &value) : data(value), next(nullptr) {}
    };

    Node *head;

public:
    SinglyLinkedList()
        : head(nullptr)
    {
    }

    ~SinglyLinkedList()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    SinglyLinkedList(const SinglyLinkedList &) = delete;
    SinglyLinkedList &operator=(const SinglyLinkedList &) = delete;

    void push_front(const T &value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void push_back(const T &value)
    {
        Node *newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *current = head;

        while (current->next != nullptr)
        {
            current = current->next;
        }

        current->next = newNode;
    }

    T pop_front()
    {
        if (head == nullptr)
        {
            throw std::runtime_error("List is empty");
        }

        Node *temp = head;
        T value = temp->data;

        head = head->next;
        delete temp;

        return value;
    }

    Node *find(const T &value)
    {
        Node *current = head;

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

    void remove(const T &value)
    {
        if (head == nullptr)
        {
            return;
        }

        if (head->data == value)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *current = head;

        while (current->next != nullptr &&
               current->next->data != value)
        {
            current = current->next;
        }

        if (current->next != nullptr)
        {
            Node *temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    void reverse()
    {
        Node *prev = nullptr;
        Node *current = head;

        while (current != nullptr)
        {
            Node *next = current->next;

            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    bool empty() const
    {
        return head == nullptr;
    }

    void print() const
    {
        Node *current = head;

        while (current != nullptr)
        {
            std::cout << current->data << " -> ";
            current = current->next;
        }

        std::cout << "nullptr\n";
    }
};
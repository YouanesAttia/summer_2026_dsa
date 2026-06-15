#include <iostream>
#include <stdexcept>

template <class T>
class Tree
{
private:
    struct node
    {
        node *left;
        node *right;
        T data;
        node(T data_) : data(data_), left(nullptr), right(nullptr) {}
    };
    node *root;

public:
    void insert(const T &d)
    {
        node *n = new node(d);
        if (root == nullptr)
        {
            root = n;
        }
        else
        {
            node *t = root;
            node *s = root;
            while (t)
            {
                if (d > t->data)
                {
                    s = t;
                    t = t->right;
                }
                else if (d == t->data)
                {
                    delete n;
                    return;
                }
                else
                {
                    s = t;
                    t = t->left;
                }
            }
            if (d > s->data)
            {
                s->right = n;
            }
            else
            {
                s->left = n;
            }
        }
    }
    void insert(node *&n, const T &val)
    {
        if (n == nullptr)
        {
            n = new node(val);
            return;
        }

        if (val < n->data)
            insert(n->left, val);

        else if (val > n->data)
            insert(n->right, val);
    }
};
#include <iostream>
#include <stdexcept>
#include "Stack.hpp"
#include "Queue.hpp"

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
    Tree() : root(nullptr) {}
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

    void insertR(node *&n, const T &val)
    {
        if (n == nullptr)
        {
            n = new node(val);
            return;
        }

        if (val < n->data)
            insertR(n->left, val);

        else if (val > n->data)
            insertR(n->right, val);
    }

    void preorder()
    {
        preorder(root);
    }

    void preorder(node *n)
    {
        if (n == nullptr)
            return;
        std::cout << n->data << " ";
        preorder(n->left);
        preorder(n->right);
    }

    void inorder()
    {
        inorder(root);
    }

    void inorder(node *n)
    {
        if (n == nullptr)
            return;
        inorder(n->left);
        std::cout << n->data << " ";
        inorder(n->right);
    }

    void postorder()
    {
        postorder(root);
    }

    void postorder(node *n)
    {
        if (n == nullptr)
            return;
        postorder(n->left);
        postorder(n->right);
        std::cout << n->data << " ";
    }

    void preorderI()
    {

        if (!root)
            return;

        Stack<node *> s;
        s.push(root);

        while (!s.empty())
        {
            node *n = s.top();
            s.pop();
            std::cout << n->data << " ";

            if (n->right)
                s.push(n->right);

            if (n->left)
                s.push(n->left);
        }
    }

    void inorderI()
    {
        if (!root)
            return;

        Stack<node *> s;
        node *current = root;
        while (current || !s.empty())
        {
            while (current)
            {
                s.push(current);
                current = current->left;
            }

            current = s.top();
            s.pop();

            std::cout << current->data << " ";

            current = current->right;
        }
    }

    void postorderI()
    {
        if (!root)
            return;

        Stack<node *> s1;
        Stack<node *> s2;

        s1.push(root);

        while (!s1.empty())
        {
            node *n = s1.top();
            s1.pop();

            s2.push(n);

            if (n->left)
                s1.push(n->left);

            if (n->right)
                s1.push(n->right);
        }

        while (!s2.empty())
        {
            std::cout << s2.top()->data << " ";
            s2.pop();
        }
    }

    void levelorder()
    {
        if (!root)
            return;

        Queue<node *> q;
        q.enqueue(root);
        while (!q.isempty())
        {
            node *r = q.dequeue();
            std::cout << r->data << " ";
            if (r->left)
                q.enqueue(r->left);
            if (r->right)
                q.enqueue(r->right);
        }
    }

    int height(struct node *n)
    {
        int x = 0, y = 0;
        if (n == 0)
            return 0;
        x = height(n->left);
        y = height(n->right);
        if (x > y)
            return x + 1;
        else
            return y + 1;
    }

    int height()
    {
        return height(root);
    }

    int countNodes(node *n)
    {
        if (!n)
            return 0;

        return 1 +
               countNodes(n->left) +
               countNodes(n->right);
    }

    int countNodes()
    {
        return countNodes(root);
    }

    node *search(T x)
    {
        return search(root, x);
    }

    node *search(node *n, T x)
    {
        if (n == nullptr)
            return nullptr;

        node *t = n;
        if (t->data > x)
        {
            return search(t->left, x);
        }
        else if (t->data < x)
        {
            return search(t->right, x);
        }
        else
        {
            return t;
        }
    }
};

int main()
{
    Tree<int> t;

    int values[] = {50, 30, 70, 20, 40, 60, 80};

    for (int x : values)
        t.insert(x);

    std::cout << "Inorder (sorted): ";
    t.inorder();
    std::cout << "\n";

    std::cout << "Preorder: ";
    t.preorder();
    std::cout << "\n";

    std::cout << "Postorder: ";
    t.postorder();
    std::cout << "\n";

    std::cout << "Level Order: ";
    t.levelorder();
    std::cout << "\n";

    std::cout << "\nIterative Traversals\n";

    std::cout << "Preorder Iterative: ";
    t.preorderI();
    std::cout << "\n";

    std::cout << "Inorder Iterative: ";
    t.inorderI();
    std::cout << "\n";

    std::cout << "Postorder Iterative: ";
    t.postorderI();
    std::cout << "\n";

    std::cout << "\nTree Height = "
              << t.height() << "\n";

    std::cout << "Node Count = "
              << t.countNodes() << "\n";

    return 0;
}
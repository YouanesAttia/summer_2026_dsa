#include <iostream>
#include <stdexcept>
#include "Stack.hpp"
#include "Queue.hpp"
#include <vector>
#include <algorithm>
#include <cassert>

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

    node *findMin()
    {
        if (root == nullptr)
            return nullptr;
        node *t = root;
        while (t->left != nullptr)
        {
            t = t->left;
        }
        return t;
    }

    node *findMin(node *n)
    {
        node *current = n;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    node *findMax()
    {
        if (root == nullptr)
            return nullptr;
        node *t = root;
        while (t->right != nullptr)
        {
            t = t->right;
        }
        return t;
    }

    std::vector<T> inorder2()
    {
        std::vector<T> v;
        inorder2(root, v);
        return v;
    }

    void inorder2(node *n, std::vector<T> &v)
    {
        if (n == nullptr)
            return;

        inorder2(n->left, v);
        v.push_back(n->data);
        inorder2(n->right, v);
    }

    bool isValidBST()
    {
        std::vector<T> v = inorder2();
        if (std::is_sorted(v.begin(), v.end()))
            return true;
        return false;
    }

    node *deleteNode(T key)
    {
        return deleteNode(root, key);
    }

    node *deleteNode(node *n, T key)
    {
        if (n == nullptr)
        {
            return n;
        }

        if (key < n->data)
        {
            n->left = deleteNode(n->left, key);
        }
        else if (key > n->data)
        {
            n->right = deleteNode(n->right, key);
        }

        else
        {
            if (n->left == nullptr)
            {
                node *temp = n->right;
                delete n;
                return temp;
            }
            else if (n->right == nullptr)
            {
                node *temp = n->left;
                delete n;
                return temp;
            }

            node *temp = findMin(n->right);
            n->data = temp->data;
            n->right = deleteNode(n->right, temp->data);
        }
        return n;
    }

    node *lowestCommonAncestor(const T val1, const T val2)
    {
        node *p = root;
        node *q = root;
        node *lca = root;

        while (p != nullptr && q != nullptr)
        {
            if (p == q)
            {
                lca = p;
            }
            else
            {
                break;
            }

            if (p->data > val1)
            {
                p = p->left;
            }
            else if (p->data < val1)
            {
                p = p->right;
            }

            if (q->data > val2)
            {
                q = q->left;
            }
            else if (q->data < val2)
            {
                q = q->right;
            }
            if (p != nullptr && p->data == val1 && q != nullptr && q->data == val2)
                break;
        }
        return lca;
    }
};

void printSection(const std::string &name)
{
    std::cout << "\n--- Testing " << name << " ---" << std::endl;
}

int main()
{
    Tree<int> bst;

    /*
            Structure we are building:
                  50
               /      \
              30      70
             /  \    /  \
            20  40  60  80
    */

    printSection("Insertion and Count");
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    std::cout << "Nodes counted: " << bst.countNodes() << " (Expected: 7)" << std::endl;
    assert(bst.countNodes() == 7);

    printSection("Height");
    std::cout << "Tree Height: " << bst.height() << " (Expected: 3)" << std::endl;
    assert(bst.height() == 3);

    printSection("Traversals (Visual Check)");

    std::cout << "Inorder (Recursive): ";
    bst.inorder(); // Should be 20 30 40 50 60 70 80
    std::cout << "\nInorder (Iterative): ";
    bst.inorderI();
    std::cout << std::endl;

    std::cout << "Preorder (Recursive): ";
    bst.preorder(); // Should be 50 30 20 40 70 60 80
    std::cout << "\nPreorder (Iterative): ";
    bst.preorderI();
    std::cout << std::endl;

    std::cout << "Postorder (Recursive): ";
    bst.postorder(); // Should be 20 40 30 60 80 70 50
    std::cout << "\nPostorder (Iterative): ";
    bst.postorderI();
    std::cout << std::endl;

    std::cout << "Level-order: ";
    bst.levelorder(); // Should be 50 30 70 20 40 60 80
    std::cout << std::endl;

    printSection("Search and Min/Max");
    auto minNode = bst.findMin();
    auto maxNode = bst.findMax();
    if (minNode)
        std::cout << "Min: " << minNode->data << " (Expected: 20)" << std::endl;
    if (maxNode)
        std::cout << "Max: " << maxNode->data << " (Expected: 80)" << std::endl;

    assert(minNode->data == 20);
    assert(maxNode->data == 80);

    auto searchNode = bst.search(40);
    std::cout << "Searching for 40: " << (searchNode ? "Found" : "Not Found") << std::endl;
    assert(searchNode != nullptr);

    auto searchFail = bst.search(99);
    std::cout << "Searching for 99: " << (searchFail ? "Found" : "Not Found") << std::endl;
    assert(searchFail == nullptr);

    printSection("BST Validation");
    std::cout << "Is valid BST? " << (bst.isValidBST() ? "Yes" : "No") << std::endl;
    assert(bst.isValidBST() == true);

    printSection("Lowest Common Ancestor");
    // LCA of 20 and 40 is 30
    auto lca1 = bst.lowestCommonAncestor(20, 40);
    std::cout << "LCA of 20 and 40: " << lca1->data << " (Expected: 30)" << std::endl;
    assert(lca1->data == 30);

    // LCA of 20 and 80 is 50
    auto lca2 = bst.lowestCommonAncestor(20, 80);
    std::cout << "LCA of 20 and 80: " << lca2->data << " (Expected: 50)" << std::endl;
    assert(lca2->data == 50);

    printSection("Deletion");
    std::cout << "Deleting leaf node 20..." << std::endl;
    bst.deleteNode(20);
    bst.inorder();
    std::cout << "\nNodes after delete: " << bst.countNodes() << " (Expected: 6)" << std::endl;
    assert(bst.countNodes() == 6);

    std::cout << "Deleting node with two children 70..." << std::endl;
    bst.deleteNode(70);
    bst.inorder();
    std::cout << std::endl;
    assert(bst.isValidBST());

    std::cout << "\nAll tests passed successfully!" << std::endl;

    return 0;
}
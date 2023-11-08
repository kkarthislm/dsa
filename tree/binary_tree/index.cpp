#include <iostream>
#include <string.h>

using namespace std;

template <class T>
struct Node
{
    T data;
    Node *left = nullptr, *right = nullptr;
};

template <class T>
class Tree
{
    Node *root = nullptr;

public:
    void insert(T data);
    void delete_node(T data);
    bool search(T data);
    void inorder_traversal();
    void preorder_traversal();
    void postorder_traversal();
    void levelorder_traversal();
};

template <class T>
void Tree<T>::insert(T data)
{
}

template <class T>
void Tree<T>::delete_node(T data)
{
}

template <class T>
bool Tree<T>::search(T data)
{
}

template <class T>
void Tree<T>::inorder_traversal()
{
}

template <class T>
void Tree<T>::preorder_traversal()
{
}

template <class T>
void Tree<T>::postorder_traversal()
{
}

template <class T>
void Tree<T>::levelorder_traversal()
{
}

int main()
{
}
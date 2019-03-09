#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Node
{
  public:
    T data;
    Node<T> *left;
    Node<T> *right;

    Node()
    {
        left = right = NULL;
    }
    Node(T data)
    {
        this->data = data;
        left = right = NULL;
    }
};

template <typename T>
class BinarySearchTree
{
    Node<T> *root;

    void insertToNode(Node<T> *node, T data)
    {
        if (node->data > data)
        {
            if (node->left == NULL)
            {
                node->left = new Node<T>(data);
            }
            else
            {
                insertToNode(node->left, data);
            }
        }
        else
        {
            if (node->right == NULL)
            {
                node->right = new Node<T>(data);
            }
            else
            {
                insertToNode(node->right, data);
            }
        }
    }

  public:
    BinarySearchTree()
    {
        root = NULL;
    }
    void insert(T data)
    {
        if (root == null)
        {
            Node<T> newNode = new Node<T>(data);
            root = newNode;
        }
        else
        {
            insertToNode(root,data);
        }
    }
};
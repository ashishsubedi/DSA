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
        if (root == NULL)
        {
            Node<T> *newNode = new Node<T>(data);
            root = newNode;
        }
        else
        {
            insertToNode(root, data);
        }
    }

    void inorder(Node<T> *node)
    {
        if (node == NULL)
            return;

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
    void preorder(Node<T> *node)
    {
        if (node == NULL)
            return;

        cout << node->data << " ";
        inorder(node->left);
        inorder(node->right);
    }
    void postorder(Node<T> *node)
    {
        if (node == NULL)
            return;

        inorder(node->left);
        inorder(node->right);
        cout << node->data << " ";
    }
    Node<T> *getRoot()
    {
        return root;
    }
};
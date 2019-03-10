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
    Node<T> *findWithParent(Node<T> *node, T data, Node<T> *&parentNode)
    {
        if (data == node->data)
        {
            return node;
        }
        else
        {
            if (data > node->data)
            {
                if (node->right == NULL)
                {
                    return NULL;
                }
                else
                {
                    parentNode = node;
                    findWithParent(node->right, data, parentNode);
                }
            }
            else
            {
                if (node->left == NULL)
                {
                    return NULL;
                }
                else
                {
                    parentNode = node;
                    findWithParent(node->left, data, parentNode);
                }
            }
        }
    }

    //Refactor this with reference variable dumbo
    void swapNode(Node<T> **node1, Node<T> **node2)
    {
        Node<T> *temp = *(node1);
        (*node1)->data = (*node2)->data;
        (*node2)->data = temp->data;
    }

    Node<T> *findMinimumValueNode(Node<T> *node, Node<T>* &parentNode)
    {
        Node<T> *p = node;
        while (p->left != NULL)
        {
            parentNode = p;
            p = p->left;
        }
        return p;
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
        preorder(node->left);
        preorder(node->right);
    }
    void postorder(Node<T> *node)
    {
        if (node == NULL)
            return;

        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
    Node<T> *find(T data)
    {
        Node<T> *parentNode = NULL;
        findWithParent(root, data, parentNode);
    }

    //THIS DOESNOT WORK YETTTTTT
    void deleteByData(T data)
    {
        Node<T> *parentNode = NULL;

        Node<T> *currentNode = findWithParent(root, data, parentNode);
        //If the node is leaf, delete directly
        if (currentNode->left == NULL && currentNode->right == NULL)
        {
            delete currentNode;
            return;
        }
        //If not,
        else
        {
            //If the node has only right node, swap values and dele
            if (currentNode->left == NULL)
            {
                if (currentNode->data < parentNode->data)
                {
                    //current node is left child of parent
                    parentNode->left = currentNode->right;
                }
                else
                {
                    //current node is right child of parent
                    parentNode->right = currentNode->right;
                }
                delete currentNode;
            }
            //If the node has only left node, swap values and dele

            else if (currentNode->right == NULL)
            {
                if (currentNode->data < parentNode->data)
                {
                    //current node is left child of parent
                    parentNode->left = currentNode->left;
                }
                else
                {
                    //current node is right child of parent
                    parentNode->right = currentNode->left;
                }
                delete currentNode;
            }
            else
            {
                Node<T>* reqNodeParent = NULL;
                Node<T> *reqNode = findMinimumValueNode(currentNode->right,reqNodeParent);
                currentNode->data = reqNode->data;
                reqNodeParent->left = NULL;
                delete reqNode;
            }
        }
    }

    Node<T> *getRoot()
    {
        return root;
    }
};
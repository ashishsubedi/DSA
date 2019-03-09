#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Node
{
  public:
    T data;
    Node *prev;
    Node *next;

    Node()
    {
        next = NULL;
        prev = NULL;
    }
    Node(T _data)
    {
        data = _data;
        next = NULL;
        prev = NULL;
    }
};

template <class T>
class DoublyLinkedList
{

    Node<T> *head;

  public:
    DoublyLinkedList()
    {
        head = NULL;
    }

    void insertFirst(T data)
    {

        Node<T> *newNode = new Node<T>(data);
        if (head != NULL)
        {
            head->prev = newNode;
            newNode->next = head;
        }

        head = newNode;
    }
    void printAll()
    {
        Node<T> *p = head;
        while (p != NULL)
        {
            cout << " " << p->data;
            p = p->next;
        }
        cout << endl;
    }

    void insertLast(T data)
    {
        Node<T> *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        Node<T> *newNode = new Node<T>(data);
        p->next = newNode;
        newNode->prev = p;
    }

    T getFront()
    {
        return head->data;
    }
    T getBack()
    {
        Node<T> *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        return p->data;
    }
    void deleteAtPosition(int index){
        int count = 0;
        Node<T>* p = head;
        while(count != index && p != NULL){
            count++;
            p = p->next;
        }
        p->prev->next = p->next;
        p->next->prev = p->prev;

        delete p;
    }
};

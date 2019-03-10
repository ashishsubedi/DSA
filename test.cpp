//#include "doublyLinkedList.hpp"
#include "tree.hpp"
void testBST();

int main()
{
    testBST();
}

/* void testDoublyLinkedList()
{
    DoublyLinkedList<int> list;
    list.insertFirst(5);
    list.printAll();
    list.insertFirst(10);
    list.printAll();
    list.insertFirst(15);
    list.printAll();
    list.insertLast(20);
    list.printAll();
    list.insertLast(25);
    list.printAll();
    cout << list.getBack() << endl;
    cout << list.getFront() << endl;
    list.deleteAtPosition(2);
    list.printAll();
} */

void testBST()
{
    BinarySearchTree<int> tree;
    tree.insert(25);
    tree.insert(20);
    tree.insert(230);
    tree.insert(5);
    tree.insert(28);
    tree.inorder(tree.getRoot());
    cout << endl;
    tree.preorder(tree.getRoot());
    cout << endl;
    tree.postorder(tree.getRoot());
    cout << endl;

    if (tree.find(28) != NULL)
    {
        cout << "Found data" << endl;
    }
    else
    {
        cout << "RETURNED NULL" << endl;
    }
    tree.deleteByData(25);
    tree.inorder(tree.getRoot());
    cout << endl;
    tree.preorder(tree.getRoot());
    cout << endl;
    tree.postorder(tree.getRoot());
    cout << endl;
}
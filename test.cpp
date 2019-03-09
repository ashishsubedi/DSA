#include "doublyLinkedList.hpp"

int main()
{
}

void testDoublyLinkedList()
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
}
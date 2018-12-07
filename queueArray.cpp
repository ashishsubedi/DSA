#include<iostream>

#define MAX_SIZE 101

using namespace std;

class Queue{
    int front, rear;
    unsigned int length;
    int data[MAX_SIZE];
public:
    Queue(){
        front = rear = -1;
        length = 0;
    }
    bool isFull(){
        if(length == (MAX_SIZE)) return true;
        return false;
    }
    bool isEmpty(){
        if(length == 0) return true;
        return false;
    }
    void enqueue(int x){
        if(isFull()){
            cout<<"Queue Overflow\n";
            return;
        }
        if(isEmpty()){
            front++;
        }
        rear = (rear + 1) % (MAX_SIZE );
        length ++;
        data[rear] = x;

    }
    int dequeue(){
        if(isEmpty()){
            cout<<"Queue Underflow\n";
            return -1;
        }
        length --;
        int x = data[front];
        front = (front + 1) % (MAX_SIZE );
        return x;
    }
    int frontElement(){
        return data[front];
    }
    int rearElement(){
        return data[rear];
    }
    void Print(){

        //Doesnot work if rear < front
       
        for(int i = front; i < (length + front); i++){
            cout<<data[i]<<" ";
        }
        cout<<"\n";
    }
};

int main(int argc, char const *argv[])
{
    Queue q;
    cout<<q.isEmpty()<<endl;
    cout<<q.isFull()<<endl;
    q.Print();
    q.enqueue(5);
    q.enqueue(10);
    q.Print();
    q.enqueue(20);
    q.Print();
    cout<<q.dequeue()<<endl;
    cout<<q.frontElement()<<endl;
    cout<<q.rearElement()<<endl;


    return 0;
}

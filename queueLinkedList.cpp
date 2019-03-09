#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

class Queue{
    int count;
    Node* front,*rear;

    Node* createNode(){
        Node* newNode = new Node();
        newNode->next = NULL;
        cout<<"Node Created\n";
        return newNode;
    }
    
    public:

    Queue(){
        count = 0;
        front = rear = NULL;
    }

    void enqueue(int val){
        Node *current = createNode();
        current->data = val;
        if(rear == NULL){
            front = rear = current;
        }else{
            rear->next = current;
            rear = current;
        }
           
        count++;
        cout<<"Data Enqueued\n";

    }
    int dequeue(){
        int val = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        count--;
        cout<<"Data dequeued ";


        return val;
    }
    bool isEmpty(){
        return (count == 0)?true: false;
    }

   
};

int main(){

    Queue q;
    for(int i=0;i<10;i++){
        q.enqueue(i);
    }
    cout<<"Enqueued"<<endl;

    for(int i=0; i<10; i++){
        cout<<q.dequeue()<<" \n";
    }

    return 0;
}
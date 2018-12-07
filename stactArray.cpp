#include<iostream>
#define MAX_SIZE 101

using namespace std;
class Stack{
    private:
        int top;
        int data[MAX_SIZE];
    public:
        Stack(){
            top = -1;
        }
        bool isEmpty(){
            if(top == -1) return true;
            return false;
        }
        int top(){
            return data[top];
        }
        void push(int x){
            if(top == MAX_SIZE - 1){
                cout<<"Stack Overflow"<<endl;
                return;
            }
            data[++top] = x;
        }
        int pop(){
            if(isEmpty()){
                cout<<"Stack Underflow\n";
                return -1;
            }
            return data[top--];
        }
        void print(){
            for(int i=0; i <= top; i++){
                cout<<data[i]<<" ";
            }
            cout<<"\n";
        }
};
int main(){

    Stack s;
    s.push(5);
    s.print();
    for(int i=0; i < 150; i++){
        s.push(i);
    }
    s.print();

    return 0;
}
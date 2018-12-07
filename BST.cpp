#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

class BST{
    
    Node* createNode(int data){
        Node* newNode = new Node();
        newNode->data = data;
        newNode->left = newNode->right = NULL;
    }
    public:
    Node* root;

    BST(){
        root = NULL;
    }


    Node* insert(int data,Node* rootPtr){

        if(rootPtr == NULL){
            rootPtr = createNode(data);
        }
        else if(data <= rootPtr->data){
            rootPtr->left = insert(data,rootPtr->left);
        }
        else{
            rootPtr->right = insert(data,rootPtr->right);
        }
        return rootPtr;
    }

    bool search(int data,Node* rootPtr){
        if(rootPtr == NULL) return false;
        else if(rootPtr->data == data) return true;
        else if(data <= rootPtr->data) return search(data,rootPtr->left);
        else return search(data,rootPtr->right);
    }
};



int main(){

    BST myTree;

    myTree.insert(10,myTree.root);
    myTree.insert(20,myTree.root);
    myTree.insert(50,myTree.root);
    myTree.insert(15,myTree.root);
    myTree.insert(20,myTree.root);
    int num;

    cin>>num;
    if(myTree.search(num,myTree.root)) cout<<"Found data\n";
    else cout<<"Data not found\n";


    return 0;
}
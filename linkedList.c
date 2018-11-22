#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head;
int length = 0;


struct Node* createNode(){
    struct Node* current = (struct Node*)malloc(sizeof(struct Node));
    current->next = NULL;
    return current;
}
void append(int val){
    struct Node* current = createNode();

    if(head == NULL) head = current;    
    else{
        struct Node* current2 = head; 
        while(current2->next != NULL)
            current2 = current2->next;

        current2->next = current;
    }

    
    current->data = val;
    length++;
}

void insertAt(int val, int index){
    struct Node* current = createNode();
    current->data = val;
    
    if(index > length - 1){
        printf("Invalid index\n");
        return;
    }

    if(head == NULL) head = current;
    if(index == 0){
        current->next = head;
        head = current;
        
    }
    else{
        struct Node* temp = head;
        int i;
        for(i = 0; i < index - 1 ; i++ ){
            temp = temp->next;
        }
        current->next = temp->next;
        temp->next = current;
    }
    length++;
}
int isEmpty(){
    if(length == 0) return 1;
    else return 0;
}
void removeValue(int val){
    struct Node* prev = NULL;
    struct Node* current = prev = head;

    if(head == NULL) return;
    while(current != NULL){
        if(current->data == val){

            prev->next = current->next;
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }

 
    
 
    length--;
    
}

void removeAt(int index){
    struct Node* prev;
    struct Node* current = prev = head;

    if(head == NULL) return;
    int i ;
    if(index > length - 1) {
        printf("Invalid index\n");
        return;
    }
    if(index == 0) {
        
        head = current->next;
        
        
    }
    else{
        for(i = 0; i < index-1; i++){
            prev = prev->next;
        }
        current = prev->next;
        prev->next = current->next;
    }
 
    free(current);
    length--;

}

void Print(){

    

    struct Node* current = head;
    if (head == NULL) return;
    while(current != NULL){
        printf("%d ",current->data);
        current = current->next;
    }
    printf("\n");
}

int main(){
    head = NULL;
    printf("length:%d\n",length);

    append(2);
    printf("length:%d\n",length);

    Print();
    
    append(3);
    printf("length:%d\n",length);
   

    Print();
   
   
    append(5);
    printf("length:%d\n",length);
    

    Print();
    append(8);
    printf("length:%d\n",length);
    

    Print();
   
   
    insertAt(10,2);
    printf("length:%d\n",length);
    

    Print();
    
    
    removeValue(3);
    printf("length:%d\n",length);
   

    Print();
    removeValue(8);
    printf("length:%d\n",length);
  

    Print();

    insertAt(15,0);
    printf("length:%d\n",length);

    Print();
    
    insertAt(15,10);
    printf("length:%d\n",length);

    Print();

    removeValue(2);
    printf("length:%d\n",length);


    Print();

    removeAt(0);
    printf("length:%d\n",length);

    Print();

    removeAt(4);
    printf("length:%d\n",length);

    Print();

    removeAt(1);
    printf("length:%d\n",length);
    Print();
    
    printf("Empty: %d\n",isEmpty());
   
    removeAt(0);
    printf("length:%d\n",length);
    Print();

    printf("Empty: %d\n",isEmpty());
   

    return 0;
}
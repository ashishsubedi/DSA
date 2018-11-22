#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int front, rear, length;
    unsigned int size;
    int * data;
} ;

struct Queue* createQueue(int size){
    struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
    q->front = q->length  = 0;
    q->size = size;
     q->rear= size-1;//Because after enqueuing, rears goes to 0
    q->data = (int*)malloc(q->size*sizeof(int));
    return q;
}
int isFull(struct Queue* q){
    return (q->length == q->size);
}
int isEmpty(struct Queue* q){
    return (q->length == 0);
}
void enqueue(struct Queue* q, int value){
    if(isFull(q)){
        printf("Queue Overflow");
        return;
    }

    q->rear = (q->rear +1)%q->size;
    q->data[q->rear] = value;
    q->length++;

    printf("Queue enqued\n");

}
int dequeue(struct Queue* q){
    if(isEmpty(q)){
        printf("Queue Underflow");
        return -1;
    }

   int item = q->data[q->front];
   q->front = (q->front + 1) % q->size;
   q->length --;
   

    printf("Queue dequed\n");
    return item;

}
int front(struct Queue* q){
    if(isEmpty(q)){
        printf("Queue Underflow");
        return -1;
    } 
    return q->data[q->front];
}
int rear(struct Queue* q){
    if(isEmpty(q)){
        printf("Queue Underflow");
        return -1;
    } 
    return q->data[q->rear];
}
int main(int argc, char const *argv[])
{
    struct Queue *queue =createQueue(1000);
    enqueue(queue, 10); 
    printf("Rear item is %d at %d\n",rear(queue), queue->rear); 
    enqueue(queue, 20); 
    printf("Rear item is %d at %d\n",rear(queue), queue->rear); 

    enqueue(queue, 30); 
    printf("Rear item is %d at %d\n",rear(queue), queue->rear); 

    enqueue(queue, 40); 
    printf("Rear item is %d at %d\n",rear(queue), queue->rear); 

  
    printf("%d dequeued from queue\n\n", dequeue(queue)); 
  
    printf("Front item is %d\n", front(queue)); 
    printf("Rear item is %d\n", rear(queue)); 
  
  
    return 0;
}

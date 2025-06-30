#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

typedef struct Node Queue;

Queue* front = NULL;
Queue* rear = NULL;

void createNode(int val){
    Queue* newNode = NULL;
    newNode = (Queue*)malloc(sizeof(Queue));
    newNode->data = val;
    newNode->next = NULL;
    front = rear = newNode;
}   

// enqueue -> appendNode
// dequeue -> removefromhead

void enQueue(int val){
     Queue* newNode = NULL;
    newNode = (Queue*)malloc(sizeof(Queue));
    newNode->data = val;
    newNode->next = NULL;

    if(front == NULL){
        createNode(val);
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

void deQueue(void){
    if(front == NULL){
        printf("Queue is empty..\n");
        return;
    }
    Queue* temp = front;
    front = front->next;
    free(temp);
}

void display(void){
    Queue* temp = front;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}

int main(){
    int arr[] = {4, 5, 1, 2, 8, 9, 0};
    int n = sizeof(arr)/sizeof(int);
    for(int i = 0; i < n; i++){
        enQueue(arr[i]);
    }

    display();

    deQueue();
    deQueue();
    display();  // Should print: 1 2 8 9 0


    return 0;
}

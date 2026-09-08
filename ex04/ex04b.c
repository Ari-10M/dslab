#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct queue {
  struct Node* front;
  struct Node* rear; 
};

struct Node* createNode(int data) {
  struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
  if(!newNode) {
    printf("memory allocation error\n");
    exit(1);
  }
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void initializequeue(struct queue* queue){
  queue->front = NULL;
  queue->rear = NULL;
}

void enqueue(struct queue* queue, int data){
  struct Node* newNode=createNode(data);
  if(queue->rear==NULL){
    queue->front=queue->rear=newNode;
    printf("element enqueued:%d\n",data);
    return;
  }
  queue->rear->next=newNode;
  queue->rear=newNode;
  printf("element enqueued:%d\n",data);
  }
int dequeue(struct queue* queue) {
  if(queue->front == NULL) {
    printf("error:queue underflow. cannot dequeue element.\n");
    return -1;
  }
  struct Node* temp=queue->front;
  int dequeuedelement=temp->data;
  queue->front=queue->front->next;
    
  if(queue->front==NULL){
    queue->rear=NULL;
  }
  free(temp);
  return dequeuedelement;
}

void displayqueue(struct queue* queue) {
  if (queue->front==NULL) {
    printf("queue is empty.\n");
  }
  printf("Queue elements:");
  struct Node* temp =queue->front;
  while(temp!=NULL) {
    printf("%d->",temp->data);
    temp=temp->next;
  }
  printf("NULL\n");
}

int main() {
  struct queue queue;
  int choice,element;
  
  initializequeue(&queue);
  
  while(1) {
    printf("\nqueue operations menu:\n");
    printf("1.enqueue\n");
    printf("2.dequeue\n");
    printf("3.display\n");
    printf("4.exit\n");
    printf("enter your choice:");
    scanf("%d",&choice);
    
    switch(choice) {
      case 1:
        printf("enter element to enqueue: ");
        scanf("%d",&element);
        enqueue(&queue,element);
        break;
      case 2:
        element=dequeue(&queue);
        if(element!=-1)
          printf("dequeued element:%d\n",element);
        break;
      case 3:
        displayqueue(&queue);
        break;
      case 4:
        exit(0);
      default:
        printf("invalid choice!please enter a valid option.\n");
    }
  }
  return 0;
}
  
  

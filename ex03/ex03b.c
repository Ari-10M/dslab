#include<stdio.h>
#include<stdlib.h>

#define MAX 100

struct queue {
  int arr[MAX];
  int front;
  int rear;
};

void initializequeue(struct queue *queue) {
  queue->front = -1;
  queue->rear = -1;
}

int isfull(struct queue *queue) {
  return queue->rear == MAX -1;
}

int isempty(struct queue *queue) {
  return queue->front == MAX -1|| queue->front > queue->rear;
}

void enqueue(struct queue *queue, int element) {
  if (isfull(queue)) {
    printf("error: queue overflow.cannot enqueue element.\n");
    return;
  }
  if (queue->front == -1) {
    queue->front = 0;
  }
  queue->arr[++queue->rear] = element;
  printf("element enqueued: %d\n",element);
}

int dequeue(struct queue *queue) {
  if(isempty(queue)) {
    printf("error:queue underflow.cannot dequeue element.\n");
    return -1;
  }
  int element = queue->arr[queue->front++];
  
  if(queue->front > queue->rear) {
    queue->front = -1;
    queue->rear = -1;
  }
  
  return element;
}
  
void displayqueue(struct queue *queue) {
  if (isempty(queue)) {
    printf("queue is empty.\n");
    return;
  }
  printf("queue elements: ");
  for (int i = queue->front;i <= queue->rear;i++){
    printf("%d ", queue->arr[i]);
  }
  printf("\n");
}

int main() {
  struct queue queue;
  int choice,element;
  
  initializequeue(&queue);
  
  while(1){
    printf("\nqueue operations menu :\n");
    printf("1. enqueue\n");
    printf("2. dequeue\n");
    printf("3. display\n");
    printf("4. exit\n");
    printf("enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
      case 1:
        printf("enter element to enqueue: ");
        scanf("%d", &element);
        enqueue(&queue, element);
        break;
      case 2:
        element = dequeue(&queue);
        if (element != -1)
          printf("dequeued element: %d\n", element);
        break;
      case 3:
        displayqueue(&queue);
        break;
      case 4:
        exit(0);
      default:
        printf("invalid choice! please enter a valid option.\n");
    }
  }
  return 0;
}

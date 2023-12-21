#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int size;
    int* arr;
    int front,rear;
};

void initialise(struct Queue *q){
    q->size = 10000;
    q->front = -1;
    q->rear = -1;
    q->arr = (int*)malloc(sizeof(int)*q->size);
}

int isFull(struct Queue q){
    return q.rear == q.size;
}

int isEmpty(struct Queue q){
    return q.front == q.rear;
}

void enqueue(struct Queue *q,int ele){
    if(isFull(*q)) printf("Queue is Full\n");

    if(q->front == -1){
        q->front = q->rear = 0;
    }

    q->arr[q->rear++] = ele;
}

int dequeue(struct Queue *q){
    if(isEmpty(*q)) return -1;

    if(q->front == q->rear) q->front = q->rear = -1;

    return(q->arr[q->front++]);
}

int front(struct Queue q){
    if(isEmpty(q)) return -1;

    return(q.arr[q.front]);
}

int main(){
    struct Queue q;
    initialise(&q);

    enqueue(&q, 5);
    enqueue(&q, 23);
    enqueue(&q, 64);

    printf(" %d\n", front(q));

    printf(" %d\n", dequeue(&q));
    printf(" %d\n", dequeue(&q));
    printf(" %d\n", front(q));

    return 0;
}
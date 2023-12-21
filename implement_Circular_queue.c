#include <stdio.h>
#include <stdlib.h>

struct Cqueue{
    int size;
    int *arr;
    int front , rear;
};

void initialise(struct Cqueue *cq,int n){
    cq->size = n;
    cq->arr = (int*)malloc(sizeof(int)*cq->size);
    cq->front = cq -> rear = -1;
}

int isEmpty(struct Cqueue cq){
    return (cq.front == -1);
}

int isFull(struct Cqueue q) {
    return ((q.rear + 1) % q.size == q.front);
}

void enqueue(struct Cqueue *cq, int ele) {
    if (isFull(*cq)) {
        return; 
    }

    if (cq->front == -1 && cq->rear == -1) {
        cq->front = cq->rear = 0;
        cq->arr[cq->rear] = ele;
    }
    else{
        cq->rear = (cq->rear + 1) % cq->size;
        cq->arr[cq->rear] = ele; 
    }
}


int dequeue(struct Cqueue *cq) {
    if (isEmpty(*cq)) return -1;

    int value = cq->arr[cq->front];
    if (cq->front == cq->rear) {
        cq->front = cq->rear = -1;
    } else {
        cq->front = (cq->front + 1) % cq->size;
    }
    return value;
}

int front(struct Cqueue cq){
    if (isEmpty(cq)) return -1;

    return cq.arr[cq.front];

}

int main() {
    struct Cqueue cq;
    initialise(&cq, 5); 

    enqueue(&cq, 10);
    enqueue(&cq, 20);
    enqueue(&cq, 30);
    enqueue(&cq, 40);
    enqueue(&cq, 50);

    enqueue(&cq, -0);
    enqueue(&cq, -1);
    enqueue(&cq, -2);
    enqueue(&cq, -3);

    if (isFull(cq)) {
        printf("\nQueue is full.\n");
    }

    printf("Front element: %d\n", front(cq));

    printf("Dequeued: %d\n", dequeue(&cq));
    printf("Dequeued: %d\n", dequeue(&cq));

    enqueue(&cq, 60);
    enqueue(&cq, 70);

    while (!isEmpty(cq)) {
        printf("Dequeued: %d\n", dequeue(&cq));
    }

    if (isEmpty(cq)) {
        printf("Queue is empty.\n");
    }

    return 0;
}

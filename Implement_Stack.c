#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    int size;
    int* arr;
};

void initialise(struct Stack *st) {
    st->top = -1;
    st->size = 10000;
    st->arr = (int*)malloc(sizeof(int) * st->size);
}

int isFull(struct Stack st) {
    return (st.top == st.size - 1);
}

int isEmpty(struct Stack st) {
    return (st.top == -1);
}

void push(struct Stack *st, int ele) {
    if (isFull(*st)) 
        printf("Stack is Full\n");
    else {
        st->arr[++st->top] = ele;
    }
}

int pop(struct Stack *st) {
    if (isEmpty(*st)) 
        return (-1);
    else {
        return st->arr[st->top--];
    }
}

int peek(struct Stack st) {
    if (isEmpty(st)) 
        return (-1);
    else {
        return st.arr[st.top];
    }
}

int main() {
    struct Stack st;
    initialise(&st);

    push(&st, 10);
    push(&st, 20);
    push(&st, 30);

    printf(" %d\n", peek(st));

    printf(" %d\n", pop(&st));
    printf(" %d\n", pop(&st));
    printf(" %d\n", peek(st));

    return 0;
}

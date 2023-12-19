#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Stack {
    int top;
    int size;
    int *arr;
};

void initialise(struct Stack *st) {
    st->top = -1;
    st->size = 10000;
    st->arr = (int *)malloc(sizeof(int) * st->size);
}

void push(struct Stack *st, int ele) {
    if (st->top < st->size - 1) {
        st->arr[++st->top] = ele;
    }
}

int pop(struct Stack *st) {
    if (st->top == -1) {
        return -1;
    } else {
        return st->arr[st->top--];
    }
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int main() {  
    int n;
    scanf("%d",&n);

    while(n){
        struct Stack st;
        initialise(&st);

        char str[100];
        scanf(" %[^\n]",str);

        int i = 0;
        while(str[i]!='?'){
            if(isdigit(str[i])){
                int num = 0;
                while (isdigit(str[i]))
                {
                    num = num*10 + (str[i] - '0');
                    i++;
                }
                push(&st,num);
            }
            else if(isOperator(str[i])){
                int a = pop(&st);
                int b = pop(&st);

                switch (str[i])
                {
                case '+':
                    push(&st,a+b);
                    break;
                case '-':
                    push(&st,b-a);
                    break;
                case '*':
                    push(&st,a*b);
                    break;
                case '/':
                    push(&st,b/a);
                    break;
                default:
                    break;
                }
            }
            i++;
        }
        printf("%d\n",pop(&st));
        n--;
    }
    return 0;
}

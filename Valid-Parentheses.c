#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Stack {
    int top;
    int size;
    char *arr;
};

void initialise(struct Stack *st) {
    st->top = -1;
    st->size = 10000;
    st->arr = (char*)malloc(sizeof(char) * st->size);
}

void push(struct Stack *st, char ele) {
    if (st->top == st->size - 1) {
        printf("Overflow\n");
    } else {
        st->arr[++st->top] = ele;
    }
}

char pop(struct Stack *st) {
    if (st->top == -1) {
        return '\0';
    } else {
        char ele = st->arr[st->top--];
        return ele;
    }
}

char peek(struct Stack st) {
    if (st.top == -1) return '\0';
    return st.arr[st.top];
}

bool isEmpty(struct Stack st) {
    return st.top == -1;
}

bool isValid(char* s) {
    struct Stack st;
    initialise(&st);

    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            push(&st, s[i]);
        } else {
            if (isEmpty(st) || (s[i] == ')' && peek(st) != '(') || 
               (s[i] == ']' && peek(st) != '[') || (s[i] == '}' && peek(st) != '{')) {
                return false;
            }
            pop(&st);
        }
    }

    return isEmpty(st);
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    if (isValid(input)) {
        printf("balanced brackets.\n");
    } else {
        printf("unbalanced brackets.\n");
    }

    return 0;
}

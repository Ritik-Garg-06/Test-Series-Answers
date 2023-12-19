#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int top;
    int size;
    char *arr;
};

void initialise(struct Stack *st){
    st->top = -1;
    st->size = 10000;
    st->arr = (char*)malloc(sizeof(char)*st->size);
}

int isEmpty(struct Stack *st) {
    return st->top == -1;
}

int isFull(struct Stack *st) {
    return st->top == st->size - 1;
}

void push(struct Stack *st, char ele) {
    if (!isFull(st)) {
        st->arr[++st->top] = ele;
    }
}

char pop(struct Stack* st){
    if(!isEmpty(st)){
        return st->arr[st->top--];
    }
    return '\0';
}

char peek(struct Stack *st) {
    if (!isEmpty(st)) {
        return st->arr[st->top];
    }
    return '\0';
}

char* removeDuplicateLetters(char* s) {
    struct Stack st;
    initialise(&st);

    int *freq = (int*)calloc(sizeof(int),26);
    int *visited = (int*)calloc(sizeof(int),26);

    int len = strlen(s);

    for(int i = 0; i < len; i++){
        freq[s[i]-'a']++;
    }   

    for(int i = 0; i < len; i++){
        char ch = s[i];
        freq[ch-'a']--;
        if(visited[ch-'a']) continue;

        while(!isEmpty(&st) && peek(&st) > ch && freq[peek(&st) - 'a'] > 0){
            char rem = pop(&st);
            visited[rem - 'a'] = 0;
        }
        push(&st,ch);
        visited[ch - 'a'] = 1;
    }

    int n = 0;
    struct Stack tempSt = st; 
    while (!isEmpty(&tempSt)) {
        pop(&tempSt);
        n++;
    }

    char *arr = (char *)malloc(sizeof(char) * (n+1)); 
    int i = n - 1; 
    while (!isEmpty(&st)) {
        arr[i--] = pop(&st); 
    }

    arr[n] = '\0';

    return arr;
}

int main() {
    char s[] = "bcabc"; 

    char *result = removeDuplicateLetters(s);

    printf("Result: %s\n", result);

    return 0;
}

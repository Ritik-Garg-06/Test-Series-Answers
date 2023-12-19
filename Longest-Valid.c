#include <stdio.h>
#include <string.h>

int maxi(int a, int b) {
    return (a > b) ? a : b;
}

int longestValidParentheses(char* s) {
    int open = 0, close = 0, max = 0;

    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == '(')
            open++;
        else if (c == ')')
            close++;

        if (open == close) {
            max = maxi(max, open + close);
        }
        if (close > open)
            close = open = 0;
    }

    open = close = 0;

    for (int i = n - 1; i >= 0; i--) {
        char c = s[i];
        if (c == '(')
            open++;
        else if (c == ')')
            close++;

        if (open == close) {
            max = maxi(max, open + close);
        }
        if (open > close)
            close = open = 0;
    }

    return max;
}

int main() {
    char input[] = "((())()";
    int result = longestValidParentheses(input);
    printf("%d\n", result);

    return 0;
}

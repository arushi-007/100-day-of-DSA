#include <stdio.h>
#define MAX 1000   
int stack[MAX];
int top = -1;
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    top--;
}
int main() {
    int n, m, i, elem;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &elem);
        push(elem);
    }
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        pop();
    }
    if (top == -1) {
        printf("Empty Stack\n");
    } else {
        for (i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
    return 0;
}
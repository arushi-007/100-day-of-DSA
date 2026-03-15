#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Stack {
    int *arr;
    int top;
    int capacity;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

void enqueue(struct Queue* q, int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(struct Queue* q) {
    if (q->front == NULL) return -1;
    struct Node* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return val;
}

void initStack(struct Stack* s, int capacity) {
    s->arr = (int*)malloc(sizeof(int) * capacity);
    s->top = -1;
    s->capacity = capacity;
}

void push(struct Stack* s, int x) {
    if (s->top == s->capacity - 1) return;
    s->arr[++s->top] = x;
}

int pop(struct Stack* s) {
    if (s->top == -1) return -1;
    return s->arr[s->top--];
}

int main() {
    int N;
    scanf("%d", &N);

    struct Queue q;
    initQueue(&q);

    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        enqueue(&q, x);
    }

    struct Stack s;
    initStack(&s, N);

    while (q.front != NULL) {
        push(&s, dequeue(&q));
    }

    while (s.top != -1) {
        printf("%d ", pop(&s));
    }

    return 0;
}
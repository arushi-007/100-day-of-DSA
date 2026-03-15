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

void initQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (q->front == NULL) {
        q->front = q->rear = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = q->front;
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void dequeue(struct Queue* q) {
    if (q->front == NULL) return;
    if (q->front == q->rear) return;
    q->rear = q->front;
    q->front = q->front->next;
}

void printQueue(struct Queue* q) {
    if (q->front == NULL) return;
    struct Node* temp = q->front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != q->front);
}

int main() {
    int n, m;
    scanf("%d", &n);
    struct Queue q;
    initQueue(&q);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(&q, x);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        dequeue(&q);
    }
    printQueue(&q);
    return 0;
}
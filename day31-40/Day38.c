#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int deque[MAX];
int front = -1, rear = -1;

int empty() {
    return (front == -1);
}

int size() {
    if (empty()) return 0;
    return rear - front + 1;
}

void push_front(int x) {
    if (front <= 0) {
        printf("Deque overflow\n");
        return;
    }
    deque[--front] = x;
}

void push_back(int x) {
    if (rear == MAX - 1) {
        printf("Deque overflow\n");
        return;
    }
    if (empty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    deque[rear] = x;
}

int pop_front() {
    if (empty()) return -1;
    int val = deque[front];
    if (front == rear) front = rear = -1;
    else front++;
    return val;
}

int pop_back() {
    if (empty()) return -1;
    int val = deque[rear];
    if (front == rear) front = rear = -1;
    else rear--;
    return val;
}

int front_val() {
    if (empty()) return -1;
    return deque[front];
}

int back_val() {
    if (empty()) return -1;
    return deque[rear];
}

void clear() {
    front = rear = -1;
}

void reverse() {
    if (empty()) return;
    int i = front, j = rear;
    while (i < j) {
        int tmp = deque[i];
        deque[i] = deque[j];
        deque[j] = tmp;
        i++; j--;
    }
}

void sort() {
    if (empty()) return;
    for (int i = front; i <= rear; i++) {
        for (int j = i + 1; j <= rear; j++) {
            if (deque[j] < deque[i]) {
                int tmp = deque[i];
                deque[i] = deque[j];
                deque[j] = tmp;
            }
        }
    }
}

void printDeque() {
    if (empty()) {
        printf("Deque is empty\n");
        return;
    }
    for (int i = front; i <= rear; i++) {
        printf("%d ", deque[i]);
    }
    printf("\n");
}

int main() {
    push_back(10);
    push_back(20);
    push_front(5);
    printDeque();       // 5 10 20
    printf("%d\n", pop_back());   // 20
    printf("%d\n", front_val());  // 5
    push_back(15);
    push_back(25);
    reverse();
    printDeque();       // 25 15 10 5
    sort();
    printDeque();       // 5 10 15 25
    clear();
    printDeque();       // Deque is empty
    return 0;
}
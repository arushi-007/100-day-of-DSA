#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct QNode {
    struct TreeNode* node;
    int hd;
};

struct QNode queue[2000];
int front = 0, rear = 0;

void enqueue(struct TreeNode* node, int hd) {
    queue[rear].node = node;
    queue[rear].hd = hd;
    rear++;
}

struct QNode dequeue() {
    return queue[front++];
}

typedef struct {
    int* arr;
    int size;
    int capacity;
} Vector;

Vector* createVector() {
    Vector* v = (Vector*)malloc(sizeof(Vector));
    v->size = 0;
    v->capacity = 10;
    v->arr = (int*)malloc(sizeof(int) * v->capacity);
    return v;
}

void push(Vector* v, int val) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->arr = (int*)realloc(v->arr, sizeof(int) * v->capacity);
    }
    v->arr[v->size++] = val;
}

#define OFFSET 1000
Vector* map[2000];

void verticalOrder(struct TreeNode* root) {
    if (!root) return;

    enqueue(root, 0);
    int minHD = 0, maxHD = 0;
    while (front < rear) {
        struct QNode q = dequeue();
        struct TreeNode* node = q.node;
        int hd = q.hd;

        if (!map[hd + OFFSET]) {
            map[hd + OFFSET] = createVector();
        }
        push(map[hd + OFFSET], node->val);

        if (node->left) enqueue(node->left, hd - 1);
        if (node->right) enqueue(node->right, hd + 1);

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;
    }

    for (int i = minHD; i <= maxHD; i++) {
        Vector* v = map[i + OFFSET];
        if (v) {
            for (int j = 0; j < v->size; j++) {
                printf("%d ", v->arr[j]);
            }
            printf("\n");
        }
    }
}
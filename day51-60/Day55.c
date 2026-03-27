#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left, *right;
};

struct Queue {
    struct Node **arr;
    int front, rear, size;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->arr = (struct Node**)malloc(sizeof(struct Node*) * size);
    q->front = q->rear = 0;
    q->size = size;
    return q;
}

void enqueue(struct Queue* q, struct Node* node) {
    q->arr[q->rear++] = node;
}

struct Node* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Queue* q = createQueue(n);
    enqueue(q, root);
    int i = 1;
    while (!isEmpty(q) && i < n) {
        struct Node* node = dequeue(q);
        if (arr[i] != -1) {
            node->left = newNode(arr[i]);
            enqueue(q, node->left);
        }
        i++;
        if (i < n && arr[i] != -1) {
            node->right = newNode(arr[i]);
            enqueue(q, node->right);
        }
        i++;
    }
    return root;
}

void rightView(struct Node* root) {
    if (!root) return;
    struct Queue* q = createQueue(1000);
    enqueue(q, root);
    while (!isEmpty(q)) {
        int size = q->rear - q->front;
        for (int i = 0; i < size; i++) {
            struct Node* node = dequeue(q);
            if (i == size - 1) {
                printf("%d ", node->val);
            }
            if (node->left) enqueue(q, node->left);
            if (node->right) enqueue(q, node->right);
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    struct Node* root = buildTree(arr, N);
    rightView(root);
    return 0;
}
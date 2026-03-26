#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(int val) {
    if (val == -1) return NULL;
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct TreeNode* root = newNode(arr[0]);
    struct TreeNode* queue[2000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int i = 1;
    while (i < n && front < rear) {
        struct TreeNode* curr = queue[front++];
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    return root;
}

void zigzagTraversal(struct TreeNode* root) {
    if (!root) return;
    struct TreeNode* queue[2000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int leftToRight = 1;
    while (front < rear) {
        int levelSize = rear - front;
        int* temp = (int*)malloc(sizeof(int) * levelSize);
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];
            int index = leftToRight ? i : (levelSize - 1 - i);
            temp[index] = node->val;
            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }
        for (int i = 0; i < levelSize; i++) {
            printf("%d ", temp[i]);
        }
        free(temp);
        leftToRight = !leftToRight;
    }
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    struct TreeNode* root = buildTree(arr, N);
    zigzagTraversal(root);
    return 0;
}
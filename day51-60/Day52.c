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
    if (n == 0) return NULL;
    struct TreeNode* nodes[n];
    for (int i = 0; i < n; i++) {
        nodes[i] = newNode(arr[i]);
    }
    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int leftIndex = 2 * i + 1;
            int rightIndex = 2 * i + 2;
            if (leftIndex < n) nodes[i]->left = nodes[leftIndex];
            if (rightIndex < n) nodes[i]->right = nodes[rightIndex];
        }
    }
    return nodes[0];
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL || root == p || root == q) return root;
    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left && right) return root;
    return left ? left : right;
}

struct TreeNode* search(struct TreeNode* root, int val) {
    if (root == NULL) return NULL;
    if (root->val == val) return root;
    struct TreeNode* left = search(root->left, val);
    if (left) return left;
    return search(root->right, val);
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    int pVal, qVal;
    scanf("%d %d", &pVal, &qVal);

    struct TreeNode* root = buildTree(arr, N);
    struct TreeNode* p = search(root, pVal);
    struct TreeNode* q = search(root, qVal);

    struct TreeNode* lca = lowestCommonAncestor(root, p, q);
    printf("%d\n", lca->val);

    return 0;
}
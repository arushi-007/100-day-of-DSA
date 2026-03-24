#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    while (root != NULL) {
        if (p->val < root->val && q->val < root->val) {
            root = root->left;
        } else if (p->val > root->val && q->val > root->val) {
            root = root->right;
        } else {
            return root;
        }
    }
    return NULL;
}

struct TreeNode* search(struct TreeNode* root, int val) {
    if (root == NULL || root->val == val) return root;
    if (val < root->val) return search(root->left, val);
    return search(root->right, val);
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

    int pVal, qVal;
    scanf("%d %d", &pVal, &qVal);

    struct TreeNode* root = NULL;
    for (int i = 0; i < N; i++) {
        root = insert(root, arr[i]);
    }

    struct TreeNode* p = search(root, pVal);
    struct TreeNode* q = search(root, qVal);

    struct TreeNode* lca = lowestCommonAncestor(root, p, q);
    printf("%d\n", lca->val);

    return 0;
}
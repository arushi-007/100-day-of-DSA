#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int key;
    int count;
    struct Node* next;
} Node;
int hash(int key, int size) {
    return (key % size + size) % size;
}
void insert(Node** table, int size, int key, int* totalCount) {
    int idx = hash(key, size);
    Node* curr = table[idx];
    while (curr) {
        if (curr->key == key) {
            *totalCount += curr->count; 
            curr->count++;
            return;
        }
        curr = curr->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->count = 1;
    newNode->next = table[idx];
    table[idx] = newNode;
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int size = 2 * n + 1; 
    Node** table = (Node**)calloc(size, sizeof(Node*));
    int prefixSum = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];
        if (prefixSum == 0) count++;
        insert(table, size, prefixSum, &count);
    }
    printf("%d\n", count);
    return 0;
}
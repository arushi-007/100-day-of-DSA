#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node* createCircularList(int arr[], int n) {
    if (n == 0) return NULL;

    struct Node* head = createNode(arr[0]);
    struct Node* temp = head;

    for (int i = 1; i < n; i++) {
        temp->next = createNode(arr[i]);
        temp = temp->next;
    }
    temp->next = head;

    return head;
}
void traverseCircularList(struct Node* head, int n) {
    if (head == NULL) return;

    struct Node* temp = head;
    for (int i = 0; i < n; i++) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct Node* head = createCircularList(arr, n);
    traverseCircularList(head, n);
    return 0;
}
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
struct Node* appendNode(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}
struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) return head;
    int length = 1;
    struct Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
        length++;
    }
    tail->next = head;
    k = k % length;
    int stepsToNewHead = length - k;
    struct Node* newTail = head;
    for (int i = 1; i < stepsToNewHead; i++) {
        newTail = newTail->next;
    }
    struct Node* newHead = newTail->next;
    newTail->next = NULL; 
    return newHead;
}
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    int n, k, val;
    struct Node* head = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        head = appendNode(head, val);
    }
    scanf("%d", &k);
    head = rotateRight(head, k);
    printList(head);
    return 0;
}
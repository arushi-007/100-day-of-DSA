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
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    struct Node* result = NULL;

    if (l1->data <= l2->data) {
        result = l1;
        result->next = mergeLists(l1->next, l2);
    } else {
        result = l2;
        result->next = mergeLists(l1, l2->next);
    }
    return result;
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
    int n, m, val;
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertEnd(&list1, val);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        insertEnd(&list2, val);
    }
    struct Node* mergedList = mergeLists(list1, list2);
    printList(mergedList);
    return 0;
}
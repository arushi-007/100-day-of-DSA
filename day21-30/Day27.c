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
int findIntersection(struct Node* head1, struct Node* head2) {
    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;
    while (ptr1 != ptr2) {
        ptr1 = (ptr1 == NULL) ? head2 : ptr1->next;
        ptr2 = (ptr2 == NULL) ? head1 : ptr2->next;
    }

    if (ptr1 != NULL) {
        return ptr1->data;
    }
    return -1; 
}
int main() {
    int n, m, i, val;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        head1 = appendNode(head1, val);
    }
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &val);
        head2 = appendNode(head2, val);
    }

    int intersection = findIntersection(head1, head2);
    if (intersection == -1) {
        printf("No Intersection\n");
    } else {
        printf("%d\n", intersection);
    }

    return 0;
}
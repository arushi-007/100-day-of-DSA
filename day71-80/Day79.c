#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct {
    int v, w;
    struct Node* next;
} Node;

Node* adj[100005];  
int dist[100005];
void addEdge(int u, int v, int w) {
    Node* node1 = (Node*)malloc(sizeof(Node));
    node1->v = v; node1->w = w; node1->next = adj[u];
    adj[u] = node1;

    Node* node2 = (Node*)malloc(sizeof(Node));
    node2->v = u; node2->w = w; node2->next = adj[v];
    adj[v] = node2;
}
typedef struct {
    int v, d;
} HeapNode;

HeapNode heap[200005];
int heapSize = 0;

void swap(HeapNode* a, HeapNode* b) {
    HeapNode t = *a; *a = *b; *b = t;
}

void push(int v, int d) {
    heap[++heapSize].v = v;
    heap[heapSize].d = d;
    int i = heapSize;
    while (i > 1 && heap[i].d < heap[i/2].d) {
        swap(&heap[i], &heap[i/2]);
        i /= 2;
    }
}

HeapNode pop() {
    HeapNode root = heap[1];
    heap[1] = heap[heapSize--];
    int i = 1;
    while (1) {
        int smallest = i;
        if (2*i <= heapSize && heap[2*i].d < heap[smallest].d) smallest = 2*i;
        if (2*i+1 <= heapSize && heap[2*i+1].d < heap[smallest].d) smallest = 2*i+1;
        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }
    return root;
}

int empty() { return heapSize == 0; }

void dijkstra(int n, int src) {
    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;
    dist[src] = 0;
    push(src, 0);

    while (!empty()) {
        HeapNode hn = pop();
        int u = hn.v;
        if (hn.d > dist[u]) continue;

        for (Node* p = adj[u]; p; p = p->next) {
            int v = p->v, w = p->w;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int src;
    scanf("%d", &src);

    dijkstra(n, src);

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) printf("INF ");
        else printf("%d ", dist[i]);
    }
    printf("\n");
    return 0;
}
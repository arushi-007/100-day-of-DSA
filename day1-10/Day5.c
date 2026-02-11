#include <stdio.h>
#include <stdlib.h>
int main() {
    int p, q;
    scanf("%d", &p);
    int* log1 = (int*)malloc(p * sizeof(int));
    for (int i = 0; i < p; i++) {
        scanf("%d", &log1[i]);
    }
    scanf("%d", &q);
    int* log2 = (int*)malloc(q * sizeof(int));
    for (int i = 0; i < q; i++) {
        scanf("%d", &log2[i]);
    }
    int* merged = (int*)malloc((p + q) * sizeof(int));
    int i = 0, j = 0, k = 0;
    while (i < p && j < q) {
        if (log1[i] <= log2[j]) {
            merged[k++] = log1[i++];
        } else {
            merged[k++] = log2[j++];
        }
    }
    while (i < p) {
        merged[k++] = log1[i++];
    }
    while (j < q) {
        merged[k++] = log2[j++];
    }
    for (int x = 0; x < p + q; x++) {
        printf("%d ", merged[x]);
    }
    printf("\n");
    free(log1);
    free(log2);
    free(merged);
    return 0;
}
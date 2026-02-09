#include <stdio.h>
int linearSearch(int arr[], int n, int k, int *comparisons) {
    for (int i = 0; i < n; i++) {
        (*comparisons)++;  
        if (arr[i] == k) {
            return i;  
        }
    }
    return -1;  
}

int main() {
    int n, k;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);

    int comparisons = 0;
    int index = linearSearch(arr, n, k, &comparisons);

    if (index != -1) {
        printf("Found at index %d\n", index);
    } else {
        printf("Not Found\n");
    }
    printf("Comparisons = %d\n", comparisons);

    return 0;
}
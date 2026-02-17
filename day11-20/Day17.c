#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    int max = nums[0];
    int min = nums[0];
    for (int i = 1; i < n; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
        if (nums[i] < min) {
            min = nums[i];
        }
    }
    printf("Maximum = %d\n", max);
    printf("Minimum = %d\n", min);
    return 0;
}
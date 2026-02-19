#include <stdio.h>
int kadaneMax(int* arr, int n) {
    int max_so_far = arr[0], curr = arr[0];
    for (int i = 1; i < n; i++) {
        curr = (arr[i] > curr + arr[i]) ? arr[i] : curr + arr[i];
        if (curr > max_so_far) max_so_far = curr;
    }
    return max_so_far;
}
int kadaneMin(int* arr, int n) {
    int min_so_far = arr[0], curr = arr[0];
    for (int i = 1; i < n; i++) {
        curr = (arr[i] < curr + arr[i]) ? arr[i] : curr + arr[i];
        if (curr < min_so_far) min_so_far = curr;
    }
    return min_so_far;
}
int maxSubarraySumCircular(int* nums, int n) {
    int max_normal = kadaneMax(nums, n);
    if (max_normal < 0) return max_normal; 

    int total_sum = 0;
    for (int i = 0; i < n; i++) total_sum += nums[i];

    int min_subarray = kadaneMin(nums, n);
    int max_circular = total_sum - min_subarray;

    return (max_normal > max_circular) ? max_normal : max_circular;
}
int main() {
    int nums[] = {1, -2, 3, -2};
    int n = sizeof(nums) / sizeof(nums[0]);

    printf("%d\n", maxSubarraySumCircular(nums, n)); 
    return 0;
}
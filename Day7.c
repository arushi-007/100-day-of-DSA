#include <stdio.h>
int fib(int n) {
    if (n == 0) 
        return 0;
    else if (n == 1) 
        return 1;
    else 
        return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    printf("Fibonacci number at position %d is %d\n", n, fib(n));
    return 0;
}
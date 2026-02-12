#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char s[100];
    scanf("%s", s);

    int left = 0;
    int right = strlen(s) - 1;
    bool isPalindrome = true;

    while (left < right) {
        if (s[left] != s[right]) {
            isPalindrome = false;
            break;
        }
        left++;
        right--;
    }

    if (isPalindrome) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
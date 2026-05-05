// ==========================================
// Program: Check Palindrome using Two Pointers
// ==========================================

#include <stdio.h>
#include <string.h>

int main() {

    char s[1000];
    int left, right;
    int isPalindrome = 1;

    scanf("%s", s);

    left = 0;
    right = strlen(s) - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            isPalindrome = 0;
            break;
        }
        left++;
        right--;
    }
    if (isPalindrome == 1)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}

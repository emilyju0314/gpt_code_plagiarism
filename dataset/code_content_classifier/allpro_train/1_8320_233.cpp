#include <bits/stdc++.h>
int palindrome(int n) { return (n % 10) * 10 + n / 10; }
int main() {
  int a, b;
  scanf("%d:%d", &a, &b);
  while (1) {
    if (a >= 6 && a <= 9) {
      printf("10:01\n");
      return 0;
    } else if (a >= 16 && a <= 19) {
      printf("20:02\n");
      return 0;
    }
    int c = palindrome(a);
    if (c > b) {
      printf("%02d:%02d\n", a, c);
      return 0;
    }
    a++;
    b = -1;
    if (a == 24) {
      printf("00:00\n");
      return 0;
    }
  }
  return 0;
}

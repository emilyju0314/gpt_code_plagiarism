#include <bits/stdc++.h>
using namespace std;
const int N = 1001000;
char s[N];
int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  int P = n + 1;
  for (int i = 1; i <= n; i++)
    if (s[i] == '.') P = i;
  int L = 1;
  while (L <= n && (s[L] == '.' || s[L] == '0')) L++;
  int R = n;
  while (R >= 0 && (s[R] == '.' || s[R] == '0')) R--;
  if (L > R) {
    puts("0");
    return 0;
  }
  for (int i = L; i <= R; i++) {
    if (i == L + 1) putchar('.');
    if (s[i] != '.') putchar(s[i]);
  }
  if (P - L - 1) printf("E%d", (P - L - 1 < 0) ? P - L : P - L - 1);
  return 0;
}

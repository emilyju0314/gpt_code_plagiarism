#include <bits/stdc++.h>
int n, m;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &m);
    if (m & 1) {
      puts("First");
      return 0;
    }
  }
  puts("Second");
  return 0;
}

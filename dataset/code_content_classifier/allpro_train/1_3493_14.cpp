#include <bits/stdc++.h>
int main() {
  int n, str[105], tp;
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &str[i]);
    }
    int mx = 0;
    for (int i = 0; i < n; i++) {
      tp = str[i];
      if (tp > mx) mx = tp;
      for (int j = i + 1; j < n; j++) {
        tp ^= str[j];
        if (tp > mx) mx = tp;
      }
    }
    printf("%d\n", mx);
  }
  return 0;
}

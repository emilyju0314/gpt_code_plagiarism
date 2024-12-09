#include <bits/stdc++.h>
using namespace std;
int n;
int a[1010], b[1010];
int S, W;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (; !a[n]; n--)
    ;
  S = INT_MAX;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) b[j] = a[j];
    for (int j = i; j <= n; j++)
      if (b[j]) b[j]--;
    int sum = 0, delta = 0;
    for (int j = 1, last = 0; j <= n; j++) {
      sum += b[j], delta += max(0, b[j] - last);
      last = b[j];
    }
    int T = 2 * n + 2 + (n - i) + 3 * sum + 2 * delta;
    if (T < S) {
      S = T, W = i;
    }
  }
  for (int i = W; i <= n; i++)
    if (a[i]) a[i]--;
  for (int i = 1; i <= n; i++) {
    for (; a[i];) {
      int j = i;
      for (; a[j]; a[j]--, j++)
        ;
      for (int k = 1; k <= j - i; k++) printf("AR");
      printf("A");
      for (int k = 1; k <= j - i; k++) printf("L");
      printf("A");
    }
    printf("AR");
  }
  printf("A");
  for (int i = W; i <= n; i++) printf("L");
  printf("A");
}

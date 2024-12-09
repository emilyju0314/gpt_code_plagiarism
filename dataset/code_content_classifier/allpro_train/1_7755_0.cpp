#include <bits/stdc++.h>
using namespace std;
int a[100000];
int erfen(int n, int target);
int main() {
  int n, max;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n);
  int t;
  scanf("%d", &t);
  while (t--) {
    int k, e = 0;
    int *c;
    scanf("%d", &k);
    if (k >= a[n - 1])
      printf("%d", n);
    else if (k < a[0])
      printf("0");
    else {
      int ans = 0;
      c = upper_bound(a, a + n, k);
      ans = (c - a);
      printf("%d", ans);
    }
    if (t >= 1) printf("\n");
  }
}

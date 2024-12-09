#include <bits/stdc++.h>
using namespace std;
int n, a[1010];
int main() {
  scanf("%d", &n);
  int maxv = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      for (int k = i; k <= j; k++) {
        a[k] = 1 - a[k];
      }
      int cnt = 0;
      for (int l = 0; l < n; l++) {
        if (a[l] == 1) cnt++;
      }
      if (cnt > maxv) maxv = cnt;
      for (int k = i; k <= j; k++) {
        a[k] = 1 - a[k];
      }
    }
  }
  printf("%d", maxv);
  return 0;
}

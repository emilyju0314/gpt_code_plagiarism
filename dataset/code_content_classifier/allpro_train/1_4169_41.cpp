#include <bits/stdc++.h>
using namespace std;
int n;
int a[100100];
int b[100100];
int map_a[100100];
int map_b[100100];
int checked[100100];
int ans = 0;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) scanf("%d", &b[i]);
  int pos1 = 0;
  int pos2 = 0;
  while (pos2 < n) {
    if (a[pos1] == b[pos2]) {
      checked[a[pos1]]++;
      pos1++;
      pos2++;
    } else {
      if (!checked[a[pos1]]) {
        ans++;
        checked[b[pos2]]++;
        pos2++;
      } else
        pos1++;
    }
  }
  printf("%d", ans);
}

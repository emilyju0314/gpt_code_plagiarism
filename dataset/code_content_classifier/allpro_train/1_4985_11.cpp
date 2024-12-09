#include <bits/stdc++.h>
using namespace std;
int freq[1025], a[1025];
int main() {
  int n, k, x, y;
  scanf("%d %d %d", &n, &k, &x);
  for (int i = 0; i < n; i++) {
    scanf("%d", &y);
    freq[y]++;
  }
  for (int i = 0; i < k; i++) {
    for (int i = 0; i <= 1024; i++) a[i] = freq[i];
    bool left = true;
    for (int i = 0; i <= 1024; i++) {
      if (a[i] == 0) continue;
      int p = i ^ x;
      freq[i] -= (a[i] + left) / 2;
      freq[p] += (a[i] + left) / 2;
      left = (a[i] + left) % 2 == 0 ? false : true;
    }
  }
  for (int i = 1024; i >= 0; i--)
    if (freq[i]) {
      printf("%d ", i);
      break;
    }
  for (int i = 0; i <= 1024; i++)
    if (freq[i]) {
      printf("%d\n", i);
      return 0;
    }
  return 0;
}

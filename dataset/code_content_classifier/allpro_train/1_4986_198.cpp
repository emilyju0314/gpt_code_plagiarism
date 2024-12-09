#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[111];
int vst[111];
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int cur = 0;
  int nbr = n;
  int j = 0;
  while (k--) {
    int r = a[j++] % nbr;
    r++;
    nbr--;
    int e;
    for (int i = cur; r; i = (i + 1) % n) {
      if (!vst[i]) {
        r--;
        e = i;
      }
    }
    vst[e] = 1;
    for (int i = e;; i = (i + 1) % n) {
      if (!vst[i]) {
        cur = i;
        break;
      }
    }
    cout << e + 1 << " ";
  }
}

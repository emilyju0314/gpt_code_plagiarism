#include <bits/stdc++.h>
using namespace std;
int compare(const void* pa, const void* pb) {
  int p1 = *(const int*)pa;
  int p2 = *(const int*)pb;
  if (p1 < p2)
    return -1;
  else if (p1 > p2)
    return 1;
  else if (p1 == p2)
    return 0;
}
int a[200500], b[200500];
int main() {
  int i, j, t, n, k = 200500;
  cin >> t;
  while (t--) {
    cin >> n;
    int cnt[k];
    int l, r, z = 0;
    for (j = 0; j < n; j++) {
      cin >> a[j];
      b[j] = a[j];
      cnt[a[j]]++;
    }
    qsort(b, n, sizeof(b[0]), compare);
    l = 0;
    r = n - 1;
    for (j = 0; j < n; j++) {
      if (cnt[b[j]] != 0) {
        if (a[l] == b[j]) {
          cnt[b[j]]--;
          l++;
        } else if (a[r] == b[j]) {
          cnt[b[j]]--;
          r--;
        } else {
          for (i = l; i <= r; i++) {
            if (a[i] == b[j]) {
              z = i;
              j--;
              l = i;
              break;
            } else {
              cnt[a[i]]--;
            }
          }
        }
      }
    }
    cout << z << endl;
  }
}

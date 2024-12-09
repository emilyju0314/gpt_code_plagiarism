#include <bits/stdc++.h>
using namespace std;
template <typename T>
void out(T x) {
  cout << x << endl;
  exit(0);
}
const int maxn = 1e6 + 5;
int n, k, a[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (k == 0) {
    int i = 0;
    int longest = 0;
    while (i < n) {
      if (a[i] == 0) {
        i++;
        continue;
      }
      int j = i;
      while (j < n && a[j] == 1) j++;
      longest = max(longest, j - i);
      i = j;
    }
    cout << longest << endl;
    for (int i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    cout << endl;
    return 0;
  }
  int i = 0, j = 0;
  int z = 0;
  int ans = 0;
  int x = -1, y = -1;
  while (j < n) {
    while (j < n) {
      if (a[j] == 0) {
        if (z == k) break;
        z++;
      }
      j++;
      assert(z <= k);
      if (j - i > ans) {
        ans = j - i;
        x = i;
        y = j;
      }
    }
    assert(z <= k);
    while (i < j) {
      if (a[i] == 0) z--;
      i++;
      if (z < k) break;
    }
  }
  cout << ans << endl;
  for (int k = x; k < y; k++) a[k] = 1;
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int v[200010];
int b[200010];
int c[200010];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
      cin >> v[i];
      b[i] = 0;
      c[i] = 0;
    }
    for (int i = 2; i <= n - 1; ++i) {
      b[i] = v[i] > v[i - 1] and v[i] > v[i + 1];
      c[i] = b[i];
    }
    for (int i = 1; i <= n; ++i) b[i] += b[i - 1];
    int mx = -1, id = -1;
    for (int i = 1; i <= n; ++i) {
      int val = b[i + k - 1] - b[i - 1];
      val -= c[i];
      val -= c[i + k - 1];
      if (val > mx) {
        mx = val;
        id = i;
      }
    }
    cout << mx + 1 << " " << id << "\n";
    for (int i = 0; i <= n; ++i) b[i] = c[i] = 0;
  }
  return 0;
}

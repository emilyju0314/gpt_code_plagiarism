#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  solve();
  return 0;
}
void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int i;
    int M[8001];
    M[0] = 0;
    vector<int> cnt(n + 1);
    for (i = 0; i < n; i++) {
      int k;
      cin >> k;
      M[i + 1] = k;
      M[i + 1] += M[i];
      cnt[k] += 1;
    }
    int j;
    int count = 0;
    for (i = 0; i < n; i++) {
      for (int j = i + 2; j < n + 1; j++) {
        int val = M[j] - M[i];
        if (val > n) break;
        if (val <= n) {
          count += cnt[val];
          cnt[val] = 0;
        }
      }
    }
    cout << count << endl;
  }
}

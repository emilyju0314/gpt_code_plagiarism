#include <bits/stdc++.h>
using namespace std;
const long long LLINF = 1e17 + 7;
const long long INF = 1e9;
const long long EPS = 1e-9 - 7;
const long long MAX = 1e5 + 7;
const long long MOD = 1e9 + 7;
int q, n, r, x[MAX];
int main() {
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> n >> r;
    set<int> s;
    bool wrote = false;
    for (int j = 0; j < n; j++) {
      int in;
      cin >> in;
      s.insert(in);
    }
    int k = 0;
    for (auto t : s) {
      x[k] = t;
      k++;
    }
    if (k == 1) {
      cout << 1 << endl;
      continue;
    }
    int cnt = 1;
    for (int j = k - 2; j >= 0; j--) {
      if (x[j] <= r * cnt) {
        cout << cnt << endl;
        wrote = true;
        break;
      } else {
        cnt++;
      }
    }
    if (wrote == false) {
      cout << cnt << endl;
    }
  }
  return 0;
}

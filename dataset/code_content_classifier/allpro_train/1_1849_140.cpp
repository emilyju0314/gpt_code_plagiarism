#include <bits/stdc++.h>
using namespace std;
long long k;
long long succ[10];
long long cnt = 0;
const long long mod = 1e9 + 7;
void recur(long long pos) {
  if (pos == k + 1) {
    for (long long i = 1; i <= k; i++) {
      long long u = i;
      bool flag = false;
      for (long long j = 0; j <= k; j++) {
        if (u == 1) {
          flag = true;
          break;
        } else {
          u = succ[u];
        }
      }
      if (!flag) {
        return;
      }
    }
    cnt++;
    cnt %= mod;
  } else {
    for (long long i = 1; i <= k; i++) {
      succ[pos] = i;
      recur(pos + 1);
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n >> k;
  recur(1);
  long long otherNodes = 1;
  for (long long i = 0; i < n - k; i++) {
    otherNodes *= n - k;
    otherNodes %= mod;
  }
  long long res = cnt * otherNodes;
  res %= mod;
  cout << res << endl;
}

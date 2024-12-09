#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll mod = 1e9 + 7;
const int inf = 5e6;
const int sz = 1e5 + 10;
int n;
int ar[sz];
int br[sz];
int dp[sz][4];
int rec(int x, int t) {
  if (x == n) return 1;
  int& ret = dp[x][t];
  if (~ret) return ret;
  ret = 0;
  for (int i = 0; i <= 3; i++) {
    if ((t | i) == ar[x] && (t & i) == br[x]) {
      ret |= rec(x + 1, i);
    }
  }
  return ret;
}
void print(int x, int t) {
  if (x == n) return;
  for (int i = 0; i <= 3; i++) {
    if ((t | i) == ar[x] && (t & i) == br[x]) {
      if (rec(x + 1, i)) {
        cout << i << " ";
        print(x + 1, i);
      }
    }
  }
}
int main() {
  while (cin >> n) {
    for (int i = 1; i < n; i++) cin >> ar[i];
    for (int i = 1; i < n; i++) cin >> br[i];
    memset(dp, -1, sizeof dp);
    int ans = 0;
    for (int i = 0; i <= 3; i++) ans |= rec(1, i);
    if (ans) {
      cout << "YES\n";
      for (int i = 0; i <= 3; i++)
        if (rec(1, i)) {
          cout << i << " ";
          print(1, i);
          cout << "\n";
          break;
        }
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}

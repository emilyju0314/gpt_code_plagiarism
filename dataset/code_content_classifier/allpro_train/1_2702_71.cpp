#include <bits/stdc++.h>
using namespace std;
using llong = long long;
inline char Flip(char x) { return (x == '0') ? '1' : '0'; }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  vector<int> ans;
  while (t--) {
    int n;
    cin >> n;
    n *= 2;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    vector<int> b;
    int i = n - 1;
    while (i >= 0) {
      int j = max_element(a.begin(), a.begin() + i + 1) - a.begin();
      b.push_back(i - j + 1);
      i = j - 1;
    }
    bitset<4001> dp;
    dp[0] = 1;
    for (int len : b) dp = dp | (dp << len);
    if (dp[n / 2])
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int toi[maxn];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  long long m;
  cin >> s >> m;
  int n = s.size();
  long long res = 0, tmp = 1;
  for (int i = 1; i <= n; i++) {
    toi[i] = s[i - 1] - '0';
    res = (res * 10 + toi[i]) % m;
    tmp = (tmp * 10) % m;
  }
  long long cur = res;
  for (int i = 1; i <= n; i++) {
    cur = ((cur * 10 - tmp * toi[i] + toi[i]) % m + m) % m;
    if (toi[i + 1]) res = min(res, cur);
  }
  cout << res << "\n";
}

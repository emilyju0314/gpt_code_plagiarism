#include <bits/stdc++.h>
using namespace std;
const long long lg = 61;
string Y;
long long x, y;
map<long long, bool> mp;
string doi(long long x) {
  string res = "";
  for (long long i = 0; i <= lg; i++) {
    if ((x >> i & 1)) {
      res = "1" + res;
    } else {
      res = "0" + res;
    }
  }
  while (res.size() >= 1 && res[0] == '0') {
    res.erase(0, 1);
  }
  return res;
}
long long dak(string s) {
  long long n = s.size() - 1;
  long long res = 0;
  for (char c : s) {
    res += (c - '0') * (1ll << n);
    n--;
  }
  return res;
}
void bfs() {
  queue<long long> q;
  q.push(x);
  mp[x] = 1;
  if (x == y) return;
  while (q.size()) {
    long long u = q.front();
    q.pop();
    string tmp = doi(u);
    string d = tmp + "1";
    long long mim = dak(d);
    reverse(tmp.begin(), tmp.end());
    if (mim <= 2e18) {
      if (mp.count(mim) == 0) {
        mp[mim] = 1;
        q.push(mim);
      }
      if (mim == y) return;
    }
    mim = dak(tmp);
    if (mim <= 2e18) {
      if (mp.count(mim) == 0) {
        mp[mim] = 1;
        q.push(mim);
      }
      if (mim == y) return;
    }
  }
}
void solve() {
  cin >> x >> y;
  Y = doi(y);
  bfs();
  if (mp.count(y) == 0) {
    cout << "NO";
  } else {
    cout << "YES";
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long test;
  test = 1;
  while (test--) {
    solve();
  }
}

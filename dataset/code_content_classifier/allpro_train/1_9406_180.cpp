#include <bits/stdc++.h>
using namespace std;
const long long base = 31;
const long long mod = 1e9 + 7;
const long long maxn = 2e5 + 7;
long long n;
string s, k;
vector<long long> v;
long long change(string s) {
  long long t = 0;
  for (auto i : s) {
    t = i - 48 + t * 10;
  }
  return t;
}
bool ss(string s, string t) {
  if (s.size() < t.size()) return 0;
  if (s.size() > t.size()) return 1;
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] != t[i]) {
      if (s[i] > t[i]) return 1;
      return 0;
    }
  }
  return 1;
}
void program() {
  cin >> s >> k;
  n = change(s);
  string t = "";
  t += k.back();
  k.pop_back();
  while (k.size()) {
    if (k.back() == '0') {
      string d = "";
      while (k.size()) {
        d = k.back() + d;
        k.pop_back();
        if (d.front() != '0') break;
      }
      string add = d + t;
      if (ss(add, s) == 1) {
        v.push_back(change(t));
        while (ss(d, s) == 1) {
          v.push_back(0);
          d.pop_back();
        }
        t = d;
      } else
        t = add;
    } else {
      string d = k.back() + t;
      if (ss(d, s) == 0) {
        t = d;
      } else {
        v.push_back(change(t));
        t = k.back();
      }
      k.pop_back();
    }
  }
  if (t != "") v.push_back(change(t));
  long long ans = 0;
  long long tich = 1;
  for (long long i : v) {
    ans += (i * tich);
    tich *= n;
  }
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  program();
}

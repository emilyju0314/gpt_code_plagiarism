#include <bits/stdc++.h>
using namespace std;
template <typename T>
void __read(T& a) {
  cin >> a;
}
template <typename T, typename... Args>
void __read(T& a, Args&... args) {
  cin >> a;
  __read(args...);
}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void Solve() {
  long long n;
  __read(n);
  string s, t;
  __read(s, t);
  auto check = [&](const string& p) {
    for (long long i = 1; i < p.length(); ++i) {
      if (p[i - 1] == s[0] && p[i] == s[1] || p[i - 1] == t[0] && p[i] == t[1])
        return false;
    }
    return true;
  };
  string p = "abc";
  do {
    string v1 = "";
    for (signed i = 0; i < (n); i++) v1.append(p);
    if (check(v1)) return void(cout << "YES\n" << v1);
    v1 = string(n, p[0]) + string(n, p[1]) + string(n, p[2]);
    if (check(v1)) return void(cout << "YES\n" << v1);
    v1 = "";
    for (signed i = 0; i < (n); i++) {
      v1.push_back(p[0]);
      v1.push_back(p[1]);
    }
    v1 += string(n, p[2]);
    if (check(v1)) return void(cout << "YES\n" << v1);
  } while (next_permutation((p).begin(), (p).end()));
  assert(false);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  Solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:20000007")
#pragma GCC optimize("unroll-loops")
const int N = (int)1e6 + 100;
const int maxn = (int)1e3 + 100;
const int base = (int)1e9;
const int mod = (int)1e9 + 7;
const int inf = INT_MAX;
const long long ll_inf = LLONG_MAX;
const long double pi = acos((long double)-1.0);
const long double eps = 1e-8;
void solve() {
  bool ok = false;
  string s;
  set<string> S;
  S.insert("great");
  S.insert("great!");
  S.insert("not bad");
  S.insert("don't touch me");
  S.insert("don't touch me!");
  S.insert("cool");
  S.insert("don't think so");
  for (int i = 0; i <= 9; ++i) {
    cout << i << '\n';
    cout.flush();
    getline(cin, s);
    if (s != "no") {
      if (S.count(s) != 0)
        cout << "normal\n";
      else
        cout << "grumpy\n";
      cout.flush();
      break;
    }
  }
}
int main() {
  int T = 1;
  for (; T; --T) solve();
  return 0;
}

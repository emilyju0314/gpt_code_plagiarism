#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:134217728")
const long long MOD = 1000000007;
const int INF = 1000000000;
const int MAXN = 200005;
const double EPS = 1e-6;
const int HASH_POW = 7;
const double PI = acos(-1.0);
using namespace std;
void my_return(int code) { exit(code); }
int main() {
  mt19937 mt_rand(time(NULL));
  int n;
  string s, t;
  cin >> n >> s >> t;
  int l = 0, r = n - 1;
  while (s[l] == t[l]) ++l;
  while (s[r] == t[r]) --r;
  int ans = 0;
  if (s.substr(l + 1, r - l) == t.substr(l, r - l)) ++ans;
  if (s.substr(l, r - l) == t.substr(l + 1, r - l)) ++ans;
  cout << ans;
  my_return(0);
}

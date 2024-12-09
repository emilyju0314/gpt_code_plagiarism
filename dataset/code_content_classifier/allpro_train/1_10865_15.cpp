#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
const int OO = (int)1e9 + 7;
const long long OOO = (long long)1e13 + 7;
const int MAX = 109;
char c1, c2, c3;
string s, s1, s2, s3;
long long n, m, k, t, q, a, b, c, d, e, f, x, y, z, sol, sum = 0;
long long ar[100009 * 2];
long long dp[109][5];
string ans;
map<string, bool> mp;
void fun(string s) {
  if (mp[s]) return;
  mp[s] = 1;
  ans = min(ans, s);
  string t = s;
  for (int i = 0; i < (int)s.size(); i++)
    if (s[i] == '9')
      s[i] = '0';
    else
      s[i]++;
  for (int i = (int)s.size() - 1; i > 0; i--) swap(t[i], t[i - 1]);
  fun(s);
  fun(t);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> s;
  ans = s;
  fun(s);
  cout << ans;
  cout << "\n\n";
  return 0;
}

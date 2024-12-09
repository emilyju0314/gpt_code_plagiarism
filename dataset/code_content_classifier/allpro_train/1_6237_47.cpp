#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 10;
const long long inf = 1e18;
const long long mod = 1e9 + 7;
const long long eps = 1e-9;
const char spc = 29;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
using namespace std;
string s;
bool ispal(string &s) {
  for (long long i = 0; i <= s.size() / 2; ++i)
    if (s[i] != s[(long long)s.size() - 1 - i]) return false;
  return true;
}
bool isonel(string &s) {
  char c = s[0];
  for (long long i = 0; i < s.size(); ++i)
    if (s[i] != c) return false;
  return true;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  for (long long i = 1; i < s.size(); ++i) {
    string t = s.substr(i, (long long)s.size() - i) + s.substr(0, i);
    if (t != s && ispal(t)) {
      cout << 1 << "\n";
      return 0;
    }
  }
  string sh = s.substr(0, s.size() / 2);
  for (long long i = 1; i < sh.size(); ++i) {
    string t = s.substr((long long)s.size() - i, i) +
               s.substr(i, (long long)s.size() - 2 * i) + s.substr(0, i);
    if (s != t && ispal(t)) {
      cout << 2 << "\n";
      return 0;
    }
  }
  if (!ispal(sh)) {
    cout << (s.size() % 2 + 1) << "\n";
    return 0;
  }
  if (!isonel(sh)) {
    if (s.size() % 2 == 1) {
      string rsh = sh;
      reverse(rsh.begin(), rsh.end());
      for (long long i = 1; i < sh.size(); ++i) {
        string t1 = sh.substr(i, (long long)sh.size() - i) + sh.substr(0, i) +
                    string(1, s[s.size() / 2]) + rsh;
        string t2 = sh.substr(i, (long long)sh.size() - i) +
                    string(1, s[s.size() / 2]) + rsh + sh.substr(0, i);
        if ((t1 != s && ispal(t1)) || (t2 != s && ispal(t2))) {
          cout << 2 << "\n";
          return 0;
        }
      }
      for (long long i = 1; i < sh.size(); ++i) {
        string t1 = sh.substr(i, (long long)sh.size() - i) +
                    string(1, s[s.size() / 2]) + sh.substr(0, i) + rsh;
        if ((t1 != s && ispal(t1))) {
          cout << 3 << "\n";
          return 0;
        }
      }
    }
    cout << (s.size() % 2 + 3) << "\n";
    return 0;
  }
  cout << "Impossible"
       << "\n";
}

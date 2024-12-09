#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f;
const long long mod = 1000000007;
const long double eps = 1e-14;
int i, j;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  string s, t;
  getline(cin, t);
  n = stoll(t);
  getline(cin, s);
  vector<int> v;
  for (int i = 0; i < s.size(); i++) {
    for (int j = i; j < s.size(); j++) {
      if (s[j] == '.' || s[j] == '?' || s[j] == '!' || s[j] == ':') {
        v.push_back(j - i + 1);
        i = j + 1;
        break;
      }
    }
  }
  for (int i = 0; i < v.size(); i++) {
    if (v[i] > n) {
      cout << "Impossible" << endl;
      return 0;
    }
  }
  int ans = 0, sz = 0;
  int st = 0, ed = 0;
  for (ed = 0; ed < v.size();) {
    ans++;
    sz = 0;
    while (sz + v[ed] <= n) {
      sz += v[ed] + 1;
      ed++;
    }
  }
  cout << ans << endl;
  return 0;
}

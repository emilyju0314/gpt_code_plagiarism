#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(0);
  long long n, c[26];
  memset(c, 0, sizeof(c));
  cin >> n;
  vector<string> s;
  string str;
  for (long long i = 0; i < n; i++) {
    cin >> str;
    sort(str.begin(), str.end());
    long long kk = 0;
    string p;
    for (kk = 0; kk < str.size() - 1; kk++) {
      if (str[kk] != str[kk + 1]) p = p + str[kk];
    }
    if (p.size() == 0) p = str[0];
    if (str[kk] != p[p.size() - 1]) p = p + str[kk];
    s.push_back(p);
  }
  sort(s.begin(), s.end());
  long long k = 0;
  map<long long, string> m;
  for (long long i = 0; i < n; i++) {
    {
      if (s[i] != s[i + 1]) {
        m.insert(make_pair(k, s[i]));
        k++;
      }
    }
  }
  cout << m.size();
  return 0;
}

#include <bits/stdc++.h>
const long long INF = 1e9;
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  long long ans = 0, i = 0;
  string s;
  cin >> s;
  set<long long> v;
  while (i < 100) {
    v.insert(i);
    i += 4;
  }
  for (int i = 0; i < s.size(); i++) {
    if (i + 1 < s.size()) {
      long long k = (s[i] - '0') * 10 + (s[i + 1] - '0');
      if (v.find(k) != v.end()) ans += i + 1;
    }
    long long k = s[i] - '0';
    if (v.find(k) != v.end()) ans++;
  }
  cout << ans;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const long long MAXI = 1000006;
long long a[MAXI];
map<long long, long long> mp;
map<pair<long long, long long>, long long> m;
int main() {
  for (int i = 0; i < 26; i++) {
    long long x;
    cin >> x;
    mp['a' - 0 + i] = x;
  }
  string s;
  cin >> s;
  long long ans = 0;
  long long cur_sum = 0;
  for (int i = 0; i < s.size(); i++) {
    ans += m[make_pair(s[i] - 0, cur_sum)];
    cur_sum += mp[s[i] - 0];
    m[make_pair(s[i] - 0, cur_sum)]++;
  }
  cout << ans << endl;
  return 0;
}

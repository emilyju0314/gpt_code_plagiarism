#include <bits/stdc++.h>
using namespace std;
const long long mod1 = 675685497, mod2 = 965936261;
string s, t;
int k;
long long ans;
bool used[2000];
set<pair<long long, long long> > q[2000];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> s >> t >> k;
  for (int i = 0; i < t.size(); i++) {
    used[i] = (t[i] == '0');
  }
  for (int i = 0; i < s.size(); i++) {
    long long h1 = 0, h2 = 0, p1 = 1, p2 = 1, cur = 0;
    for (int j = i; j < s.size(); j++) {
      cur += used[s[j] - 'a'];
      if (cur > k) {
        break;
      }
      h1 = (h1 + p1 * (s[j] - 'a' + 1)) % mod1;
      p1 = p1 * 31 % mod1;
      h2 = (h2 + p2 * (s[j] - 'a' + 1)) % mod2;
      p2 = p2 * 43 % mod2;
      q[j - i + 1].insert(make_pair(h1, h2));
    }
  }
  for (int i = 1; i <= 1500; i++) {
    ans += q[i].size();
  }
  cout << ans;
}

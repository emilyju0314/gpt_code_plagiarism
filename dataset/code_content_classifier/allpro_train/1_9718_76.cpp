#include <bits/stdc++.h>
long long max(long long x, long long y) { return x > y ? x : y; }
long long min(long long x, long long y) { return x < y ? x : y; }
using namespace std;
const long long N = 1e5 + 9;
string s;
int l;
void solve(string &ans, vector<int> &v, int k) {
  long long cnt[30];
  int occ[30];
  memset(cnt, 0, sizeof(cnt));
  memset(occ, 0, sizeof(occ));
  int i, j;
  for (j = 0; j < v.size(); j++) {
    occ[s[v[j]] - 'a']++;
    cnt[s[v[j]] - 'a'] += l - v[j];
  }
  for (i = 0; i < 26; i++) {
    if (k < cnt[i]) break;
    k -= cnt[i];
  }
  if (k < occ[i]) {
    ans.push_back(i + 'a');
    return;
  }
  k -= occ[i];
  ans.push_back(i + 'a');
  vector<int> vv;
  vv.clear();
  for (j = 0; j < v.size(); j++)
    if (s[v[j]] - 'a' == i && v[j] < l - 1) vv.push_back(v[j] + 1);
  solve(ans, vv, k);
}
int main() {
  int k;
  cin >> s >> k;
  l = s.size();
  if (1ll * l * (l + 1) / 2 < k) {
    cout << "No such line." << endl;
    return 0;
  }
  string ans = "";
  vector<int> v;
  for (int i = 0; i < l; i++) v.push_back(i);
  solve(ans, v, k - 1);
  cout << ans << endl;
  return 0;
}

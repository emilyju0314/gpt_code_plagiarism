#include <bits/stdc++.h>
using namespace std;
vector<int> calc(string s) {
  vector<int> cnt(52, 0);
  for (int i = 0; i < (int)s.length(); ++i) ++cnt[s[i] - 'a'];
  return cnt;
}
long long fw(string s) {
  vector<int> tree(32, 0);
  long long sum = 0;
  for (auto c : s) {
    int p = c - 'a' + 1;
    for (int x = p; x > 0; x -= x & -x) sum += tree[x];
    for (; p < 32; p += p & -p) ++tree[p];
  }
  return sum;
}
void solve() {
  int n;
  string s, f;
  cin >> n >> s >> f;
  if (s == f) {
    cout << "YES\n";
    return;
  }
  auto cs = calc(s), cf = calc(f);
  if (cs != cf) {
    cout << "NO\n";
    return;
  }
  int mv = 0;
  for (auto v : cs) mv = max(mv, v);
  if (mv >= 2) {
    cout << "YES\n";
    return;
  }
  long long fs = fw(s) & 1;
  long long ff = fw(f) & 1;
  cout << (fs == ff ? "YES" : "NO") << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int nt;
  cin >> nt;
  for (int t = 1; t <= nt; ++t) {
    solve();
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
vector<long long> ve[100005];
long long vis[100005], z;
void solve() {
  vector<long long> v;
  vector<pair<long long, long long>> vp;
  map<long long, long long> mp;
  set<long long> st;
  multiset<long long> mst;
  long long n = 0, m = 0, i = 0, j = 0, k = 0, c = 0, l = 0, r = 0, p = 0,
            q = 0, x = 0, y = 0, z = 0, flag = 0, sum = 0;
  long long a[300005] = {0}, b[300005] = {0}, ans[300005];
  string s, t;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x;
    v.push_back(abs(x));
  }
  sort(v.begin(), v.end());
  vector<long long>::iterator it;
  for (i = 0; i < n; i++) {
    it = upper_bound(v.begin(), v.end(), 2 * v[i]);
    c += ((it - v.begin()) - i - 1);
  }
  cout << c << endl;
}
bool imp = false;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  if (imp) cin >> t;
  long long j = t;
  while (t--) {
    solve();
  }
  return 0;
}

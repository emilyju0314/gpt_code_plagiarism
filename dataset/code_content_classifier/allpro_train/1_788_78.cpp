#include <bits/stdc++.h>
using namespace std;
long long n, second;
void input() {
  cin >> n >> second;
  second *= 8;
}
void solve() {
  vector<long long int> a(n);
  map<long long int, long long int> mp;
  for (auto &it : a) cin >> it, mp[it]++;
  a.clear();
  for (auto it : mp) a.emplace_back(it.first);
  long long l = 0, r = -1;
  while (r < ((long long int)(a).size())) {
    r++;
    if (r == ((long long int)(a).size())) break;
    long long siz = ceil(log2(r + 1)) * n;
    if (siz <= second)
      ;
    else
      break;
  }
  if (r == ((long long int)(a).size()))
    cout << 0;
  else {
    vector<long long int> c(((long long int)(a).size()));
    c[0] = mp[a[0]];
    for (long long i = 1; i < ((long long int)(a).size()); i++)
      c[i] = c[i - 1] + mp[a[i]];
    long long ans = c.back() - c[r - 1];
    while (r < ((long long int)(a).size())) {
      l++;
      long long z = c[l - 1] + c.back() - c[r];
      ans = min(ans, z);
      r++;
    }
    cout << ans;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(20);
  long long T = 1;
  while (T--) {
    input();
    solve();
  }
  cin.get();
  return 0;
}

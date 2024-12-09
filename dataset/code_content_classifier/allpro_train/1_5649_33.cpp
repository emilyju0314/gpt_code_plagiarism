#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long llinf = (1LL << 60);
const int inf = (1 << 30);
const int nmax = 5e5 + 50;
const long long mod = 1e9 + 7;
using namespace std;
int n, i, j, l, a;
map<long long, int> mp;
long long tot, h[nmax], v[nmax], f[nmax], b;
vector<int> p[nmax];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cerr.tie(0);
  cout.tie(0);
  srand(9904);
  cin >> n;
  for (i = 1; i <= n; i++)
    v[i] = ((long long)rand() << 30) + (rand() << 16) + rand();
  mp[0] = 1;
  for (i = 1; i <= n; i++) {
    cin >> a;
    b = f[a];
    f[a] = (f[a] + 1) % 3;
    h[i] = h[i - 1] + (f[a] - b) * v[a];
    if ((int)p[a].size() > 2)
      l = p[a][(int)p[a].size() - 3] - 1;
    else
      l = j - 1;
    for (; j <= l; j++) mp[h[j]]--;
    tot += 1LL * mp[h[i]];
    mp[h[i]]++;
    p[a].push_back(i);
  }
  cout << tot << endl;
  return 0;
}

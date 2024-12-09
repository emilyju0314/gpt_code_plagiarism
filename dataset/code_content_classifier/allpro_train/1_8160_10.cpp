#include <bits/stdc++.h>
const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long llinf = (1LL << 60);
const int inf = (1 << 30);
const int nmax = 1e3 + 5;
const long long mod = 1e9 + 7;
using namespace std;
int n, s, d, s1, s2, x, y, i, j, q, nr[2 * nmax], rs[nmax];
bitset<nmax> t[2 * nmax], g[nmax], b[nmax], tmp[(1 << 20) + 5], tt;
vector<int> id;
unordered_map<bitset<nmax>, int> mp;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cerr.tie(0);
  cout.tie(0);
  cin >> n >> s >> d;
  for (i = 0; i < s; i++) {
    cin >> y;
    while (y--) {
      cin >> x;
      b[i].set(--x);
    }
  }
  s1 = s * 2 / 3;
  s2 = s - s1;
  for (i = 1; i <= d; i++) {
    cin >> y;
    while (y--) {
      cin >> x;
      g[i].set(--x);
    }
    rs[i] = -1;
  }
  for (i = s - s2; i < s; i++) id.push_back(i);
  for (i = 0; i < (1 << s1); i++) {
    for (j = 0; j < s1; j++) {
      if (i & (1 << j)) {
        tmp[i] = tmp[i ^ (1 << j)] ^ b[j];
        break;
      }
    }
    if (mp.find(tmp[i]) == mp.end())
      mp[tmp[i]] = __builtin_popcount(i);
    else
      mp[tmp[i]] = min(mp[tmp[i]], __builtin_popcount(i));
  }
  for (i = 0; i < (1 << s2); i++) {
    for (j = 0; j < s2; j++)
      if (i & (1 << j)) t[i] ^= b[id[j]], nr[i]++;
  }
  for (i = 1; i <= d; i++) {
    for (j = 0; j < (1 << s2); j++) {
      tt = t[j] ^ g[i];
      if (mp.find(tt) == mp.end()) continue;
      if (rs[i] == -1)
        rs[i] = mp[tt] + nr[j];
      else
        rs[i] = min(rs[i], mp[tt] + nr[j]);
    }
  }
  for (i = 1; i <= d; i++) cout << rs[i] << '\n';
  return 0;
}

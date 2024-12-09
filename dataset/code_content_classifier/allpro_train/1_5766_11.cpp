#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const long long maxn = 1e6 + 10;
bool sp;
map<long long, long long> n, m, s;
long long N, M, second;
long long par[maxn];
long long tavan(long long a, long long b) {
  if (b == 0) return 1;
  return (b % 2 ? a : 1) * tavan(a * a, b / 2);
}
void factorize(long long num, map<long long, long long> &mp) {
  while (num > 1) {
    if (par[num] == 0) {
      mp[num]++;
      return;
    }
    mp[par[num]]++;
    num /= par[num];
  }
}
void Get(map<long long, long long> &mp, long long &num) {
  mp.clear();
  long long x1, x2, x3;
  cin >> x1 >> x2 >> x3;
  num = x1 * x2 * x3;
  factorize(x1, mp);
  factorize(x2, mp);
  factorize(x3, mp);
  if (sp) mp[2]++;
}
long long solve1() {
  vector<pair<long long, long long> > v;
  vector<long long> T;
  v.clear();
  T.clear();
  for (map<long long, long long>::iterator it = n.begin(); it != n.end();
       it++) {
    if ((it->second) > (s[it->first])) {
      v.push_back(make_pair(it->first, s[it->first]));
      long long SZ = (v).size() - 1;
      T.push_back(tavan(v[SZ].first, v[SZ].second + 1));
    }
  }
  long long ans = 0;
  for (long long i = 0; i < (1 << (v).size()); i++) {
    long long zarb = 1, alamat = 1;
    for (long long j = 0; j < (v).size(); j++) {
      if ((i >> j) % 2) {
        alamat *= -1;
        zarb *= T[j];
      }
    }
    ans += alamat * (M / zarb);
  }
  return ans;
}
long long solve2() {
  vector<long long> v;
  v.clear();
  v.push_back(1);
  for (map<long long, long long>::iterator it = s.begin(); it != s.end();
       it++) {
    long long SZ = (v).size(), p = it->first, t = it->second;
    for (long long i = 0; i < SZ; i++) {
      long long pro = 1;
      for (long long j = 0; j < t; j++) {
        pro *= p;
        v.push_back(v[i] * pro);
      }
    }
  }
  long long ans = 0;
  for (long long i = 0; i < (v).size(); i++) {
    if (v[i] <= N) ans++;
  }
  return ans;
}
int main() {
  for (long long i = 2; i < maxn; i++) {
    if (par[i] == 0) {
      for (long long j = i * i; j < maxn; j += i) {
        par[j] = i;
      }
    }
  }
  long long q;
  cin >> q;
  for (long long i = 0; i < q; i++) {
    sp = 0;
    Get(n, N);
    sp = 0;
    Get(m, M);
    sp = 1;
    Get(s, second);
    cout << solve1() + solve2() << endl;
  }
}

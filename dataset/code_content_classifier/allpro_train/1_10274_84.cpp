#include <bits/stdc++.h>
using namespace std;
int T, n;
bool flag[1000010];
vector<int> fac[1000010];
void init() {
  for (int i = 2; i <= 1000000; i++) {
    if (!flag[i]) {
      fac[i].push_back(i);
      for (int j = i * 2; j <= 1000000; j += i)
        flag[j] = 1, fac[j].push_back(i);
    }
  }
}
long long N, M, S;
vector<int> facN, cntN, cntS;
vector<long long> prod;
int cnt = 0;
void getdivisor(int pos, long long vl) {
  if (vl > N) return;
  if (pos == facN.size()) {
    cnt++;
    return;
  }
  for (int i = 0; i <= cntS[pos]; i++) {
    getdivisor(pos + 1, vl);
    if (i != cntS[pos]) vl *= facN[pos];
  }
}
void solve() {
  int n1, n2, n3, m1, m2, m3, s1, s2, s3;
  scanf("%d%d%d%d%d%d%d%d%d", &n1, &n2, &n3, &m1, &m2, &m3, &s1, &s2, &s3);
  N = (long long)n1 * n2 * n3;
  M = (long long)m1 * m2 * m3;
  S = (long long)s1 * s2 * s3;
  facN = fac[n1];
  cntN.clear();
  cntS.clear();
  prod.clear();
  facN.insert(facN.end(), fac[n2].begin(), fac[n2].end());
  facN.insert(facN.end(), fac[n3].begin(), fac[n3].end());
  sort(facN.begin(), facN.end());
  facN.erase(unique(facN.begin(), facN.end()), facN.end());
  long long tmp = N;
  for (auto &x : facN) {
    int cnt = 0;
    while (tmp % x == 0) tmp /= x, cnt++;
    cntN.push_back(cnt);
  }
  tmp = 2 * S;
  for (auto &x : facN) {
    int cnt = 0;
    long long tv = x;
    while (tmp % x == 0) tmp /= x, cnt++, tv *= x;
    cntS.push_back(cnt);
    prod.push_back(tv);
  }
  long long ans = 0;
  vector<int> pos;
  for (int i = 0; i < facN.size(); i++)
    if (cntN[i] > cntS[i]) pos.push_back(i);
  for (int i = 0; i < (1 << (pos.size())); i++) {
    long long vl = 1;
    for (int j = 0; j < pos.size(); j++)
      if ((i >> j) & 1) vl *= prod[pos[j]];
    if (__builtin_parity(i))
      ans -= (M / vl);
    else
      ans += (M / vl);
  }
  facN = fac[s1];
  cntS.clear();
  facN.insert(facN.end(), fac[s2].begin(), fac[s2].end());
  facN.insert(facN.end(), fac[s3].begin(), fac[s3].end());
  facN.push_back(2);
  sort(facN.begin(), facN.end());
  facN.erase(unique(facN.begin(), facN.end()), facN.end());
  tmp = 2 * S;
  for (auto &x : facN) {
    int cnt = 0;
    while (tmp % x == 0) tmp /= x, cnt++;
    cntS.push_back(cnt);
  }
  cnt = 0;
  getdivisor(0, 1);
  printf("%lld\n", ans + cnt);
}
int main() {
  init();
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
inline void R(int &xx) {
  xx = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9')
    xx = xx + xx + (xx << 3) + ch - 48, ch = getchar();
}
inline void R(long long &xx) {
  xx = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9')
    xx = xx + xx + (xx << 3) + ch - 48, ch = getchar();
}
int n, prime[100011], tot;
bool f[100011], u[100011];
vector<pair<int, int> > ans;
vector<int> tmp;
inline void init() {
  for (int i = 2; i <= n; i++) {
    if (!f[i]) prime[++tot] = i;
    for (int j = 1; j <= tot && i * prime[j] < 100011; j++) {
      f[i * prime[j]] = 1;
      if (!(i % prime[j])) break;
    }
  }
}
int main() {
  R(n);
  init();
  for (int i = tot; i >= 1; i--) {
    int pr = prime[i];
    tmp.clear();
    for (int j = pr; j <= n; j += pr)
      if (!u[j]) tmp.push_back(j);
    if (tmp.size() & 1) swap(tmp[1], tmp[tmp.size() - 1]);
    for (int t = 0; t < ((int)tmp.size() - 1); t += 2) {
      ans.push_back(make_pair(tmp[t], tmp[t + 1]));
      u[tmp[t]] = u[tmp[t + 1]] = 1;
    }
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++)
    printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}

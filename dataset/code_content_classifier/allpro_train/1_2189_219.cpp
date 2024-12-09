#include <bits/stdc++.h>
using namespace std;
int _n, n, ql, qq[30], sum[30];
long long _a, _b, _c, _min, _max, tmp;
void Dfs(int u, int deta) {
  if (u > ql) {
    _n = n / deta;
    _a = deta + 1;
    _b = 3;
    _c = _n + 2;
    tmp = _a * _b * _c;
    if (tmp > _max) _max = tmp;
    for (int i = int(sqrt(_n + 1)); i; --i)
      if ((_n % i) == 0) {
        _b = i + 2;
        _c = (_n / i) + 2;
        break;
      }
    tmp = _a * _b * _c;
    if (tmp < _min) _min = tmp;
    return;
  }
  Dfs(u + 1, deta);
  for (int i = 1; i <= sum[u]; ++i) {
    deta *= qq[u];
    Dfs(u + 1, deta);
  }
}
int main() {
  scanf("%d", &n);
  int _m = int(sqrt(n + 1)), m = n;
  ql = 0;
  for (int i = 2; i <= _m; ++i) {
    if (m % i) continue;
    ++ql;
    qq[ql] = i;
    sum[ql] = 1;
    m /= i;
    for (; (m % i) == 0; m /= i) ++sum[ql];
  }
  if (m > 1) {
    ++ql;
    qq[ql] = m;
    sum[ql] = 1;
  }
  _max = -1;
  _min = 1000000000;
  _min *= 10000000;
  Dfs(1, 1);
  cout << (_min - n) << " " << (_max - n) << endl;
  return 0;
}

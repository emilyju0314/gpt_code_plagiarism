#include <bits/stdc++.h>
using namespace std;
long long best[55], sum[55], first[55], last[55];
int a[5005], n, in[250005], m;
long long me[250005][2];
bool seen[250005][2];
long long f(int p, int past) {
  if (p == m) return 0;
  long long& ret = me[p][past];
  if (seen[p][past]) return ret;
  seen[p][past] = 1;
  ret = 0;
  if (!past) {
    ret = best[in[p]];
    ret = max(ret, last[in[p]] + f(p + 1, 1));
    if (p + 1 != m) ret = max(ret, f(p + 1, 0));
  } else {
    ret = first[in[p]];
    ret = max(ret, sum[in[p]] + f(p + 1, 1));
  }
  return ret;
}
int main() {
  int len;
  scanf("%d %d", &n, &m);
  for (int i = 0, _e(n); i < _e; i++) {
    scanf("%d", &len);
    for (int j = 0, _e(len); j < _e; j++) scanf("%d", &a[j]);
    for (int j = 0, _e(len); j < _e; j++) sum[i] += a[j];
    long long cur = 0;
    for (int j = 0, _e(len); j < _e; j++) {
      cur += a[j];
      if (!j)
        first[i] = cur;
      else
        first[i] = max(first[i], cur);
    }
    cur = 0;
    best[i] = -1 << 30;
    for (int j = 0, _e(len); j < _e; j++)
      if (a[j] > best[i]) best[i] = a[j];
    for (int j = 0, _e(len); j < _e; j++) {
      if (cur + a[j] < 0)
        cur = 0;
      else {
        cur += a[j];
        if (cur > best[i]) best[i] = cur;
      }
    }
    cur = 0;
    for (int j(len - 1), _e(0); j >= _e; j--) {
      cur += a[j];
      if (j == len - 1)
        last[i] = cur;
      else
        last[i] = max(last[i], cur);
    }
  }
  for (int i = 0, _e(m); i < _e; i++) scanf("%d", &in[i]);
  for (int i = 0, _e(m); i < _e; i++) in[i]--;
  cout << f(0, 0) << endl;
  return 0;
}

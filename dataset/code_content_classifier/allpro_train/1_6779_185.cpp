#include <bits/stdc++.h>
using namespace std;
int n, u, r;
vector<long long> a, b, k, p;
long long answer = -((long long)(1e18));
void recur(vector<long long> ta, int dpth, bool op) {
  if (dpth == u) {
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      ans += ((long long)ta[i] * k[i]);
    }
    answer = max(ans, answer);
    return;
  }
  if ((u - dpth) % 2 == 0) {
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      ans += ((long long)ta[i] * k[i]);
    }
    answer = max(ans, answer);
  }
  if (op) {
    vector<long long> tmp2(n);
    for (int i = 0; i < n; i++) {
      tmp2[i] = ta[p[i]] + r;
    }
    recur(tmp2, dpth + 1, true);
    recur(tmp2, dpth + 1, false);
    return;
  }
  for (int i = 0; i < n; i++) {
    ta[i] ^= b[i];
  }
  recur(ta, dpth + 1, !op);
}
int main() {
  cin >> n >> u >> r;
  a.assign(n, 0);
  b.assign(n, 0);
  k.assign(n, 0);
  p.assign(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> k[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
  }
  recur(a, 0, false);
  recur(a, 0, true);
  cout << answer << endl;
}

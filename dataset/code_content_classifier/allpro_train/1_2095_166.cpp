#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 40404;
ll v1[N], v2[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  int d = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (a == 0) {
      ++v1[d];
      d = 0;
    } else
      ++d;
  }
  ++v1[d];
  d = 0;
  for (int i = 0; i < m; ++i) {
    int a;
    cin >> a;
    if (a == 0) {
      ++v2[d];
      d = 0;
    } else
      ++d;
  }
  ++v2[d];
  int amt = 0;
  for (int i = n; i > 0; --i) {
    amt += v1[i];
    v1[i] = amt + v1[i + 1];
  }
  amt = 0;
  for (int i = m; i > 0; --i) {
    amt += v2[i];
    v2[i] = amt + v2[i + 1];
  }
  ll r = 0;
  for (int i = 1; i < N; ++i) {
    if (k % i == 0 && k / i < N) r += v1[i] * v2[k / i];
  }
  cout << r << '\n';
}

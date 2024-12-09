#include <bits/stdc++.h>
#pragma GCC optimize "-O3"
#pragma GCC optimize("Ofast")
using namespace std;
inline int bin() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  return x;
}
const int M = 29;
pair<int, int> a[1000004], b[1000004];
pair<int, int> v0[1000004], v1[1000004];
pair<int, int> v[1000004];
int c[39], ans, n, d[39];
inline void work(int x, int y, int &k, int &K) {
  int l = -1, r = -1;
  for (int o = n - 1; o >= 0; o--) {
    while (l + 1 < n && b[l + 1].first + b[o].first < x) l++;
    while (r + 1 < n && b[r + 1].first + b[o].first <= y) r++;
    if (o > l && o <= r) K++;
    if (l <= r) k += (r - l);
  }
}
int main() {
  for (int i = 1; i <= M; i++) {
    c[i] = (1 << (i + 1)) - 1;
    d[i] = (1 << (i));
  }
  n = bin();
  for (int i = 0; i < n; i++) {
    a[i].first = bin();
    a[i].second = i;
  }
  for (int i = 1; i <= M; i++) {
    if (i == 1) {
      for (int j = 0; j < n; j++) {
        b[j].first = c[i] & a[j].first;
        b[j].second = a[j].second;
      }
      sort(b, b + n);
    } else {
      for (int j = 0; j < n; j++) {
        b[j].first = b[j].first & c[i];
      }
      int V1 = 0, V0 = 0;
      for (int j = 0; j < n; j++) {
        if (d[i] & b[j].first) {
          v1[V1] = b[j];
          V1++;
        } else {
          v0[V0] = b[j];
          V0++;
        }
      }
      for (int j = 0; j < V0; j++) {
        v[j] = v0[j];
      }
      for (int j = 0; j < V1; j++) {
        v[j + V0] = v1[j];
      }
      for (int j = 0; j < n; j++) {
        b[j] = v[j];
      }
    }
    int b1 = (1 << (i));
    int b2 = ((1 << (i + 1)) - 1);
    int B1 = b1 + (1 << (i + 1));
    int B2 = ((1 << (i + 2)) - 2);
    int k = 0, K = 0;
    work(b1, b2, k, K);
    work(B1, B2, k, K);
    k -= K;
    k /= 2;
    if (k & 1) {
      ans |= (1 << (i));
    }
    for (int j = 0; j < n; j++) {
      b[j].first = a[b[j].second].first;
    }
  }
  int k = 0;
  for (int i = 0; i < n; i++) {
    if (a[i].first & 1) k++;
  }
  if ((k * (n - k)) & 1) {
    ans++;
  }
  cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;
int diag(vector<int> &a, vector<pair<int, int> > &s) {
  int r = 0;
  for (int i = 30; i >= 0; --i) {
    for (int j = r; j < a.size(); ++j)
      if (a[j] & (1 << i)) {
        if (j != r) {
          s.push_back({j, r});
          s.push_back({r, j});
          s.push_back({j, r});
          swap(a[j], a[r]);
        }
        for (int k = 0; k < a.size(); ++k)
          if (k != r && (a[k] & (1 << i))) {
            s.push_back({k, r});
            a[k] ^= a[r];
          }
        ++r;
        break;
      }
  }
  return r;
}
int n;
vector<int> a, b;
vector<pair<int, int> > sa, sb, s;
int main() {
  scanf("%d", &n);
  a.resize(n);
  b.resize(n);
  for (auto &v : a) scanf("%d", &v);
  for (auto &v : b) scanf("%d", &v);
  int ra = diag(a, sa);
  int rb = diag(b, sb);
  for (int i = 0; i < ra; ++i) {
    int msb = 1;
    while (msb * 2 <= a[i]) msb *= 2;
    for (int j = 0; j < ra; ++j)
      if (j != i && (b[j] & msb)) {
        s.push_back({j, i});
        a[j] ^= a[i];
      }
    if (!(b[i] & msb)) {
      s.push_back({i, i});
      a[i] ^= a[i];
    }
  }
  for (int i = 0; i < n; ++i)
    if (a[i] != b[i]) {
      puts("-1");
      return 0;
    }
  printf("%d\n", s.size() + sa.size() + sb.size());
  reverse(sb.begin(), sb.end());
  for (auto v : sa) printf("%d %d\n", v.first + 1, v.second + 1);
  for (auto v : s) printf("%d %d\n", v.first + 1, v.second + 1);
  for (auto v : sb) printf("%d %d\n", v.first + 1, v.second + 1);
  return 0;
}

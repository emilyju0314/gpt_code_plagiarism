#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmin(T &x, T y) {
  return x > y ? x = y, 1 : 0;
}
template <typename T>
inline bool chkmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
inline void read(int &x) {
  char ch = getchar();
  int f = 1;
  x = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  x *= f;
}
int n, k, ss[200050], d[200050];
vector<pair<int, int> > ans;
int main() {
  read(n), read(k);
  for (register int i = 2; i <= k + 1; ++i)
    ans.push_back(make_pair(1, i)), ss[i] = i, d[i] = 1;
  int pwp = 0;
  for (register int i = k + 2; i <= n; ++i) {
    int cur = pwp + 2;
    ans.push_back(make_pair(ss[cur], i)), ss[cur] = i, d[cur]++;
    pwp = (pwp + 1) % k;
  }
  int max[2] = {0, 0};
  for (register int i = 2; i <= k + 1; ++i)
    if (d[i] > max[0])
      swap(max[0], max[1]), max[0] = d[i];
    else if (d[i] > max[1])
      max[1] = d[i];
  cout << max[0] + max[1] << endl;
  for (auto v : ans) cout << v.first << ' ' << v.second << endl;
  return 0;
}

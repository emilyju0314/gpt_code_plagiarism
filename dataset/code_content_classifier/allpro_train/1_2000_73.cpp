#include <bits/stdc++.h>
using namespace std;
unsigned long long min(unsigned long long x, unsigned long long y) {
  if (x < y) return x;
  return y;
}
unsigned long long max(unsigned long long x, unsigned long long y) {
  if (x < y) return y;
  return x;
}
long long min(long long x, long long y) {
  if (x < y) return x;
  return y;
}
long long max(long long x, long long y) {
  if (x < y) return y;
  return x;
}
int main() {
  int n;
  cin >> n;
  vector<int> g[100001];
  vector<int> c(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    int pi, ci;
    cin >> pi >> ci;
    if (pi != -1) g[pi].push_back(i);
    c[i] = ci;
  }
  int f = 0;
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 0; j < g[i].size(); j++) {
      cnt += c[g[i][j]];
    }
    if (c[i] && (cnt == g[i].size())) {
      cout << i << " ";
      f++;
    }
  }
  if (!f) cout << "-1";
  cout << "\n";
  return 0;
}

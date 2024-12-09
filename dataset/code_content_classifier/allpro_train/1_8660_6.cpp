#include <bits/stdc++.h>
using namespace std;
int v[100010], n, x;
int b[100010];
set<int> s;
int main() {
  cin >> n >> x;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    v[a]++;
    s.insert(a);
  }
  int cur = v[x];
  for (int i = 1; i < 100010; ++i)
    if (v[i] >= 2) return cout << "0\n", 0;
  for (int i = 1; i < 100010; ++i) {
    if (v[i] == 0) continue;
    int dx = i & x;
    if (dx != i) {
      b[dx]++;
      if (s.count(dx)) return cout << "1\n", 0;
    }
  }
  for (int i = 0; i < 100010; ++i) {
    if (b[i] >= 2) return cout << "2\n", 0;
  }
  cout << "-1\n";
  return 0;
}

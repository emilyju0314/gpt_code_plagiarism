#include <bits/stdc++.h>
using namespace std;
unordered_map<long long, long long> f;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    long long t, v, u;
    cin >> t >> v >> u;
    if (t == 1) {
      long long w;
      cin >> w;
      while (u != v)
        if (u > v)
          f[u] += w, u /= 2;
        else
          f[v] += w, v /= 2;
    } else {
      long long w = 0;
      while (u != v)
        if (u > v)
          w += f[u], u /= 2;
        else
          w += f[v], v /= 2;
      cout << w << '\n';
    }
  }
}

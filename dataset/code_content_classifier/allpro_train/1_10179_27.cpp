#include <bits/stdc++.h>
using namespace std;
long long int mcd(long long int a, long long int b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return mcd(a % b, b);
}
int main() {
  vector<int> marca(10000001, 1);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int u;
    cin >> u;
    marca[u] = 0;
  }
  vector<vector<int> > g(10000001);
  for (int u = 1; u < 10000; u++) {
    for (int v = 1; v < u; v++) {
      if (u * u - v * v <= 10000000 and 2 * u * v <= 10000000) {
        int val1 = u * u - v * v;
        int val2 = 2 * u * v;
        int val3 = u * u + v * v;
        int marcaval3 = 1;
        if (val3 <= 10000000) marcaval3 = marca[val3];
        if (marca[val1] + marca[val2] + marcaval3 <= 1 and
            mcd(val1, val2) == 1 and mcd(val1, val3) == 1 and
            mcd(val2, val3) == 1) {
          if (val3 <= 10000000) {
            if (marca[val1] + marca[val3] == 0) {
              g[val1].push_back(val3);
              g[val3].push_back(val1);
            }
            if (marca[val2] + marca[val3] == 0) {
              g[val2].push_back(val3);
              g[val3].push_back(val2);
            }
          }
          if (marca[val1] + marca[val2] == 0) {
            g[val1].push_back(val2);
            g[val2].push_back(val1);
          }
        }
      }
    }
  }
  int compo = 0;
  for (int i = 0; i < 10000001; i++) {
    if (marca[i] == 0) {
      compo++;
      stack<int> s;
      marca[i] = 1;
      s.push(i);
      while (not s.empty()) {
        int u = s.top();
        s.pop();
        vector<int> &ad = g[u];
        for (int j = 0; j < int(ad.size()); j++) {
          int v = ad[j];
          if (marca[v] == 0) {
            marca[v] = 1;
            s.push(v);
          }
        }
      }
    }
  }
  cout << compo << endl;
}

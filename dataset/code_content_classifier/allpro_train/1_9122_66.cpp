#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const int max_v = 222;
const int max_e = max_v * max_v;
int V, E, ret = oo, a[max_e], b[max_e], c[max_e], d[max_v][max_v];
int main() {
  cin >> V >> E;
  for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++) d[i][j] = i == j ? 0 : oo;
  for (int i = 0; i < E; i++) {
    cin >> a[i] >> b[i] >> c[i];
    d[--a[i]][--b[i]] = d[b[i]][a[i]] = c[i];
  }
  for (int k = 0; k < V; k++)
    for (int i = 0; i < V; i++)
      for (int j = 0; j < V; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  for (int i = 0; i < E; i++) {
    int temp, maxB = 0;
    vector<pair<int, int> > niz;
    for (int j = 0; j < V; j++)
      niz.push_back(make_pair(d[a[i]][j], d[b[i]][j]));
    sort(niz.begin(), niz.end(), greater<pair<int, int> >());
    for (int j = 0; j < V; j++) {
      if (abs(niz[j].first - maxB) < c[i])
        temp = niz[j].first + maxB + c[i];
      else
        temp = max(maxB, niz[j].first) * 2;
      ret = min(ret, temp);
      maxB = max(maxB, niz[j].second);
    }
  }
  cout << ret / 2;
  if (ret & 1) cout << ".5";
  return 0;
}

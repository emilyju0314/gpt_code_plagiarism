#include <bits/stdc++.h>
using namespace std;
const int DIM = 100005;
vector<int> edg[DIM];
int val[DIM];
int main(void) {
  int n, m, h, t;
  cin >> n >> m >> h >> t;
  for (int i = 1; i <= m; ++i) {
    int x, y;
    cin >> x >> y;
    edg[x].push_back(y);
    edg[y].push_back(x);
  }
  for (int x = 1; x <= n; ++x) {
    for (int y : edg[x]) {
      for (int i = 0; i < min((int)edg[x].size(), h + t + 1); ++i) {
        int z = edg[x][i];
        if (z == x or z == y) continue;
        val[z] ^= 1;
      }
      for (int i = 0; i < min((int)edg[y].size(), h + t + 1); ++i) {
        int z = edg[y][i];
        if (z == x or z == y) continue;
        val[z] ^= 2;
      }
      vector<int> heads, tails, mix;
      for (int i = 0; i < min((int)edg[x].size(), h + t + 1); ++i) {
        int z = edg[x][i];
        if (z == x or z == y) continue;
        if (val[z] == 1) heads.push_back(z);
      }
      for (int i = 0; i < min((int)edg[y].size(), h + t + 1); ++i) {
        int z = edg[y][i];
        if (z == x or z == y) continue;
        if (val[z] == 2)
          tails.push_back(z);
        else
          mix.push_back(z);
      }
      while (heads.size() < h and mix.size()) {
        heads.push_back(mix.back());
        mix.pop_back();
      }
      while (tails.size() < t and mix.size()) {
        tails.push_back(mix.back());
        mix.pop_back();
      }
      if (heads.size() >= h and tails.size() >= t) {
        cout << "YES\n";
        cout << x << " " << y << "\n";
        for (int i = 0; i < h; ++i) cout << heads[i] << " ";
        cout << "\n";
        for (int i = 0; i < t; ++i) cout << tails[i] << " ";
        cout << "\n";
        return 0;
      }
      for (int i = 0; i < min((int)edg[x].size(), h + t + 1); ++i) {
        int z = edg[x][i];
        if (z == x or z == y) continue;
        val[z] = 0;
      }
      for (int i = 0; i < min((int)edg[y].size(), h + t + 1); ++i) {
        int z = edg[y][i];
        if (z == x or z == y) continue;
        val[z] = 0;
      }
    }
  }
  cout << "NO\n";
  return 0;
}

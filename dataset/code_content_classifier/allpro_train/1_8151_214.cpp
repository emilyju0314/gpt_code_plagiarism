#include <bits/stdc++.h>
using namespace std;
const int MXN = 8;
vector<pair<int, int>> g;
int nums[MXN];
int dom[MXN][MXN];
void mfill(int i, int j, int r) {
  int z = 1;
  for (int k = 1; k <= 7; k++) {
    if (z == r) z++;
    if (k == i || k == j) continue;
    nums[k] = z++;
  }
}
void mclean() {
  for (int i = 0; i < MXN; i++) {
    for (int j = 0; j < MXN; j++) {
      dom[i][j] = 0;
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    g.push_back({b, a});
  }
  if (n <= 6) {
    cout << m << endl;
  } else {
    int maxc = 0;
    for (int r = 1; r <= n; r++) {
      for (int i = 1; i <= n; i++) {
        nums[i] = r;
        for (int j = i + 1; j <= n; j++) {
          if (i == j) continue;
          nums[j] = r;
          mfill(i, j, r);
          mclean();
          int c = 0;
          for (int k = 0; k < (int)g.size(); k++) {
            int f = nums[g[k].first];
            int s = nums[g[k].second];
            if (dom[f][s] == 0) {
              c++;
            }
            dom[f][s] = 1;
            dom[s][f] = 1;
          }
          maxc = max(maxc, c);
        }
      }
    }
    cout << maxc << endl;
  }
}

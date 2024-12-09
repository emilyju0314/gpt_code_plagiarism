#include <bits/stdc++.h>
using namespace std;
void Emsawy() {}
const double PI = acos(-1.0);
const double eps = 1e-10;
const long long mod = 1e9 + 7, oo = 1e9;
int dx[]{1, -1, 0, 0, 1, -1, 1, -1};
int dy[]{0, 0, 1, -1, 1, -1, -1, 1};
vector<vector<pair<int, int> > > adj;
int n, m, k, t, c;
int s1[100001], s2[100001];
int main() {
  Emsawy();
  while (cin >> n >> k >> m) {
    vector<char> v(n + 1);
    for (int i = 1; i <= n; i++) scanf("\n%c", &v[i]);
    for (int i = 1; i <= n; i++) {
      s1[i] = s2[i] = v[i] - '0';
      s1[i] += s1[i - 1];
      if (i > k) s2[i] += s2[i - k];
    }
    int l, r;
    while (m--) {
      scanf("%d%d", &l, &r);
      int rng = s2[r] - s2[l - 1];
      int ans = s1[r] - s1[l - 1];
      ans -= rng;
      ans += ((r - l + 1) / k - rng);
      printf("%d\n", ans);
    }
  }
  return 0;
}

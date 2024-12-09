#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5;
const int inf = 1e9;
vector<pair<int, int> > basket[maxn];
int tmp[maxn];
int main() {
  int n, cur, mxCur = 0, x, y, m, k, sumK = 0;
  scanf("%d", &n);
  for (int j = 0; j < n; j++) {
    scanf("%d%d%d%d%d", &k, &tmp[0], &x, &y, &m);
    sumK += k;
    for (int i = 1; i < k; i++) {
      tmp[i] = (tmp[i - 1] * 1ll * x + y) % m;
    }
    cur = 0;
    for (int i = 0; i < k; i++) {
      if (i > 0 && tmp[i - 1] > tmp[i]) cur++;
      if (sumK <= 200000) basket[cur].push_back(make_pair(tmp[i], j));
    }
    mxCur = max(mxCur, cur);
  }
  printf("%d\n", mxCur);
  for (int i = 0; i <= mxCur; i++) {
    sort(basket[i].begin(), basket[i].end());
    for (int j = 0; j < (int)basket[i].size(); j++)
      if (sumK <= 200000)
        printf("%d %d\n", basket[i][j].first, basket[i][j].second + 1);
  }
  return 0;
}

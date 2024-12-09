#include <bits/stdc++.h>
using namespace std;
int x[1005], y[1005], r[1005], level[1005];
long long sum[1005];
vector<pair<int, int> > X[1005];
void dfs(int node, int l) {
  level[node] = l;
  int i;
  for (i = 0; i < X[node].size(); i++) {
    if (level[X[node][i].second] <= level[node]) dfs(X[node][i].second, l + 1);
  }
}
bool check(int ind1, int ind2) {
  if (r[ind1] < r[ind2]) return false;
  long double dist = (long long)(x[ind1] - x[ind2]) * (x[ind1] - x[ind2]) +
                     (long long)(y[ind1] - y[ind2]) * (y[ind1] - y[ind2]);
  dist = sqrtl(dist);
  if (dist + r[ind2] > (long double)r[ind1]) return false;
  return true;
}
int main() {
  int n;
  scanf("%d", &n);
  int i;
  for (i = 1; i <= n; i++) {
    scanf("%d%d%d", x + i, y + i, r + i);
  }
  for (i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (check(i, j)) X[i].push_back(make_pair(r[j], j));
      if (check(j, i)) X[j].push_back(make_pair(r[i], i));
    }
  }
  for (i = 1; i <= n; i++) {
    sort(X[i].begin(), X[i].end());
    reverse(X[i].begin(), X[i].end());
  }
  for (i = 1; i <= n; i++) {
    if (!level[i]) dfs(i, 1);
  }
  for (i = 1; i <= n; i++) {
    sum[level[i]] += (long long)r[i] * r[i];
  }
  int cnt = 0;
  long long ans = 0;
  for (i = 1; i <= 1000; i++) {
    if (i <= 2) {
      ans += sum[i];
      continue;
    }
    if (i % 2)
      ans -= sum[i];
    else
      ans += sum[i];
  }
  long double p = (long double)(3.14159265359) * ans;
  cout.precision(9);
  cout << fixed << p;
}

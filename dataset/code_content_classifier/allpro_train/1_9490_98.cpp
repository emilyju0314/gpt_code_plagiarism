#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)100;
long long n, t;
int ans;
long long all = 0;
long long V[20][20], v[20][20];
void dfs(int lvl) {
  if (lvl > n) return;
  for (int i = 1; i <= lvl; i++) {
    long long add = min(v[lvl][i], all - V[lvl][i]);
    v[lvl][i] -= add, V[lvl][i] += add;
    v[lvl + 1][i] += v[lvl][i] / 2, v[lvl + 1][i + 1] += v[lvl][i] / 2;
    v[lvl][i] = 0;
  }
  dfs(lvl + 1);
}
void FindAns(int lvl) {
  if (lvl > n) return;
  for (int i = 1; i <= lvl; i++)
    if (V[lvl][i] == all) ans++;
  FindAns(lvl + 1);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> t;
  all = (long long)n * (n + 1) * (1 << (n + 1));
  for (int i = 1; i <= t; i++) {
    v[1][1] = all;
    dfs(1);
  }
  FindAns(1);
  cout << ans;
}

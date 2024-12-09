#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100100;
int n;
long long s[MAXN];
vector<pair<long long, int> > v[MAXN];
long long p[MAXN];
vector<long long> tmp;
void dfs(int cvor, int d) {
  tmp.push_back(s[cvor]);
  sort((v[cvor]).begin(), (v[cvor]).end());
  if (d % 2 == 1 && d != 1) {
    int sz = (int)tmp.size();
    if (tmp[sz - 2] == -1) {
      if (tmp.back() - tmp[sz - 3] < 0) {
        puts("-1");
        exit(0);
      }
      tmp[sz - 2] = tmp.back();
    }
  }
  for (auto ncvor : v[cvor]) {
    dfs(ncvor.second, d + 1);
  }
  if (d % 2 == 0) s[cvor] = tmp.back();
  tmp.pop_back();
}
long long ans[MAXN];
void rek(int cvor) {
  tmp.push_back(s[cvor]);
  if (tmp.back() == -1)
    ans[cvor] = 0;
  else {
    if (cvor == 1)
      ans[cvor] = s[cvor];
    else
      ans[cvor] = tmp.back() - tmp[(int)tmp.size() - 2];
  }
  for (auto ncvor : v[cvor]) {
    rek(ncvor.second);
  }
  tmp.pop_back();
}
void solve() {
  rek(1);
  long long sum = 0;
  for (int i = (1); i < int(n + 1); i++) sum += ans[i];
  printf("%lld\n", sum);
}
int main() {
  scanf("%d", &n);
  for (int i = (2); i < int(n + 1); i++) {
    scanf("%lld", &p[i]);
  }
  for (int i = (1); i < int(n + 1); i++) scanf("%lld", &s[i]);
  for (int i = (2); i < int(n + 1); i++) v[p[i]].push_back({s[i], i});
  dfs(1, 1);
  solve();
  return 0;
}

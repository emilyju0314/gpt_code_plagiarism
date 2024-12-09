#include <bits/stdc++.h>
using namespace std;
bool debug = 1;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
long long ln, lk, lm;
int a[100005], b[100005], c[100005], ans;
map<int, int> mpb, mpc, mpa, inv;
set<int> sbc;
set<pair<int, int>> ss;
multiset<int> as;
void add(int pb, int pc) {
  auto it = ss.lower_bound({pb, -(1e8)});
  if ((*it).second >= pc) return;
  auto pre = it;
  pre--;
  as.erase(as.find((*pre).first + (*it).second));
  while ((*pre).second <= pc) {
    auto data = *pre;
    int y = data.second;
    pre--;
    as.erase(as.find(y + (*pre).first));
    ss.erase(data);
  }
  as.insert((*pre).first + pc);
  if ((*it).first == pb) {
    ss.erase(it);
  } else {
    as.insert(pb + (*it).second);
  }
  ss.insert({pb, pc});
}
int main() {
  scanf("%d", &n);
  for (int(i) = 1; (i) <= (int)(n); (i)++) scanf("%d", a + i);
  for (int(i) = 1; (i) <= (int)(n); (i)++) scanf("%d", b + i);
  for (int(i) = 1; (i) <= (int)(n); (i)++) scanf("%d", c + i);
  for (int i = n; i; i--) {
    mpb[b[i]] = i;
    mpc[c[i]] = i;
    mpa[a[i]] = i;
    sbc.insert(b[i]);
    sbc.insert(c[i]);
  }
  for (int(i) = 1; (i) <= (int)(n); (i)++) sbc.erase(a[i]);
  ss.insert({0, (1e8) * 10});
  ss.insert({(1e8) * 10, 0});
  as.insert(0);
  for (int x : sbc) {
    int pb = mpb.find(x) == mpb.end() ? (1e8) : mpb[x];
    int pc = mpc.find(x) == mpc.end() ? (1e8) : mpc[x];
    add(pb, pc);
  }
  ans = (1e8);
  for (int i = n; i >= 0; i--) {
    while (i && mpa[a[i]] != i) i--;
    int tmp = i + *as.begin();
    ans = min(ans, tmp);
    if (i) {
      int x = a[i];
      int pb = mpb.find(x) == mpb.end() ? (1e8) : mpb[x];
      int pc = mpc.find(x) == mpc.end() ? (1e8) : mpc[x];
      if (pb == (1e8) && pc == (1e8)) break;
      add(pb, pc);
    }
  }
  printf("%d\n", ans);
  return 0;
}

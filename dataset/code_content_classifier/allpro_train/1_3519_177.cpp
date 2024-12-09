#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:65777216")
using namespace std;
int n, k;
pair<int, int> a[111111];
int root;
int par[111111];
int val[111111];
vector<int> v[111111];
int m[111111];
int M[111111];
const int st = 1 << 18;
long long s1[2 * st];
long long s2[2 * st];
void add(long long *s, int beg, int end, int val) {
  beg += st;
  end += st;
  while (beg <= end) {
    if (beg & 1) s[beg] += val;
    if (!(end & 1)) s[end] += val;
    beg = (beg + 1) >> 1;
    end = (end - 1) >> 1;
  }
}
long long getSum(long long *s, int pos) {
  long long res = 0;
  pos += st;
  while (pos) {
    res += s[pos];
    pos >>= 1;
  }
  return res;
}
void dfs(int ver) {
  if (v[ver].size() == 0) {
    m[ver] = M[ver] = val[ver];
  } else {
    dfs(v[ver][0]);
    dfs(v[ver][1]);
    m[ver] = m[v[ver][0]];
    M[ver] = M[v[ver][1]];
  }
}
void go(int ver, int beg, int end) {
  if (beg > end) return;
  if (v[ver].size() == 0) return;
  int B = beg, E = end;
  int best = end + 1;
  while (B <= E) {
    int s = (B + E) / 2;
    if (a[s].first > val[ver]) {
      best = s;
      E = s - 1;
    } else
      B = s + 1;
  }
  add(s2, beg, end, 1);
  add(s1, beg, best - 1, m[v[ver][1]]);
  add(s1, best, end, M[v[ver][0]]);
  go(v[ver][0], beg, best - 1);
  go(v[ver][1], best, end);
}
double r[111111];
int main() {
  cin >> n;
  for (int i(0); i < (n); i++) {
    scanf("%d %d", par + i, val + i);
    if (par[i] == -1)
      root = i;
    else
      par[i]--;
    if (par[i] != -1) v[par[i]].push_back(i);
  }
  cin >> k;
  for (int i(0); i < (k); i++) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  sort(a, a + k);
  for (int i(0); i < (n); i++)
    if (v[i].size() && val[v[i][0]] > val[i]) swap(v[i][0], v[i][1]);
  dfs(root);
  go(root, 0, k - 1);
  for (int i(0); i < (k); i++) {
    r[a[i].second] = double(getSum(s1, i)) / getSum(s2, i);
  }
  for (int i(0); i < (k); i++) printf("%.10lf\n", r[i]);
  return 0;
}

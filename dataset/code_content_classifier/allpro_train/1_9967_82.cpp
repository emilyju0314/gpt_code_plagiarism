#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, nalive = 0, a[maxn], nextid[maxn], previd[maxn], value_to_id[maxn];
vector<vector<int> > ans;
vector<int> parent(maxn);
int kval;
void remove_id(int id) {
  nextid[previd[id]] = nextid[id];
  previd[nextid[id]] = previd[id];
}
void finish_LIS(int t) {
  nalive = 0;
  vector<int> v;
  vector<int> curr[t];
  int i = nextid[0];
  while (i <= n) {
    if (v.empty() or v.back() < a[i]) {
      curr[(int)v.size()].emplace_back(a[i]);
      v.emplace_back(a[i]);
    } else {
      int index = upper_bound(v.begin(), v.end(), a[i]) - v.begin();
      curr[index].emplace_back(a[i]);
      v[index] = a[i];
    }
    i = nextid[i];
  }
  for (auto it : curr) {
    ans.emplace_back(it);
  }
}
bool find_LIS() {
  parent.assign(n + 2, -1);
  vector<int> v, id;
  int i = nextid[0];
  while (i <= n) {
    if (v.empty() or v.back() < a[i]) {
      if (!v.empty()) parent[i] = id.back();
      v.emplace_back(a[i]);
      id.emplace_back(i);
    } else {
      int index = upper_bound(v.begin(), v.end(), a[i]) - v.begin();
      if (index > 0) parent[i] = id[index - 1];
      v[index] = a[i];
      id[index] = i;
    }
    i = nextid[i];
  }
  if ((int)v.size() + (int)ans.size() <= kval) {
    finish_LIS(v.size());
    return 1;
  }
  vector<int> lis(v.size(), 0);
  nalive -= lis.size();
  int curr = id.back();
  i = id.size() - 1;
  while (curr > -1) {
    lis[i] = a[curr];
    i--;
    curr = parent[curr];
  }
  ans.emplace_back(lis);
  for (auto it : lis) {
    remove_id(value_to_id[it]);
  }
  return 1;
}
int f(int id) { return (id * (id + 1)) / 2; }
void g() {
  kval = sqrt(n);
  while (f(kval + 1) <= n) kval++;
}
void solve() {
  cin >> n;
  nalive = n;
  ans.clear();
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    value_to_id[a[i]] = i;
  }
  g();
  for (int i = 0; i <= n + 5; ++i) {
    previd[i] = i - 1;
    if (i) nextid[i - 1] = i;
  }
  while (nalive) {
    find_LIS();
  }
  cout << ans.size() << endl;
  for (auto i : ans) {
    printf("%d", (int)i.size());
    for (auto j : i) {
      printf(" %d", j);
    }
    printf("\n");
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}

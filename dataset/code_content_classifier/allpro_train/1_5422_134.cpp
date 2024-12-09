#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int a[MAXN];
int n;
vector<int> occ[MAXN];
int firstAfter(int rot, int x) {
  int p = *upper_bound(occ[x].begin(), occ[x].end(), rot);
  return p;
}
int bit[MAXN];
void update(int pos, int val) {
  while (pos <= n) {
    bit[pos] += val;
    pos += pos & -pos;
  }
}
int get(int pos) {
  int ret = 0;
  while (pos) {
    ret += bit[pos];
    pos -= pos & -pos;
  }
  return ret;
}
bool nema(int val, int from) {
  return upper_bound(occ[val].begin(), occ[val].end(), from) == occ[val].end();
}
int dist(int x, int y) {
  int ret = get(y) - get(x);
  if (ret < 0) ret += get(n);
  return ret;
}
int bruteforce() {
  multiset<int> values;
  queue<int> niz;
  for (int i = 1; i <= n; i++) {
    values.insert(a[i]);
    niz.push(a[i]);
  }
  int ans = 0;
  while (!niz.empty()) {
    ++ans;
    int x = niz.front();
    niz.pop();
    if (x == *values.begin()) {
      values.erase(values.find(x));
    } else
      niz.push(x);
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    occ[a[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) update(i, 1);
  long long ans = 0;
  int rot = 0;
  for (int val = 1; val <= 100000; val++) {
    int cnt = occ[val].size();
    while (cnt--) {
      if (nema(val, rot)) {
        ans += get(n) - get(rot);
        rot = 0;
      }
      int fnext = firstAfter(rot, val);
      ans += dist(rot, fnext);
      rot = fnext;
      update(fnext, -1);
    }
  }
  printf("%lld\n", ans);
  return 0;
}

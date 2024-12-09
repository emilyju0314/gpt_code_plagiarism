#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int D[N];
struct T {
  int l, r;
  bool operator<(T b) const { return l < b.l; }
};
set<T> Q;
int s[N], Ord[N];
bool cmp(int a, int b) { return D[a] < D[b]; }
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &D[i]), Ord[i] = i;
  sort(Ord, Ord + n, cmp);
  int cnt = 0;
  int MX = 0, ans, ML = 1;
  for (int i = 0; i < n; i++) {
    int idx = Ord[i];
    auto it2 = Q.lower_bound({idx + 1, 0}), it1 = it2;
    if (it2 != Q.begin())
      it1--;
    else
      it1 = Q.end();
    if (it1 != Q.end() && it2 != Q.end() && it1->r == idx - 1 &&
        it2->l == idx + 1) {
      int u = it2->r - it1->l + 1;
      ML = max(ML, u);
      s[u]++;
      int l = it1->l, r = it2->r;
      Q.erase(it1), Q.erase(it2);
      T g = {l, r};
      Q.insert(g);
    } else if (it1 != Q.end() && it1->r == idx - 1) {
      int u = idx - it1->l + 1;
      ML = max(ML, u);
      int l = it1->l, r = idx;
      s[u]++;
      Q.erase(it1);
      T g = {l, r};
      Q.insert(g);
    } else if (it2 != Q.end() && it2->l == idx + 1) {
      int u = it2->r - idx + 1;
      ML = max(ML, u);
      s[u]++;
      int l = idx, r = it2->r;
      Q.erase(it2);
      T g = {l, r};
      Q.insert(g);
    } else {
      cnt++, s[1]++;
      T g = {idx, idx};
      Q.insert(g);
    }
    if (s[ML] == cnt) {
      if (cnt > MX)
        MX = cnt, ans = D[idx] + 1;
      else if (cnt == MX && D[idx] + 1 < ans)
        ans = D[idx] + 1;
    }
  }
  cout << ans << '\n';
}

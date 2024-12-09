#include <bits/stdc++.h>
using namespace std;
const int maxn = 3000 + 10;
const int INF = 1000000000 + 7;
const int maxp = 1;
const long long inf = 1e18;
const double eps = 1e-8;
vector<vector<int> > op;
int n, k;
char s[maxn];
int _max, _min;
inline void init() {
  int ok = 0;
  for (; !ok;) {
    ok = 1;
    op.push_back(vector<int>());
    vector<int>& oi = op.back();
    for (int i = 1; i <= n; i++) {
      if (s[i] == 'R' && s[i + 1] == 'L') {
        ok = 0;
        swap(s[i + 1], s[i]);
        oi.push_back(i);
        _max++;
        i++;
      }
    }
    if (ok)
      op.pop_back();
    else {
      _min++;
    }
  }
}
inline int solve() {
  if (k < _min || k > _max) return 0;
  int o = _max - k;
  for (auto& ve : op) {
    if (!o) {
      for (auto e : ve) {
        printf("%d %d\n", 1, e);
      }
    } else {
      if (o >= ve.size() - 1) {
        o -= ve.size() - 1;
        printf("%d", ve.size());
        for (auto e : ve) {
          printf(" %d", e);
        }
        puts("");
      } else {
        printf("%d", o + 1);
        for (int i = 0; i <= o; ++i) {
          printf(" %d", ve[i]);
        }
        puts("");
        for (int i = o + 1; i < ve.size(); ++i) {
          printf("%d %d\n", 1, ve[i]);
        }
        o = 0;
      }
    }
  }
  return 1;
}
int main(void) {
  scanf("%d", &(n)), scanf("%d", &(k));
  scanf("%s", s + 1);
  init();
  if (!solve()) puts("-1");
  return 0;
}

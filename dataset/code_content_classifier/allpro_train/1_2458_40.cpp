#include <bits/stdc++.h>
using namespace std;
const int Maxn = 10005;
const int Inf = 1000000000;
int n;
int a[Maxn];
set<pair<int, int> > S;
long long res;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) S.insert(pair<int, int>(i - a[i], i));
  for (int i = 0; i < n; i++) {
    int add = 0, j = 0;
    set<pair<int, int> >::iterator it = S.begin();
    while (j < n - 1) {
      int nxt = j;
      while (it != S.end() && j >= it->first - i) {
        nxt = max(nxt, it->second - i);
        it++;
      }
      j = nxt;
      add++;
    }
    res += add;
    S.erase(pair<int, int>(-a[i] + i, i));
    S.insert(pair<int, int>(n - 1 - a[i] + i + 1, n - 1 + i + 1));
  }
  printf("%I64d\n", res);
  return 0;
}

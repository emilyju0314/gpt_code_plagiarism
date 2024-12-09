#include <bits/stdc++.h>
using namespace std;
const int qq = 3e5 + 10;
vector<int> G[qq];
multiset<int, greater<int> > myset;
int num[qq];
void Del(int x) {
  __typeof(myset.begin()) t;
  t = myset.find(x);
  myset.erase(t);
}
int main() {
  int ans = 2e9 + 10;
  int n;
  scanf("%d", &n);
  int a, b;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", num + i);
    myset.insert(num[i]);
  }
  for (int i = 1; i <= n - 1; ++i) {
    scanf("%d%d", &a, &b);
    G[a].push_back(b), G[b].push_back(a);
  }
  for (int i = 1; i <= n; ++i) {
    Del(num[i]);
    int ma = num[i];
    for (int y : G[i]) {
      Del(num[y]);
      ma = max(ma, num[y] + 1);
    }
    if (!myset.empty()) {
      ma = max(ma, *myset.begin() + 2);
    }
    for (int y : G[i]) {
      myset.insert(num[y]);
    }
    myset.insert(num[i]);
    ans = min(ans, ma);
  }
  printf("%d\n", ans);
}

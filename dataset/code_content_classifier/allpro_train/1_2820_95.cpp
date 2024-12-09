#include <bits/stdc++.h>
using namespace std;
set<int> s[100005];
int cnt[1000005];
int main() {
  int n, A;
  scanf("%d%d", &n, &A);
  for (int i = 1; i <= 1e6; i++) s[0].insert(i);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    cnt[x]++;
    if (x == A) {
      s[cnt[x] - 1].clear();
      s[cnt[x]].insert(x);
    } else if (s[cnt[x] - 1].find(x) != s[cnt[x] - 1].end()) {
      s[cnt[x] - 1].erase(x);
      s[cnt[x]].insert(x);
    }
  }
  s[cnt[A]].erase(A);
  for (int i = 0; i <= 1e5; i++) {
    if (!s[i].empty()) {
      printf("%d", *s[i].begin());
      return 0;
    }
  }
  printf("-1");
  return 0;
}

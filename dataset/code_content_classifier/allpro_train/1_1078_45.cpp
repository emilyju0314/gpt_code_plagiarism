#include <bits/stdc++.h>
using namespace std;
int n, m;
set<int> ans;
int main() {
  scanf("%d", &n);
  m = 2 * n * n;
  ans.insert(1);
  for (int i = 2; ans.size() <= n; i++) {
    for (set<int>::iterator it = ans.begin(); it != ans.end(); it++)
      if ((*it) * i <= m) {
        ans.insert((*it) * i);
      }
  }
  set<int>::iterator it = ans.end();
  for (int i = 0; i < n; i++) {
    it--;
    printf("%d ", *it);
  }
  printf("\n");
  return 0;
}

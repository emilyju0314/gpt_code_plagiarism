#include <bits/stdc++.h>
using namespace std;
int n, k, a[100003], sorted[100003];
map<int, int> M, used;
vector<int> V[100003];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", a + i), sorted[i] = a[i];
  sort(sorted, sorted + n);
  for (int i = 0; i < n; ++i) {
    M[sorted[i]] = i;
  }
  k = 0;
  for (int i = 0; i < n; ++i) {
    if (!used[a[i]]) {
      if (M[a[i]] == i) {
        V[k].push_back(i);
      } else {
        used[a[i]] = 1;
        V[k].push_back(i);
        int cur = M[a[i]];
        while (!used[a[cur]]) {
          used[a[cur]] = 1;
          V[k].push_back(cur);
          cur = M[a[cur]];
        }
      }
      ++k;
    }
  }
  printf("%d\n", k);
  for (int i = 0; i < k; ++i) {
    printf("%d", (int)V[i].size());
    for (int index : V[i]) {
      printf(" %d", index + 1);
    }
    puts("");
  }
  return 0;
}

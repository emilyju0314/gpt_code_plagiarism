#include <bits/stdc++.h>
using namespace std;
int k, n, give[2005];
set<int> mem;
int initscore(int pos) {
  set<int> scores = mem;
  int prev = *mem.begin();
  scores.erase(prev);
  for (int i = pos + 1; i < k; i++) {
    prev += give[i];
    scores.erase(prev);
  }
  prev = *mem.begin();
  for (int i = pos - 1; i >= 0; i--) {
    prev -= give[i + 1];
    scores.erase(prev);
  }
  return scores.empty() ? prev : 2e9;
}
int main() {
  scanf("%d%d", &k, &n);
  for (int i = 0; i < k; i++) scanf("%d", &give[i]);
  for (int num, i = 0; i < n; i++) {
    scanf("%d", &num);
    mem.insert(num);
  }
  set<int> ans;
  for (int i = 0; i < k; i++) ans.insert(initscore(i));
  ans.erase(2e9);
  printf("%d", ans.size());
}

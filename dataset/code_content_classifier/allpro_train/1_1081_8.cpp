#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, l, sum = 0;
  vector<int> V;
  scanf("%d", &s), scanf("%d", &l);
  for (int i = l; i > 0; --i)
    if (sum + (i & -i) <= s) {
      sum += (i & -i);
      V.push_back(i);
    }
  if (sum != s)
    printf("-1\n");
  else {
    printf("%d\n", V.size());
    for (int i = 0; i < V.size(); ++i) {
      printf("%d ", V[i]);
    }
  }
  return 0;
}

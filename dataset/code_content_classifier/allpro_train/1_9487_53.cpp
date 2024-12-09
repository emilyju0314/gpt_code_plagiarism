#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n;
char s[N];
int lef, sum, rig;
int main() {
  scanf("%d%s", &n, s);
  lef = n + 1;
  rig = 0;
  for (int i = 1; i <= n; ++i) {
    sum += (s[i - 1] != s[i]);
    if (s[i - 1] == s[i]) {
      lef = min(lef, i - 1);
      rig = max(rig, i);
    }
  }
  printf("%d\n", min(n, sum + (lef <= rig ? 2 : 0)));
}

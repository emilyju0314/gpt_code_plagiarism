#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int T, n;
int cnt1, cnt2, cnt3;
char s1[N], s2[N];
int main() {
  scanf("%d", &n);
  scanf("%s%s", s1, s2);
  cnt1 = cnt2 = cnt3 = 0;
  for (int i = 0; i < (n << 1); i++) {
    if (s1[i] == s2[i] && s1[i] == '1') {
      ++cnt3;
    } else if (s1[i] == '1') {
      ++cnt1;
    } else if (s2[i] == '1') {
      ++cnt2;
    }
  }
  int tot1 = 0, tot2 = 0;
  tot2 = cnt3 >> 1;
  tot1 = cnt3 - tot2;
  tot1 += cnt1;
  tot2 += cnt2;
  if ((tot1 == tot2) || (tot2 - 1 == tot1)) {
    puts("Draw");
  } else if (tot1 > tot2) {
    puts("First");
  } else
    puts("Second");
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
char s[10000], t[10000];
int main() {
  int i, j;
  int ls, lt;
  int cnt, res = 0;
  scanf("%s%s", s, t);
  ls = strlen(s), lt = strlen(t);
  for (i = 0; i < lt + ls - 1; i++) {
    cnt = 0;
    for (j = i; i - j < lt; j--) {
      if (j < ls && j >= 0 && s[j] == t[j - i + lt - 1]) cnt++;
    }
    res = max(res, cnt);
  }
  cout << lt - res << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int MAXLEN = 100500;
vector<int> a[33];
int n, m, last;
char s[MAXLEN], ans[MAXLEN];
int main() {
  scanf("%s", s);
  n = strlen(s);
  for (int i = 0; i < n; i++) {
    a[s[i] - 'a'].push_back(i);
  }
  last = 0;
  m = 0;
  for (int i = 30; i >= 0; i--) {
    for (int j = 0; j < (int)a[i].size(); j++)
      if (a[i][j] >= last) {
        last = a[i][j];
        ans[m++] = (char)('a' + i);
      }
  }
  ans[m] = '\0';
  printf("%s", ans);
  return 0;
}

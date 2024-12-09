#include <bits/stdc++.h>
using namespace std;
bool mp[26] = {1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1,
               1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1};
char s[1000001];
int len, ans = 0;
int main() {
  scanf("%s", s + 1);
  len = strlen(s + 1);
  for (int i = 1; i <= len; ++i) ans += mp[s[i] - 'A'];
  (ans == len && len) || (!ans) ? puts("YES") : puts("NO");
  return 0;
}

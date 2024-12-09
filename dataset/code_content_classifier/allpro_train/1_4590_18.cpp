#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
char s[N];
int main() {
  scanf("%s", s);
  int len = strlen(s);
  for (int i = 0; i < len; i++) {
    s[i + len] = s[i];
  }
  len <<= 1;
  int ans = 0, cnt = 0;
  for (int i = 1; i < len; i++) {
    if (s[i] != s[i - 1]) {
      cnt++;
      ans = max(cnt + 1, ans);
    } else {
      ans = max(cnt + 1, ans);
      cnt = 0;
    }
  }
  printf("%d\n", min(ans, len >> 1));
  return 0;
}

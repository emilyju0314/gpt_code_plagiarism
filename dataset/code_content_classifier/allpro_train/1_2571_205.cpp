#include <bits/stdc++.h>
using namespace std;
char s[1000];
int _is(char s) {
  if (s == 'a') return 1;
  if (s == 'e') return 1;
  if (s == 'i') return 1;
  if (s == 'o') return 1;
  if (s == 'u') return 1;
  if (s == 'y') return 1;
  return 0;
}
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  int pre = 0;
  for (int i = 0; i < n; i++) {
    if (_is(s[i])) {
      if (pre == 0) printf("%c", s[i]);
      pre = 1;
    } else {
      printf("%c", s[i]);
      pre = 0;
    }
  }
  puts("");
}

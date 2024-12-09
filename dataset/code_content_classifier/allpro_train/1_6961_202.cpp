#include <bits/stdc++.h>
int letters[100];
char c;
bool res = true;
int main() {
  while (scanf("%c", &c) == 1) {
    if (c != ' ') {
      if (isupper(c))
        ++letters[c - 'A'];
      else
        ++letters[c - 'a' + 27];
    }
    if (c == '\n') break;
  }
  while (scanf("%c", &c) == 1) {
    if (c != ' ') {
      if (isupper(c))
        --letters[c - 'A'];
      else
        --letters[c - 'a' + 27];
    }
  }
  for (int i = 0; i < 52; ++i)
    if (letters[i] < 0) res = false;
  if (res)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}

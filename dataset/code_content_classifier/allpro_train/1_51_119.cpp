#include <bits/stdc++.h>
int main() {
  char password[5];
  char tmp[5];
  scanf("%s", password);
  int n;
  scanf("%d", &n);
  bool flag = 0;
  bool first = 0, second = 0;
  for (int i = 0; i < n; i++) {
    scanf("%s", tmp);
    if (tmp[0] == password[0] && tmp[1] == password[1]) flag = 1;
    if (tmp[0] == password[1]) first = 1;
    if (tmp[1] == password[0]) second = 1;
  }
  if (first && second)
    puts("YES");
  else if (flag)
    puts("YES");
  else
    puts("NO");
}

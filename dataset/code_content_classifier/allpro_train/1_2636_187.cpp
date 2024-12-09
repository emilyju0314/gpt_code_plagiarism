#include <bits/stdc++.h>
int n, ans1 = 0, ans2 = 0, temp;
char s[105][15];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
    if (strcmp(s[0], s[i]) == 0) {
      ans1++;
    } else {
      temp = i;
      ans2++;
    }
  }
  if (ans1 > ans2) {
    printf("%s\n", s[0]);
  } else {
    printf("%s\n", s[temp]);
  }
  return 0;
}

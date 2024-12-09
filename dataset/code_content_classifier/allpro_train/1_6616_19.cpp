#include <bits/stdc++.h>
int main() {
  long long int i, j, k, l;
  long long int idx;
  long long int ls = 0, rs = 0;
  char s[1000000];
  scanf("%s", &s);
  for (i = 0; i < strlen(s); i++) {
    if (s[i] == '^') {
      idx = i;
      break;
    }
  }
  j = 1;
  for (i = idx - 1; i >= 0; i--) {
    if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' ||
        s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' ||
        s[i] == '8' || s[i] == '9') {
      ls = ls + (j * (s[i] - 48));
    }
    j++;
  }
  j = 1;
  for (i = idx + 1; i < strlen(s); i++) {
    if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' ||
        s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' ||
        s[i] == '8' || s[i] == '9') {
      rs = rs + (j * (s[i] - 48));
    }
    j++;
  }
  if (ls > rs)
    printf("left");
  else if (ls < rs)
    printf("right");
  else if (ls == rs)
    printf("balance");
  return 0;
}

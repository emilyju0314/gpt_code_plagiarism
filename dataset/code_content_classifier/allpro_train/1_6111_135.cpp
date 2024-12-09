#include <bits/stdc++.h>
char str[300];
int main() {
  gets(str);
  int flag = 0, len = strlen(str);
  for (int i = 0; i < len; ++i) {
    if (str[i] == ',') {
      printf(",");
      if (i < len - 1) {
        printf(" ");
      }
      flag = 1;
    }
    if (str[i] == '.') {
      if (i != 0) {
        if (flag)
          printf("...");
        else
          printf(" ...");
      } else {
        printf("...");
      }
      i += 2;
      flag = 0;
    }
    if (str[i] >= '0' && str[i] <= '9') {
      printf("%c", str[i]);
      flag = 0;
    }
    if (str[i] == ' ') {
      if (flag)
        continue;
      else {
        int k, j;
        for (j = i - 1; j >= 0; --j) {
          if (str[j] != ' ') break;
        }
        if (str[j] <= '9' && str[j] >= '0') {
          for (k = i + 1; k < len; ++k) {
            if (str[k] != ' ') break;
          }
          if (str[k] <= '9' && str[k] >= '0') {
            printf(" ");
            flag = 1;
          }
        }
      }
    }
  }
  return 0;
}

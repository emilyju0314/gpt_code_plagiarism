#include <bits/stdc++.h>
int main() {
  long long n, i, count1 = 0, count2 = 0, j, k, b, l;
  char ar[31][21], ap[3], al[2];
  char at[27] = "abcdefghijklmnopqrstuvwxyz";
  scanf("%lld", &n);
  for (i = 0; i < n; i++) scanf("%s", ar[i]);
  for (k = 0; k < 26; k++) {
    l = 0;
    count1 = 0;
    al[l++] = at[k];
    al[l++] = '\0';
    for (i = 0; i < n; i++) {
      if (strstr(ar[i], al)) count1++;
    }
    if (count1 == 0) {
      printf("%c\n", at[k]);
      return 0;
    }
  }
  for (i = 0; i < 26; i++) {
    for (j = 0; j < 26; j++) {
      b = 0;
      count2 = 0;
      ap[b++] = at[i];
      ap[b++] = at[j];
      ap[b++] = '\0';
      for (k = 0; k < n; k++) {
        if (strstr(ar[k], ap)) count2++;
      }
      if (count2 == 0) {
        printf("%s\n", ap);
        return 0;
      }
    }
  }
  return 0;
}

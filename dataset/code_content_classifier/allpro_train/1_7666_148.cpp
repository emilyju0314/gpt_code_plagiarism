#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, k, l, m, countD, countR, countL, countU;
  char s[10000];
  scanf("%d", &n);
  scanf("%s", s);
  int count = 0;
  for (i = 0; i < n; i++) {
    countD = countU = countL = countR = 0;
    for (j = i; j < n; j++) {
      if (s[j] == 'D')
        countD++;
      else if (s[j] == 'U')
        countU++;
      else if (s[j] == 'R')
        countR++;
      else
        countL++;
      if (countD == countU && countR == countL) count++;
    }
  }
  printf("%d", count);
  return 0;
}

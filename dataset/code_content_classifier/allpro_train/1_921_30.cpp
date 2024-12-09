#include <bits/stdc++.h>
using namespace std;
int cnt[10];
int main() {
  int k, sum = 0, res = 0;
  scanf("%d", &k);
  char c;
  scanf("%c", &c);
  scanf("%c", &c);
  while (c != '\n') {
    cnt[c - '0']++;
    sum += c - '0';
    scanf("%c", &c);
  }
  for (int i = 0; i < 9 && sum < k; i++) {
    while (cnt[i]-- && sum < k) {
      sum += 9 - i;
      res++;
    }
  }
  printf("%d", res);
  return 0;
}

#include <bits/stdc++.h>
int main() {
  char ch[100005];
  long long p[40];
  memset(p, 0, sizeof(p));
  scanf("%s", ch);
  int len = strlen(ch);
  for (int i = 0; i < len; ++i) {
    if (ch[i] >= '0' && ch[i] <= '9') {
      p[ch[i] - '0']++;
    } else {
      p[ch[i] - 'a' + 10]++;
    }
  }
  long long sum = 0;
  for (int i = 0; i < 40; ++i) sum += p[i] * p[i];
  printf("%lld\n", sum);
  return 0;
}

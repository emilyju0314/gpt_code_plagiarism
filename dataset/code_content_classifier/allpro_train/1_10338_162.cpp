#include <bits/stdc++.h>
using namespace std;
int a[300000];
int main() {
  int n, m, i, t;
  long long tmp, k;
  char ch[100000], c2[10], c3[10], c4[10], c5[10], c6[10];
  string z, s, ps, tz;
  bool open = false;
  scanf("%d", &t);
  for (i = 0; i < t; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a + t);
  tmp = 0;
  for (i = 1; i <= t; i++) {
    tmp += abs(i - a[i - 1]);
  }
  printf("%I64d\n", tmp);
  return 0;
}

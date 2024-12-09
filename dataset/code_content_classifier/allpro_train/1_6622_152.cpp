#include <bits/stdc++.h>
using namespace std;
int jc[15];
char s[20];
int ss[50];
int main() {
  jc[0] = 1;
  for (int i = 1; i < 10; i++) {
    jc[i] = jc[i - 1] * i;
  }
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  long long ans = 1;
  int k = 0;
  for (int i = 0; i < n; i++) {
    ans = jc[s[i] - '0'];
    while (ans % jc[7] == 0) {
      ss[k++] = 7;
      ans /= jc[7];
    }
    while (ans % jc[5] == 0) {
      ss[k++] = 5;
      ans /= jc[5];
    }
    while (ans % jc[3] == 0) {
      ss[k++] = 3;
      ans /= jc[3];
    }
    while (ans % jc[2] == 0) {
      ss[k++] = 2;
      ans /= jc[2];
    }
  }
  sort(ss, ss + k);
  for (int i = k - 1; i >= 0; i--) printf("%d", ss[i]);
  printf("\n");
}

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int d[N][3];
void ADD(int &a, int &b) {
  a += b;
  if (a > (int)(1e9 + 7)) a -= (int)(1e9 + 7);
}
char s[N];
int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  d[0][0] = d[0][1] = 1;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0' || s[i] == '?') {
      ADD(d[i][0], d[i - 1][0]);
    }
    if (s[i] == '1' || s[i] == '?') {
      ADD(d[i][0], d[i - 1][2]);
      ADD(d[i][1], d[i - 1][0]);
    }
    if (s[i] == '2' || s[i] == '?') {
      ADD(d[i][1], d[i - 1][2]);
    }
    if (s[i] == '*' || s[i] == '?') {
      ADD(d[i][2], d[i - 1][1]);
      ADD(d[i][2], d[i - 1][2]);
    }
  }
  ADD(d[n][0], d[n][2]);
  printf("%d\n", d[n][0]);
  return 0;
}

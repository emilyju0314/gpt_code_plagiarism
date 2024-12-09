#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 9;
inline int read() {
  char c = getchar();
  int flag = 1;
  int x = 0;
  while (!(c >= '0' && c <= '9')) {
    if (c == '-') flag = 0;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  if (flag) return x;
  return ~(x - 1);
}
char s[N];
int j, n, k, i, sum;
long long space, x, y;
int main() {
  n = read();
  cin >> x >> y;
  scanf("%s", s);
  s[n] = '1';
  n++;
  sum = s[0] - '0';
  space = 0;
  for (i = 1; i < n; i++) {
    sum += s[i] - '0';
    if (s[i] == '1' && s[i - 1] == '0') space++;
  }
  if (sum == n)
    printf("0");
  else if (x <= y)
    cout << (space - 1) * x + y;
  else
    cout << space * y;
  return 0;
}

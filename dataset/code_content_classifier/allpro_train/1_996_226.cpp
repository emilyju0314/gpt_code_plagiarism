#include <bits/stdc++.h>
using namespace std;
const long long INF9 = 1e9 + 9;
const long long INF = 1e9 + 7;
long long gcd(long long b, long long s) { return (s != 0) ? gcd(s, b % s) : b; }
long long Pow(long long a, long long b, long long c) {
  if (b == 0)
    return 1 % c;
  else if (b == 1)
    return a % c;
  else {
    long long A = Pow(a, b / 2, c);
    A = (A * A) % c;
    if (b & 1) A = (A * a) % c;
    return A;
  }
}
const int N = 1e5 + 5;
char s[N];
int c[27], u[27];
inline int conv(char c) {
  if (c == 'A')
    return 0;
  else if (c == 'G')
    return 1;
  else if (c == 'T')
    return 2;
  else
    return 3;
}
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  for (int i = 0; i < n; i++) ++c[conv(s[i])];
  long long re = 1;
  for (int i = 1; i <= n; i++) {
    int sum = -1;
    long long mul = 0;
    for (int j = 0; j < 4; j++) {
      if (sum < c[j]) {
        sum = c[j];
        mul = 1;
      } else if (sum == c[j])
        ++mul;
    }
    re = (re * mul) % INF;
  }
  printf("%I64d\n", re);
}

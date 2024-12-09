#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int a[200];
char s[N];
int S(long long b) {
  int ret = 0;
  while (b) {
    ret += b % 10;
    b = b / 10;
  }
  return ret;
}
int main() {
  long long n, l, r;
  cin >> n;
  l = n / 2;
  r = n - l;
  if (l < r) swap(l, r);
  int cnt = 0;
  long long tmp = n;
  while (n) {
    a[cnt++] = n % 10;
    n /= 10;
  }
  n = tmp;
  if (a[cnt - 1] == 1) {
    long long z = 0;
    for (int i = (cnt - 1) - 1; i >= (0); --i) {
      z = z * 10 + 9;
    }
    printf("%d\n", S(z) + S(n - z));
  } else {
    long long z = 0;
    a[cnt - 1]--;
    z = z * 10 + a[cnt - 1];
    for (int i = (cnt - 1) - 1; i >= (0); --i) {
      z = z * 10 + 9;
    }
    printf("%d\n", S(z) + S(n - z));
  }
}

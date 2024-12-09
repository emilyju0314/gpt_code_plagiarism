#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long s = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  return s * f;
}
long long num[100003];
long long sum(long long x) { return (x + 1) * x / 2; }
long long sum2(long long x) { return (x + 1) * (x + 2) * x / 6; }
long long ch(long long a, long long b, long long c) {
  if ((a & 1) + (b & 2) + (c & 4) == 7)
    return 1;
  else
    return 0;
}
int check(long long a, long long b, long long c) {
  if (ch(a, b, c) || ch(a, c, b) || ch(b, c, a) || ch(b, a, c) || ch(c, a, b) ||
      ch(c, b, a))
    return 1;
  else
    return 0;
}
long long gcd(long long a, long long b) {
  if (a < b) {
    long long t = a;
    a = b;
    b = t;
  }
  return a % b == 0 ? b : gcd(b, a % b);
}
int main() {
  for (int i = 1; i <= 100000; i++) {
    for (int j = i; j <= 100000; j += i) {
      num[j]++;
    }
  }
  int t = read();
  while (t--) {
    long long a = read(), b = read(), c = read();
    long long ab = num[gcd(a, b)];
    long long bc = num[gcd(b, c)];
    long long ac = num[gcd(a, c)];
    long long abc = num[gcd(gcd(a, b), c)];
    a = num[a];
    b = num[b];
    c = num[c];
    long long block[10];
    block[1] = a - ab - ac + abc;
    block[3] = ab - abc;
    block[2] = b - ab - bc + abc;
    block[4] = c - ac - bc + abc;
    block[7] = abc;
    block[5] = ac - abc;
    block[6] = bc - abc;
    long long ans = 0;
    for (int i = 1; i <= 7; i++) {
      for (int j = i; j <= 7; j++) {
        for (int k = j; k <= 7; k++) {
          if (check(i, k, j)) {
            if (i == j && j == k) {
              ans += sum2(block[i]);
            } else if (i == j) {
              ans += sum(block[i]) * block[k];
            } else if (j == k) {
              ans += sum(block[j]) * block[i];
            } else if (k == i) {
              ans += sum(block[i]) * block[j];
            } else {
              ans += block[i] * block[j] * block[k];
            }
          }
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}

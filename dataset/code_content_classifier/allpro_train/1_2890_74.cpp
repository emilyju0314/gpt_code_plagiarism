#include <bits/stdc++.h>
using namespace std;
int MAX(long long int a, long long int b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}
int MIN(long long int a, long long int b) {
  if (a < b) {
    return a;
  } else {
    return b;
  }
}
int gcd(long long int a, long long int b) {
  long long int c;
  while (a != 0) {
    c = a;
    a = b % a;
    b = c;
  }
  return b;
}
int main() {
  int i;
  int k, a, b, v;
  scanf("%d%d%d%d", &k, &a, &b, &v);
  int ans = 0;
  while (1) {
    if (a <= 0) {
      break;
    }
    ans++;
    if (b == 0) {
      a = a - v;
    } else {
      if (b + 1 > k) {
        a = a - (v * k);
        b = b - (k - 1);
      } else {
        a = a - (b + 1) * v;
        b = 0;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

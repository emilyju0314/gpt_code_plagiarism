#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7f7f7f7f;
int BigMod(long long int B, long long int P, long long int M) {
  long long int R = 1;
  while (P > 0) {
    if (P % 2 == 1) R = (R * B) % M;
    P /= 2;
    B = (B * B) % M;
  }
  return (int)R;
}
long long int maxDivide(long long int a, long long int b) {
  while (a % b == 0) a = a / b;
  return a;
}
long long int isUgly(long long int no) {
  no = maxDivide(no, 2);
  no = maxDivide(no, 3);
  no = maxDivide(no, 5);
  return (no == 1) ? 1 : 0;
}
long long int myXOR(long long int x, long long int y) {
  long long int res = 0;
  for (long long int i = 31; i >= 0; i--) {
    bool b1 = x & (1 << i);
    bool b2 = y & (1 << i);
    bool xoredBit = (b1 & b2) ? 0 : (b1 | b2);
    res <<= 1;
    res |= xoredBit;
  }
  return res;
}
long long int ar[100005];
int main() {
  long long int x, n, m;
  cin >> n;
  for (long long int i = 0; i <= n - 1; i++) {
    cin >> x;
    ar[i] = x;
  }
  sort(ar, ar + n);
  m = 0;
  for (long long int i = 0; i <= n - 3; i++) {
    if (ar[i] + ar[i + 1] > ar[i + 2]) {
      m = 1;
      break;
    }
  }
  if (m == 1)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}

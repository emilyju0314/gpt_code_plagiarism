#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
const int inf = 1 << 28;
int main() {
  int n, p, q;
  cin >> n >> p >> q;
  string str;
  cin >> str;
  int N = n;
  if (N % p == 0) {
    cout << N / p << endl;
    for (int i = 0; i < N / p; i++) {
      cout << str.substr(i * p, p) << endl;
      ;
    }
    return 0;
  }
  if (N % q == 0) {
    cout << N / q << endl;
    for (int i = 0; i < N / q; i++) {
      cout << str.substr(i * q, q) << endl;
      ;
    }
    return 0;
  }
  int x = 1, y = 1;
  for (x = 1; x <= N; x++) {
    for (y = 1; y <= N; y++)
      if (x * p + y * q == N) {
        goto A;
      }
  }
A:;
  if (x * p + y * q == N) {
    cout << x + y << endl;
    for (int i = 0; i < x; i++) {
      cout << str.substr(i * p, p) << endl;
    }
    for (int i = 0; i < y; i++) {
      cout << str.substr(x * p + i * q, q) << endl;
    }
    return 0;
  }
  return puts("-1");
  return 0;
}

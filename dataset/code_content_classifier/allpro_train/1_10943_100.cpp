#include <bits/stdc++.h>
using namespace std;
template <class T>
void fmax(T &a, const T &b) {
  if (a < b) a = b;
}
template <class T>
void fmin(T &a, const T &b) {
  if (a > b) a = b;
}
template <class T>
T sqr(const T &a) {
  return a * a;
}
int n, m;
long long rec[33333];
int main() {
  cin >> n >> m;
  long long ans = 0;
  int l = m + 1, r = n - m;
  for (int x1 = (int)l; x1 <= (int)r; x1++) {
    int x2 = n + 1 - x1;
    if (x2 < x1)
      rec[x1] = rec[x2];
    else {
      long long tmp = 0;
      int la = m + 1 + x1, ra = n - m + x1;
      int lb = m + 1 + x2, rb = n - m + x2;
      int C = 3 * x1 * x2 - 1;
      for (int A = (int)la; A <= (int)ra; A++) {
        int M = C / A;
        if (M >= rb)
          tmp += rb - lb + 1;
        else if (M >= lb)
          tmp += M - lb + 1;
        else
          break;
      }
      rec[x1] = tmp;
    }
    ans += rec[x1];
  }
  cout << ans * 3 << endl;
}

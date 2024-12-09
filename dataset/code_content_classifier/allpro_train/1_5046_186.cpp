#include <bits/stdc++.h>
using namespace std;
inline int toInt(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}
template <class T>
inline string toString(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}
int main() {
  int d;
  cin >> d;
  int cnt = 0;
  const int n = 1000000;
  vector<int> est(n + 1, 1);
  for (int k = 2; k < n; k++) {
    if (est[k]) {
      for (int j = 2; k * j <= n; j++) {
        est[k * j] = 0;
      }
    }
  }
  int i;
  for (i = 2;; i++) {
    int k = i;
    int rev = 0;
    while (true) {
      rev += k % 10;
      k /= 10;
      if (k == 0) break;
      rev *= 10;
    }
    if (i != rev && est[i] && est[rev]) {
      cnt++;
      if (cnt == d) {
        break;
      }
    }
  }
  cout << i;
}

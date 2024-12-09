#include <bits/stdc++.h>
using namespace std;
const int N = 300000;
bool can[N];
int n, k;
bool f(int t) {
  bool* tmp = new bool[n];
  fill(tmp, tmp + n, false);
  tmp[0] = true;
  int last = 0;
  int have = k - 1;
  while (have > 0 && !tmp[n - 1]) {
    bool seted = false;
    for (size_t i = min(last + t + 1, n - 1); i > last; i--) {
      if (can[i]) {
        tmp[i] = true;
        last = i;
        seted = true;
        have--;
        break;
      }
    }
    if (!seted) {
      return false;
    }
  }
  return tmp[n - 1];
}
int main() {
  cin >> n >> k;
  string s;
  cin >> s;
  for (size_t i = 0; i < n; i++) {
    can[i] = s[i] == '0';
  }
  int lo = 0;
  int hi = n - 2;
  while (hi - lo > 1) {
    int middle = (hi + lo) >> 1;
    if (f(middle)) {
      hi = middle;
    } else {
      lo = middle + 1;
      ;
    }
  }
  while (lo <= hi) {
    if (!f(lo)) {
      lo++;
    } else {
      break;
    }
  }
  cout << lo;
  return 0;
}

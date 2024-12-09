#include <bits/stdc++.h>
int mas[400], arr[400], n;
using namespace std;
bool ok(long long h, long long w) {
  if (4 * w / 5 <= h && 5 * w / 4 >= h) return 1;
  return 0;
}
int main() {
  long long h1 = 1, h, w1 = 1, w, w_a = 0, h_a = 0, s = 0;
  cin >> h >> w;
  while (h1 <= h) {
    if (ok(h1, w)) {
      long long sum = h1 * w;
      if (sum > s) {
        s = sum;
        h_a = h1;
        w_a = w;
      }
    }
    long long cur = 5 * h1 / 4;
    if (cur <= w)
      if (ok(h1, cur)) {
        long long sum = h1 * cur;
        if (sum > s) {
          s = sum;
          h_a = h1;
          w_a = cur;
        }
      }
    h1 *= 2;
  }
  long long w_a1 = 0, h_a1 = 0, s1 = 0;
  while (w1 <= w) {
    if (ok(h, w1)) {
      long long sum = h * w1;
      if (sum > s1) {
        s1 = sum;
        h_a1 = h;
        w_a1 = w1;
      }
    }
    long long cur = 5 * w1 / 4;
    if (cur <= h)
      if (ok(cur, w1)) {
        long long sum = w1 * cur;
        if (sum > s1) {
          s1 = sum;
          h_a1 = cur;
          w_a1 = w1;
        }
      }
    w1 *= 2;
  }
  if (s > s1)
    cout << h_a << " " << w_a;
  else if (s1 > s)
    cout << h_a1 << " " << w_a1;
  else if (h_a > h_a1)
    cout << h_a << " " << w_a;
  else
    cout << h_a1 << " " << w_a1;
  return 0;
}

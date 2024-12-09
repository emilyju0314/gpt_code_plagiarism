#include <bits/stdc++.h>
int left(int n) { return n << 1; }
int right(int n) { return (n << 1) + 1; }
namespace patch {
template <typename T>
std::string to_string(const T& n) {
  std::ostringstream stm;
  stm << n;
  return stm.str();
}
}  // namespace patch
using namespace std;
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
int ii[] = {-2, -2, -3, -1, -1, +1};
int jj[] = {+1, -1, -1, -2, -3, -2};
template <typename T>
inline T GCD(T a, T b) {
  a = abs(a);
  b = abs(b);
  while (b) {
    a = a % b;
    swap(a, b);
  }
  return a;
}
template <typename T>
inline T LCM(T x, T y) {
  T tp = GCD(x, y);
  if ((x / tp) * 1. * y > 9e18) return 9e18;
  return (x / tp) * y;
}
template <typename T>
inline T BigMod(T A, T B, T M) {
  T ret = 1;
  while (B) {
    if (B & 1) ret = (ret * A) % M;
    A = (A * A) % M;
    B = B >> 1;
  }
  return ret;
}
template <typename T>
inline T ModInv(T A, T M) {
  return BigMod(A, M - 2, M);
}
int main() {
  int n, k, a, b, c, d;
  cin >> n >> k >> a >> b;
  c = a, d = b;
  char str[200000];
  int cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < n; i++) {
    if (a > b && cnt1 < k) {
      cnt1++;
      cnt2 = 0;
      a--;
      str[i] = 'G';
    } else if (a <= b && cnt2 < k) {
      cnt2++;
      cnt1 = 0;
      b--;
      str[i] = 'B';
    }
    if (cnt1 == k) {
      i++;
      str[i] = 'B';
      b--;
      cnt1 = 0;
    }
    if (cnt2 == k) {
      i++;
      str[i] = 'G';
      a--;
      cnt2 = 0;
    }
  }
  int g = 0, bl = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] == 'G')
      g++;
    else
      bl++;
  }
  if (g == c && bl == d) {
    for (int i = 0; i < n; i++) cout << str[i];
  } else
    cout << "NO";
}

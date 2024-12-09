#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
const int dxhorse[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dyhorse[] = {1, -1, 2, -2, 2, -2, 1, -1};
template <typename T>
inline void maxi(T &x, T y) {
  x = max(x, y);
}
template <typename T>
inline void mini(T &x, T y) {
  x = min(x, y);
}
template <typename T>
inline void add(T &x, T y) {
  x += y;
  if (x >= (1000 * 1000 * 1000 + 7)) x -= (1000 * 1000 * 1000 + 7);
}
template <typename T>
inline void sub(T &x, T y) {
  x -= y;
  if (x < 0) x += (1000 * 1000 * 1000 + 7);
}
template <typename T>
inline T mul(T a, T b) {
  long long int x = (long long)a * b;
  x %= (1000 * 1000 * 1000 + 7);
  return x;
}
template <typename T>
inline T power(T base, T exp) {
  long long int result = 1;
  while (exp) {
    if (exp & 1) result *= base;
    exp >>= 1;
    base *= base;
  }
  return result;
}
template <typename T>
inline T power(T a, T b, T mod) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}
template <typename T>
inline bool isPrime(T n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long int i = 5; i * i <= n; i += 6) {
    if ((n % i == 0) || (n % (i + 2) == 0)) {
      return false;
    }
  }
  return true;
}
bool is_digit(char x) { return x >= '0' && x <= '9'; }
bool is_upper(char x) { return x >= 'A' && x <= 'Z'; }
bool is_lower(char x) { return x >= 'a' && x <= 'z'; }
bool is_char(char x) {
  return x == '!' || x == '@' || x == '#' || x == '$' || x == '%' || x == '&';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int x;
  cin >> x;
  if (x != 2)
    cout << 1 << '\n';
  else
    cout << 2 << '\n';
  return 0;
}

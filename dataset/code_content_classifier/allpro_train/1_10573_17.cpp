#include <bits/stdc++.h>
using namespace std;
long long a, g, A, B, sum;
string num, zero, ans;
inline long long gcd(long long u, long long v) {
  for (; v;) {
    u %= v;
    swap(u, v);
  }
  return u;
}
inline long long S(long long u) {
  long long res = 0;
  for (; u; u /= 10) res += u % 10;
  return res;
}
int main() {
  long long i, j, tmp, t;
  for (i = 1; i <= 5; i++) zero += '0';
  cin >> a;
  if (a == 1) {
    puts("1");
    return 0;
  }
  B = S(a) * a - 1;
  for (i = 0, tmp = 1; tmp; i++) {
    if (num[num.size() - 1] != '9' && a * (S(a - tmp) + 1) < sum + 1) {
      A = sum + 1 - a * (S(a - tmp) + 1);
      g = gcd(A, B);
      if ((A / g) * (5 + 1) + (B / g) * (5 + num.size()) <= 500000) {
        num[num.size() - 1]++;
        break;
      }
    }
    tmp = tmp * 10;
    t = tmp / a;
    sum += t;
    if (num.size() || t) num += t + '0';
    tmp %= a;
  }
  if (!tmp) {
    if (a > sum) {
      puts("-1");
      return 0;
    } else if (a == sum) {
      cout << num;
      return 0;
    }
    A = sum - a;
    g = gcd(A, B);
  }
  for (i = 1; i <= (B / g); i++) ans += num + zero;
  for (i = 1; i <= (A / g); i++) ans += "1" + zero;
  cout << ans;
}

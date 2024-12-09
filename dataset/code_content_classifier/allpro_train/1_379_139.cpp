#include <bits/stdc++.h>
int main() {
  long long cnt1, cnt2, x, y;
  std::cin >> cnt1 >> cnt2 >> x >> y;
  long long l = 0, r = 1e11;
  while (l + 1 < r) {
    long long mid = (l + r) / 2;
    long long count1 = mid / (x * y);
    long long forFirst = mid / y - count1;
    long long forSecond = mid / x - count1;
    long long rest = mid - mid / x - mid / y + mid / (x * y);
    long long tmp = cnt1 - forFirst;
    if (tmp <= 0) {
      tmp = 0;
    }
    if (forSecond + rest - tmp >= cnt2 && rest >= tmp) {
      r = mid;
    } else {
      l = mid;
    }
  }
  std::cout << r << std::endl;
  return 0;
}

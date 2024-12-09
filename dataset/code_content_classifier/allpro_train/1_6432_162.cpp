#include <bits/stdc++.h>
using namespace std;
int prime(int a) {
  if (a == 2)
    return 1;
  else if (a % 2 == 0)
    return 0;
  else {
    for (int i = 3; i <= sqrt(a); i += 2) {
      if (a % i == 0) return 0;
    }
    return 1;
  }
}
int main() {
  int n, k, l = 0, flag, flag1;
  cin >> n >> k;
  for (int p = 2; p <= n; p++) {
    if (prime(p)) {
      flag1 = flag = 0;
      for (int i = p / 2; i >= 2; i--) {
        for (int j = p / 2; j <= p; j++) {
          if (1 + j + i == p && prime(j) && prime(i) && j != i) {
            flag1 = 1;
            for (int m = i + 1; m < j; m++) {
              if (prime(m)) {
                flag = 1;
                break;
              }
            }
            if (flag == 0) l++;
            break;
          }
        }
        if (flag1 == 1) break;
      }
    }
  }
  if (l >= k)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int a;
int sumNum(int n);
int main() {
  cin >> a;
  for (int i = a; i; i++) {
    int tmp = sumNum(i);
    if (tmp % 4 == 0) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
int sumNum(int n) {
  int res = 0;
  while (n) {
    res += n % 10;
    n /= 10;
  }
  return res;
}

#include <bits/stdc++.h>
using namespace std;
int sum(int n) {
  int sum = 0;
  for (int i = 0; i <= n; i++) {
    sum = sum + i;
  }
  return sum;
}
int main() {
  int n, k, difference;
  cin >> n >> k;
  difference = abs(n - k);
  if (difference % 2 == 0) {
    cout << sum(difference / 2) + sum(difference / 2);
  } else {
    cout << sum(difference / 2) + sum(difference / 2) + difference / 2 + 1;
  }
}

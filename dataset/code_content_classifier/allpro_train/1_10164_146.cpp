#include <bits/stdc++.h>
using namespace std;
int main() {
  int sum1 = 0, sum2 = 0, sum3 = 0, n, b, c;
  cin >> n;
  int arr[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  if (n == 1) {
    cout << "chest";
    return 0;
  } else if (n == 2) {
    b = max(arr[1], arr[2]);
    if (b == arr[1]) {
      cout << "chest";
    } else {
      cout << "biceps";
    }
    return 0;
  } else if (n > 2) {
    for (int i = 1; i <= (n + 2) / 3; i++) {
      sum1 += arr[3 * i - 2];
    }
    for (int i = 1; i <= (n + 1) / 3; i++) {
      sum2 += arr[3 * i - 1];
    }
    for (int i = 1; i <= (n) / 3; i++) {
      sum3 += arr[3 * i];
    }
  }
  c = max(max(sum1, sum2), sum3);
  if (c == sum1) {
    cout << "chest";
  } else if (c == sum2) {
    cout << "biceps";
  } else {
    cout << "back";
  }
  return 0;
}

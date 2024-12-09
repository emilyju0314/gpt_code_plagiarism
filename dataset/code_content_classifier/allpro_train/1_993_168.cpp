#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  bool valid = true;
  long long n, crnt, prev, i = 2, b = -1, e = -1, arr[100001];
  cin >> n;
  for (long long j = 1; j <= n; j++) cin >> arr[j];
  crnt = arr[1];
  while (i <= n) {
    prev = crnt;
    crnt = arr[i];
    if (prev > crnt) {
      b = i - 1;
      break;
    }
    i++;
  }
  while (i <= n) {
    prev = crnt;
    crnt = arr[i];
    if (prev < crnt) {
      e = i - 1;
      break;
    }
    i++;
  }
  while (i <= n) {
    prev = crnt;
    crnt = arr[i];
    if (prev > crnt) {
      valid = false;
      break;
    }
    i++;
  }
  if (valid) {
    if (b == -1) {
      b = 1;
      e = 1;
    }
    if (e == -1) e = n;
    if (e + 1 <= n && arr[b] > arr[e + 1]) {
      valid = false;
    }
    if (valid && (b > 1 && arr[e] < arr[b - 1])) {
      valid = false;
    }
  }
  if (valid) {
    cout << "yes" << '\n' << b << ' ' << e;
  } else {
    cout << "no";
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int arr[maxn];
int main() {
  int n, mi, ma, a, b, c, avg;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  mi = *min_element(arr, arr + n);
  ma = *max_element(arr, arr + n);
  if (ma - mi < 2) {
    cout << n << endl;
    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
  } else {
    a = count(arr, arr + n, mi);
    avg = (mi + ma) / 2;
    b = count(arr, arr + n, avg);
    c = n - a - b;
    int t = max(b / 2, min(a, c));
    if (t == min(a, c)) {
      a -= t;
      c -= t;
      b += 2 * t;
    } else {
      b -= 2 * t;
      a += t;
      c += t;
    }
    cout << n - 2 * t << endl;
    for (int i = 0; i < n; i++) {
      cout << avg + (i < a ? -1 : i < a + b ? 0 : 1) << " ";
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  long int n, i, b[1000006] = {0}, a[105], max = 0, count = 0;
  char ch;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> ch >> a[i];
    if (ch == '-') a[i] = -a[i];
    b[abs(a[i]) - 1]++;
    if ((a[i] < 0) && b[abs(a[i]) - 1] == 1) {
      max++;
    } else if ((a[i] < 0) && (b[abs(a[i]) - 1] != 1)) {
      count--;
    } else if (a[i] > 0) {
      count++;
    }
    if (max < count) {
      max = count;
    }
  }
  cout << max;
  return 0;
}

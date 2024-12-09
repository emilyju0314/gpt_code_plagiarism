#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[100], max = 0, min = 110;
  int pos1 = 0, pos2 = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > max) {
      pos1 = i;
      max = a[i];
    }
    if (a[i] <= min) {
      pos2 = i;
      min = a[i];
    }
  }
  pos2 += 1;
  int sum = pos1 + (n - pos2);
  if (pos1 >= pos2) sum -= 1;
  cout << sum;
  return 0;
}

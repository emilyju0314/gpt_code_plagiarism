#include <bits/stdc++.h>
using namespace std;
const int s = 10010;
int a[s], x, y, n, sum;
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    sum += a[x]++;
    sum += a[y]++;
  }
  cout << sum;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, n, w, s, sum;
  cin >> k >> n >> w;
  s = 0;
  sum = 0;
  for (int i = 1; i <= w; i++) {
    s = i * k;
    sum += s;
  }
  if (sum < n)
    cout << "0";
  else
    cout << sum - n;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int cnt = 0;
  long long min = 1000000000;
  long long s = 0;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    s += x;
    if (x % 2 == 1) {
      cnt++;
      if (x < min) min = x;
    }
  }
  if (cnt % 2 == 0)
    cout << s;
  else
    cout << s - min;
}

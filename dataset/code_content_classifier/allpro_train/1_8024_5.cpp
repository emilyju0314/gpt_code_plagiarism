#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t = 0;
  cin >> n;
  int a[n], b[601] = {0};
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[a[i]]++;
  }
  for (int i = 1; i < 601; i++) {
    if (b[i] > 0) t++;
  }
  cout << t;
  return 0;
}

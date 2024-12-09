#include <bits/stdc++.h>
using namespace std;
int a[105];
char c[105][105];
int main() {
  a[2] = 1;
  for (int i = 3; i < 102; i++) {
    a[i] = a[i - 1] + i - 1;
  }
  int n, ts;
  long long sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%s", c[i]);
  }
  for (int i = 0; i < n; i++) {
    ts = 0;
    for (int j = 0; j < n; j++) {
      if (c[i][j] == 'C') ts++;
    }
    sum += a[ts];
  }
  for (int i = 0; i < n; i++) {
    ts = 0;
    for (int j = 0; j < n; j++) {
      if (c[j][i] == 'C') ts++;
    }
    sum += a[ts];
  }
  cout << sum;
  return 0;
}

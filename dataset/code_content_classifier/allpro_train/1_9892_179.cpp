#include <bits/stdc++.h>
using namespace std;
long long pw(long long b, long long r, long long md) {
  long long ans = 1;
  while (r) {
    if (r & 1) ans = (ans * b) % md;
    b = (b * b) % md;
    r >>= 1;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long k;
  cin >> k;
  if (k == 0)
    cout << 1 << " " << 1 << '\n' << 1 << '\n';
  else if (k == 1) {
    cout << 3 << " " << 4 << '\n';
    long long arr[3][4] = {{7, 3, 3, 1}, {4, 8, 3, 6}, {7, 7, 7, 3}};
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 4; j++) cout << arr[i][j] << " ";
      cout << endl;
    }
  } else {
    cout << 3 << " " << 3 << '\n';
    long long ans = 1;
    while (ans <= k) ans *= 2;
    long long arr[3][3];
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) arr[i][j] = ans;
    arr[0][0] = arr[1][0] = ans + k;
    arr[2][2] = k;
    arr[1][1] = k;
    arr[2][1] = ans + k;
    arr[1][2] = ans + k;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) cout << arr[i][j] << " ";
      cout << endl;
    }
  }
  return 0;
}

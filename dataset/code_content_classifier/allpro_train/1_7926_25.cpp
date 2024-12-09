#include <bits/stdc++.h>
using namespace std;
const int MX = 700;
long long bc[MX][MX];
long long c(int n, int k) { return bc[n][k]; }
void intialize() {
  for (int i = 0; i < MX; i++) {
    bc[i][0] = 1;
    bc[i][i] = 1;
  }
  for (int i = 1; i < MX; i++)
    for (int j = 1; j < i; j++) bc[i][j] = bc[i - 1][j - 1] + bc[i - 1][j];
}
int main() {
  intialize();
  long long n;
  cin >> n;
  long long ans = c(4 + n, 5) * c(2 + n, 3);
  cout << ans;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long mod = 1e9 + 7;
const int N = 100100;
void add(long long &a, long long b) {
  a += b;
  a %= mod;
}
int n, m;
long long dph[N][2], dpv[N][2];
int main() {
  cin >> n >> m;
  dph[1][0] = dph[1][1] = 1;
  dph[2][0] = dph[2][1] = 2;
  for (int i = 3; i <= m; i++) {
    add(dph[i][0], dph[i - 2][1]);
    add(dph[i][0], dph[i - 1][1]);
    add(dph[i][1], dph[i - 2][0]);
    add(dph[i][1], dph[i - 1][0]);
  }
  dpv[1][0] = dpv[1][1] = 1;
  dpv[2][0] = dpv[2][1] = 2;
  for (int i = 3; i <= n; i++) {
    add(dpv[i][0], dpv[i - 2][1]);
    add(dpv[i][0], dpv[i - 1][1]);
    add(dpv[i][1], dpv[i - 2][0]);
    add(dpv[i][1], dpv[i - 1][0]);
  }
  cout << (dph[m][0] + dph[m][1] + dpv[n][0] + dpv[n][1] - 2) % mod;
}

#include <bits/stdc++.h>
using namespace std;
int p5[10] = {1, 5, 25, 125, 625, 3125, 15625, 78125, 390625, 1953125};
map<int, int> dp[2001][9];
int N, a[2000], b[2000];
void precomp() {}
int set0(int bit, int idx) {
  return (bit / p5[idx + 1] * p5[idx + 1]) + (bit % p5[idx]);
}
int gett(int bit, int idx) { return (bit / p5[idx]) % 5; }
int sett(int bit, int idx, int val) {
  int ret = set0(bit, idx);
  return ret + val * p5[idx];
}
int addd(int bit, int idx, int val) { return bit + val * p5[idx]; }
int sum(int bit) {
  int ret = 0;
  while (bit) {
    ret += (bit % 5);
    bit /= 5;
  }
  return ret;
}
void read() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d %d", a + i, b + i);
    a[i]--;
    b[i]--;
  }
}
void printState(int idx, int pos, int bit, int ret) {
  cout << idx << " " << pos << "  ";
  for (int i = 0; i < 9; i++) {
    cout << gett(bit, i) << ",";
  }
  cout << "   " << ret << "\n";
}
int solve(int idx, int pos, int bit) {
  if (idx == N && bit == 0) {
    return 0;
  }
  if (dp[idx][pos].count(bit)) {
    return dp[idx][pos][bit];
  }
  int ret = INT_MAX;
  if (idx < N && sum(bit) - gett(bit, a[idx]) + 1 <= 4) {
    ret = min(ret,
              abs(a[idx] - pos) + gett(bit, a[idx]) + 1 +
                  solve(idx + 1, a[idx], addd(set0(bit, a[idx]), b[idx], 1)));
  }
  for (int i = pos - 1; i >= 0; i--) {
    if (gett(bit, i)) {
      ret = min(ret, abs(i - pos) + gett(bit, i) + solve(idx, i, set0(bit, i)));
      break;
    }
  }
  for (int i = pos + 1; i <= 8; i++) {
    if (gett(bit, i)) {
      ret = min(ret, abs(i - pos) + gett(bit, i) + solve(idx, i, set0(bit, i)));
      break;
    }
  }
  dp[idx][pos][bit] = ret;
  return ret;
}
void solve_all() { printf("%d\n", solve(0, 0, 0)); }
int main() {
  precomp();
  read();
  solve_all();
}

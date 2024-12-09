#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int N, M;
int gcd_map[4001][4001];
int fun(int N, int parity) {
  return (N > 0) ? ((N - parity) / 2 + 1) : (1 - parity);
}
int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }
int main() {
  cin >> N >> M;
  long long total = 0;
  for (int x = 0; x <= 1; x++)
    for (int y = 0; y <= 1; y++) {
      for (int x1 = 0; x1 <= 1; x1++) {
        for (int y1 = 0; y1 <= 1; y1++) {
          for (int x2 = 0; x2 <= 1; x2++) {
            for (int y2 = 0; y2 <= 1; y2++) {
              if (((x1 - x) * (y2 - y) - (x2 - x) * (y1 - y)) % 2 == 0) {
                total += (long long)fun(N, x) * fun(N, x1) * fun(N, x2) % MOD *
                         (long long)fun(M, y) * fun(M, y1) * fun(M, y2) % MOD;
              }
            }
          }
        }
      }
    }
  for (int sum = 0; sum <= N + M; sum++) {
    for (int dx = 0; dx <= N; dx++) {
      int dy = sum - dx;
      if (dy < 0 || dy > M) continue;
      if (dx == 0) {
        gcd_map[dx][dy] = dy;
      } else if (dy == 0) {
        gcd_map[dx][dy] = dx;
      } else if (dx < dy) {
        gcd_map[dx][dy] = gcd_map[dx][dy - dx];
      } else {
        gcd_map[dx][dy] = gcd_map[dx - dy][dy];
      }
    }
  }
  for (int dx = 0; dx <= N; dx++) {
    for (int dy = 0; dy <= M; dy++) {
      int d = gcd_map[dx][dy] + 1;
      long long count = (N - dx + 1) * (M - dy + 1);
      if (d == 1) {
        total -= count;
      } else if (d == 2) {
        count *= 6;
        if (dx > 0 && dy > 0) {
          count <<= 1;
        }
        total -= count;
      } else {
        total -= count * 6;
        total -= count * 6 * (d - 2);
        if (dx > 0 && dy > 0) {
          total -= count * 6;
          total -= count * 6 * (d - 2);
        }
      }
    }
    total %= MOD;
  }
  cout << (total % MOD + MOD) % MOD << endl;
  return 0;
}

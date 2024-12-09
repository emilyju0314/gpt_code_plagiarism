#include <bits/stdc++.h>
const long long T00B1G = 9223372036854775807LL;
const int maskl = 5;
bool mask[64][5];
template <class TEl>
using TTable = std::vector<std::vector<TEl>>;
template <class TEl>
void spacecreator(long long first, long long second, TTable<TEl>& vec) {
  vec.resize(first);
  for (auto& sub : vec) {
    sub.resize(second);
  }
}
template <class T>
void makemask(long nn, T& mask) {
  auto ulim = 1 << nn;
  for (auto st = 0; st < ulim; st++) {
    for (auto pos = 0; pos < nn; pos++) {
      mask[st][pos] = (st >> pos) & 1;
    }
  }
}
int main() {
  long mm, nn;
  TTable<long long> dp;
  TTable<long long> left, down;
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cin >> nn >> mm;
  spacecreator(mm + 5, 2 * (1 << nn), dp);
  spacecreator(maskl, mm + 5, left);
  spacecreator(maskl, mm + 5, down);
  for (auto col = 1; col < mm; col++) {
    for (auto row = 0; row < nn; row++) {
      std::cin >> left[row][col];
    }
  }
  for (auto col = 0; col < mm; col++) {
    for (auto row = 0; row < nn; row++) {
      std::cin >> down[row][col];
    }
  }
  makemask(nn, mask);
  long long fix, tran;
  auto ulim = 1 << nn;
  for (auto col = 1; col < mm; col++) {
    for (auto st = 0; st < ulim; st++) {
      fix = 0;
      dp[col][st] = T00B1G;
      for (auto row = 0; row < nn; row++) {
        auto next = row + 1;
        if (next >= nn) {
          next = 0;
        }
        if (mask[st][row] ^ mask[st][next]) {
          fix += down[row][col];
        }
      }
      for (auto prev = 0; prev < ulim; prev++) {
        if (col == 1 && prev != 0) {
          break;
        }
        tran = 0;
        for (auto row = 0; row < nn; row++) {
          if ((mask[st][row] ^ mask[prev][row]) == 1) {
            tran += left[row][col];
          }
        }
        dp[col][st] = std::min(dp[col][st], dp[col - 1][prev] + tran + fix);
      }
    }
  }
  std::cout << dp[mm - 1][ulim - 1];
  return 0;
}

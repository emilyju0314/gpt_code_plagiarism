#include <bits/stdc++.h>
using namespace std;
const int MaxP = 17;
int n, p;
string s;
bool a[MaxP][MaxP], bad[1 << MaxP], tmp_bad[1 << MaxP], possible[1 << MaxP];
int len[1 << MaxP];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> p >> s;
  for (int i = 0; i < p; i++)
    for (int j = 0; j < p; j++) cin >> a[i][j];
  for (int i = 0; i < p; i++)
    for (int j = i; j < p; j++) {
      if (a[i][j]) continue;
      for (int mask = 0; mask < (1 << p); mask++) tmp_bad[mask] = false;
      int cur_mask = (1 << p) - 1;
      char last = 0;
      for (char c : s) {
        if (c == 'a' + i || c == 'a' + j) {
          if (last != 0 && (i == j || last != c)) tmp_bad[cur_mask] = true;
          cur_mask = (1 << p) - 1;
          last = c;
        } else
          cur_mask &= ((1 << p) - 1) ^ (1 << (c - 'a'));
      }
      for (int mask = (1 << p) - 1; mask >= 0; mask--) {
        if (!tmp_bad[mask]) continue;
        bad[mask] = true;
        for (int k = 0; k < p; k++)
          if (k != i && k != j && (mask & (1 << k)))
            tmp_bad[mask ^ (1 << k)] = true;
      }
    }
  int total_mask = 0;
  for (char c : s) {
    total_mask |= 1 << (c - 'a');
    len[1 << (c - 'a')]++;
  }
  possible[total_mask] = true;
  for (int mask = 1; mask < (1 << p); mask++) {
    int submask = (mask - 1) & mask;
    len[mask] = len[submask] + len[mask ^ submask];
  }
  int sol = n;
  for (int mask = (1 << p) - 2; mask >= 0; mask--) {
    if (bad[mask]) continue;
    for (int i = 0; i < p; i++)
      possible[mask] |= !(mask & (1 << i)) && possible[mask | (1 << i)];
    if (possible[mask]) sol = min(sol, len[mask]);
  }
  cout << sol;
  return 0;
}

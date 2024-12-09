#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
int n, k, a[3333];
int res;
bool mem[3333][3333];
void rec(int pos2, int pos1, int r, vector<int> cnt) {
  mem[pos2][pos1 + 1] = true;
  res++;
  int left = max(0, k - r);
  if (pos2 == n) return;
  if (pos1 == -1) {
    res--;
    {
      cnt[a[pos2]]--;
      if (mem[pos2 + 1][pos2 + 1] == false) rec(pos2 + 1, pos2, r, cnt);
      cnt[a[pos2]]++;
    }
  } else if (left > 0) {
    if (a[pos1] != 0 and (cnt[1] > 0 or (cnt[2] > 0 and left > 0))) {
      {
        cnt[a[pos2]]--;
        if (mem[pos2 + 1][-1 + 1] == false) rec(pos2 + 1, -1, r + 1, cnt);
        cnt[a[pos2]]++;
      }
    }
    if (a[pos1] != 2 and (cnt[1] > 0 or (cnt[2] > 0 and left > 0))) {
      if (mem[pos2][-1 + 1] == false) rec(pos2, -1, r + 1, cnt);
    }
    if (a[pos1] != 0 and (cnt[2] == 0 or (cnt[2] > 0 and left == 0))) {
      {
        cnt[a[pos2]]--;
        if (mem[pos2 + 1][pos1 + 1] == false) rec(pos2 + 1, pos1, r + 1, cnt);
        cnt[a[pos2]]++;
      }
    }
  }
}
int solve() {
  memset(mem, 0, sizeof(mem));
  vector<int> cnt(3, 0);
  for (int i = (0); i < (n); i++) cnt[a[i]]++;
  res = 0;
  rec(0, -1, 0, cnt);
  return res;
}
int main() {
  while (cin >> n >> k) {
    for (int i = (0); i < (n); i++) {
      int p;
      cin >> p;
      if (p == 0)
        a[i] = 0;
      else if (p == 100)
        a[i] = 2;
      else
        a[i] = 1;
    }
    cout << solve() << endl;
  }
}

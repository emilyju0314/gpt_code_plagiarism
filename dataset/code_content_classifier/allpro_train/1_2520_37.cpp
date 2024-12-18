#include <bits/stdc++.h>
using namespace std;
const int K = 3;
struct Guy {
  int walk;
  int thr;
  int pos;
  int holds;
  int held;
  bool done[3];
};
int ans;
Guy best[3 * K + 1][K];
int GetPossibleMoves(Guy *guys, int *arr, int i, int m) {
  int mdist = 1;
  if (m == 0) mdist = guys[i].walk;
  if (m == 2) mdist = guys[i].thr;
  int res = 0;
  for (int t = 0; t < K; t++) {
    if (m == 1) {
      if (abs(guys[t].pos - guys[i].pos) == 1 && guys[t].held < 0)
        arr[res++] = guys[t].pos;
    } else {
      for (int d = -1; d <= 1; d += 2) {
        int tpos = guys[t].pos + d;
        if (abs(tpos - guys[i].pos) <= mdist) arr[res++] = tpos;
      }
    }
  }
  if (m != 1) {
    arr[res++] = guys[i].pos + mdist;
    sort(arr, arr + res);
    res = unique(arr, arr + res) - arr;
    int rr = 0;
    for (int i = 0; i < res; i++) {
      bool ok = true;
      for (int u = 0; u < K; u++)
        if (guys[u].pos == arr[i] && guys[u].held < 0) {
          ok = false;
          break;
        }
      if (ok) arr[rr++] = arr[i];
    }
    res = rr;
  }
  return res;
}
Guy state[K * 3 + 1][K];
void Solve(int u) {
  Guy *guys = state[u];
  int maxp = 0;
  for (int i = 0; i < K; i++)
    if (guys[i].held < 0 && guys[i].pos > maxp) maxp = guys[i].pos;
  if (maxp > ans) {
    memcpy(best, state, sizeof(best));
    ans = maxp;
  }
  ((void)0);
  for (int i = 0; i < K; i++) ((void)0);
  if (u == K * 3) return;
  for (int i = 0; i < K; i++) {
    if (guys[i].held >= 0) continue;
    for (int j = 0; j < 3; j++)
      if (!guys[i].done[j]) {
        if ((j == 0) && (guys[i].holds >= 0)) continue;
        if ((j == 2) && (guys[i].holds < 0)) continue;
        if ((j == 1) && (guys[i].holds >= 0)) continue;
        int pos[16];
        int pk = GetPossibleMoves(guys, pos, i, j);
        for (int q = 0; q < pk; q++) {
          Guy *nguys = state[u + 1];
          memcpy(nguys, guys, sizeof(state[0]));
          nguys[i].done[j] = true;
          if (j == 0) nguys[i].pos = pos[q];
          if (j == 1) {
            int w = 0;
            for (w = 0; w < K; w++)
              if (nguys[w].held < 0 && nguys[w].pos == pos[q]) break;
            assert(w < K);
            nguys[i].holds = w;
            nguys[w].held = i;
          }
          if (j == 2) {
            int w = nguys[i].holds;
            nguys[w].pos = pos[q];
            nguys[i].holds = -1;
            nguys[w].held = -1;
          }
          Solve(u + 1);
        }
      }
  }
}
int main() {
  Guy *guys = state[0];
  for (int i = 0; i < K; i++) {
    scanf("%d%d%d", &guys[i].pos, &guys[i].walk, &guys[i].thr);
    guys[i].holds = -1;
    guys[i].held = -1;
  }
  Solve(0);
  printf("%d\n", ans);
  ((void)0);
  for (int u = 0; u <= 3 * K; u++) {
    Guy *guys = best[u];
    for (int i = 0; i < K; i++) ((void)0);
    ((void)0);
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 5;
const int MOD = 998244353;
void inc(int &a, int b) {
  if ((a += b) >= MOD) a -= MOD;
}
int n, boxsz;
int dx[MAXN], dy[MAXN];
int xpos[MAXN], xneg[MAXN], ypos[MAXN], yneg[MAXN];
int sumxpos, sumxneg, sumypos, sumyneg;
int nstate;
vector<int> ways, nways;
int encode(int xposcarry, int xnegcarry, int yposcarry, int ynegcarry,
           int xposgreater, int yposgreater) {
  assert(xposcarry >= 0 && (xposcarry == 0 || xposcarry < sumxpos));
  assert(xnegcarry >= 0 && (xnegcarry == 0 || xnegcarry < sumxneg));
  assert(yposcarry >= 0 && (yposcarry == 0 || yposcarry < sumypos));
  assert(ynegcarry >= 0 && (ynegcarry == 0 || ynegcarry < sumyneg));
  int ret = 0;
  if (sumxpos > 0) ret = ret * sumxpos + xposcarry;
  if (sumxneg > 0) ret = ret * sumxneg + xnegcarry;
  if (sumypos > 0) ret = ret * sumypos + yposcarry;
  if (sumyneg > 0) ret = ret * sumyneg + ynegcarry;
  ret = ret * 2 + xposgreater;
  ret = ret * 2 + yposgreater;
  return ret;
}
void decode(int key, int &xposcarry, int &xnegcarry, int &yposcarry,
            int &ynegcarry, int &xposgreater, int &yposgreater) {
  yposgreater = key % 2, key /= 2;
  xposgreater = key % 2, key /= 2;
  if (sumyneg > 0)
    ynegcarry = key % sumyneg, key /= sumyneg;
  else
    ynegcarry = 0;
  if (sumypos > 0)
    yposcarry = key % sumypos, key /= sumypos;
  else
    yposcarry = 0;
  if (sumxneg > 0)
    xnegcarry = key % sumxneg, key /= sumxneg;
  else
    xnegcarry = 0;
  if (sumxpos > 0)
    xposcarry = key % sumxpos, key /= sumxpos;
  else
    xposcarry = 0;
  assert(key == 0);
}
int solve() {
  for (int i = (0); i < (n); ++i) xpos[i] = dx[i] > 0 ? +dx[i] : 0;
  for (int i = (0); i < (n); ++i) xneg[i] = dx[i] < 0 ? -dx[i] : 0;
  for (int i = (0); i < (n); ++i) ypos[i] = dy[i] > 0 ? +dy[i] : 0;
  for (int i = (0); i < (n); ++i) yneg[i] = dy[i] < 0 ? -dy[i] : 0;
  sumxpos = 0;
  for (int i = (0); i < (n); ++i) sumxpos += xpos[i];
  sumxneg = 0;
  for (int i = (0); i < (n); ++i) sumxneg += xneg[i];
  sumypos = 0;
  for (int i = (0); i < (n); ++i) sumypos += ypos[i];
  sumyneg = 0;
  for (int i = (0); i < (n); ++i) sumyneg += yneg[i];
  nstate = (sumxpos == 0 ? 1 : sumxpos) * (sumxneg == 0 ? 1 : sumxneg) *
           (sumypos == 0 ? 1 : sumypos) * (sumyneg == 0 ? 1 : sumyneg) * 2 * 2;
  ways = nways = vector<int>(nstate, 0);
  inc(ways[encode(0, 0, 0, 0, 0, 0)], 1);
  for (int bit = 0; (1 << bit) <= boxsz; ++bit) {
    int boxszbit = (boxsz >> bit) & 1;
    for (int key = (0); key < (nstate); ++key) nways[key] = 0;
    for (int key = (0); key < (nstate); ++key)
      if (ways[key] > 0) {
        int xposcarry, xnegcarry, yposcarry, ynegcarry, xposgreater,
            yposgreater;
        decode(key, xposcarry, xnegcarry, yposcarry, ynegcarry, xposgreater,
               yposgreater);
        for (int mask = (0); mask < (1 << n); ++mask) {
          int xposval = xposcarry, xnegval = xnegcarry, yposval = yposcarry,
              ynegval = ynegcarry;
          for (int i = (0); i < (n); ++i)
            if (mask & (1 << i)) {
              xposval += xpos[i];
              xnegval += xneg[i];
              yposval += ypos[i];
              ynegval += yneg[i];
            }
          if (xposval % 2 != xnegval % 2) continue;
          if (yposval % 2 != ynegval % 2) continue;
          int nxposcarry = xposval / 2, nxnegcarry = xnegval / 2,
              nyposcarry = yposval / 2, nynegcarry = ynegval / 2;
          int xbit = xposval % 2,
              nxposgreater =
                  xbit > boxszbit || xbit == boxszbit && xposgreater == 1 ? 1
                                                                          : 0;
          int ybit = yposval % 2,
              nyposgreater =
                  ybit > boxszbit || ybit == boxszbit && yposgreater == 1 ? 1
                                                                          : 0;
          inc(nways[encode(nxposcarry, nxnegcarry, nyposcarry, nynegcarry,
                           nxposgreater, nyposgreater)],
              ways[key]);
        }
      }
    swap(ways, nways);
  }
  int ret = ways[encode(0, 0, 0, 0, 0, 0)];
  inc(ret, MOD - 1);
  return ret;
}
void run() {
  scanf("%d%d", &n, &boxsz);
  for (int i = (0); i < (n); ++i) scanf("%d%d", &dx[i], &dy[i]);
  printf("%d\n", solve());
}
int main() {
  run();
  return 0;
}

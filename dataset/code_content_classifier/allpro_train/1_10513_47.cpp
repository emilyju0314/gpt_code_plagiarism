#include <bits/stdc++.h>
using namespace std;
long long rdtsc() {
  long long tmp;
  asm("rdtsc" : "=A"(tmp));
  return tmp;
}
inline int myrand() { return abs((rand() << 15) ^ rand()); }
inline int rnd(int x) { return myrand() % x; }
const int maxn = (int)1e5;
char s[maxn + 1];
long long hs[maxn + 1];
const long long Q = 239017;
long long qs[maxn + 1];
const int maxc = 26;
int colors[maxc][maxn + 1];
void precalc(int n) {
  hs[0] = 0;
  for (int i = 0; i < n; ++i) {
    hs[i + 1] = hs[i];
    hs[i + 1] *= Q;
    hs[i + 1] += (int)s[i];
  }
  qs[0] = 1;
  for (int i = 1; i <= n; ++i) qs[i] = qs[i - 1], qs[i] *= Q;
  for (int color = 0; color < maxc; ++color) {
    colors[color][0] = 0;
    for (int i = 0; i < n; ++i)
      colors[color][i + 1] = colors[color][i] + (s[i] == color + 'a');
  }
}
inline long long getHash(int pos, int len) {
  long long tmp = hs[pos];
  tmp *= qs[len];
  long long res = hs[pos + len];
  res -= tmp;
  return res;
}
const int maxl = 17;
inline int commonLen(int left, int right, int n) {
  assert(left < right);
  int ans = 0;
  for (int it = maxl - 1; it >= 0; --it) {
    if (right + ans + (1 << it) <= n &&
        getHash(left, ans + (1 << it)) == getHash(right, ans + (1 << it)))
      ans += (1 << it);
  }
  return ans;
}
int gray[maxl][maxn];
int grayLen[maxl];
long long wholeTaken[maxn + 1];
long long getInitial(int n) {
  for (int i = 0; i <= n; ++i) wholeTaken[i] = 0;
  long long res = 0;
  for (int len = 0; len < maxl; ++len) {
    grayLen[len] = (1 << (len + 1)) - 1;
    int n0 = n - grayLen[len] + 1;
    for (int i = 0; i < n0; ++i) {
      int &current = gray[len][i];
      current = 0;
      if (!len) {
        current = 1;
        continue;
      }
      int half = i + grayLen[len - 1];
      int *countMidColor = colors[s[half] - 'a'];
      if (gray[len - 1][i] &&
          countMidColor[i + grayLen[len]] - countMidColor[i] == 1 &&
          getHash(i, grayLen[len - 1]) == getHash(half + 1, grayLen[len - 1]))
        current = 1;
    }
    long long sqrLen = (long long)grayLen[len] * grayLen[len];
    for (int i = 0; i < n0; ++i) {
      if (!gray[len][i]) continue;
      wholeTaken[i] += sqrLen;
      wholeTaken[i + grayLen[len]] -= sqrLen;
      res += sqrLen;
    }
  }
  for (int i = 1; i <= n; ++i) wholeTaken[i] += wholeTaken[i - 1];
  return res;
}
long long changes[maxc][maxn];
void findChanges(int n) {
  for (int i = 0; i < maxc; ++i)
    for (int j = 0; j < n; ++j) changes[i][j] = 0;
  for (int len = 0; len < maxl; ++len) {
    int n0 = n - grayLen[len] + 1;
    for (int i = 0; i < n0; ++i) {
      if (!len) {
        for (int c = 0; c < maxc; ++c)
          if (c + 'a' != s[i]) changes[c][i] += 1;
        continue;
      }
      int half = i + grayLen[len - 1];
      if (!gray[len - 1][i] && !gray[len - 1][half + 1]) continue;
      long long sqrLen = (long long)grayLen[len] * grayLen[len];
      if (gray[len - 1][i] &&
          getHash(i, grayLen[len - 1]) == getHash(half + 1, grayLen[len - 1])) {
        for (int c = 0; c < maxc; ++c) {
          int *countMidColor = colors[c];
          if (countMidColor[i + grayLen[len]] - countMidColor[i] == 0) {
            changes[c][half] += sqrLen;
          }
        }
      }
      int *countMidColor = colors[s[half] - 'a'];
      int firstLen = commonLen(i, half + 1, n);
      if (firstLen >= grayLen[len - 1]) continue;
      int left = i + firstLen, right = left + grayLen[len - 1] + 1;
      int secondLen = commonLen(left + 1, right + 1, n);
      if (firstLen + 1 + secondLen < grayLen[len - 1]) continue;
      if (gray[len - 1][half + 1] &&
          countMidColor[half + 1 + grayLen[len - 1]] -
                  countMidColor[half + 1] ==
              0)
        changes[s[right] - 'a'][left] += sqrLen;
      if (gray[len - 1][i] && countMidColor[half] - countMidColor[i] == 0)
        changes[s[left] - 'a'][right] += sqrLen;
    }
  }
}
bool solve() {
  if (scanf("%s", s) < 1) return 0;
  int n = strlen(s);
  precalc(n);
  long long ans = getInitial(n);
  findChanges(n);
  long long maxAdd = 0;
  for (int i = 0; i < maxc; ++i)
    for (int j = 0; j < n; ++j)
      maxAdd = max(maxAdd, -wholeTaken[j] + changes[i][j]);
  printf(
      "%lld"
      "\n",
      ans + maxAdd);
  return 1;
}
int main() {
  srand(rdtsc());
  while (1) {
    if (!solve()) break;
  }
  return 0;
}

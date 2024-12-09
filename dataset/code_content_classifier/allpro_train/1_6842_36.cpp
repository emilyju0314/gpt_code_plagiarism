#include <bits/stdc++.h>
using namespace std;
inline int setBit(int N, int pos) { return N = N | (1 << pos); }
inline int resetBit(int N, int pos) { return N = N & ~(1 << pos); }
inline bool checkBit(int N, int pos) { return (bool)(N & (1 << pos)); }
const int MAX = 100005;
int n, m, arr[12][MAX], where[12][MAX];
struct simplehash {
  int len;
  long long base, mod;
  vector<int> P, H;
  simplehash() {}
  simplehash(int* str, long long b, long long m) {
    base = b, mod = m, len = n;
    P.resize(len + 3, 1), H.resize(len + 3, 0);
    for (int i = 1; i <= len; i++) P[i] = (P[i - 1] * base) % mod;
    for (int i = 1; i <= len; i++)
      H[i] = (H[i - 1] * base + str[i - 1] + 1007) % mod;
  }
  inline int range_hash(int l, int r) {
    int hashval = H[r + 1] - ((long long)P[r - l + 1] * H[l] % mod);
    return (hashval < 0 ? hashval + mod : hashval);
  }
};
struct stringhash {
  simplehash sh1, sh2;
  stringhash() {}
  stringhash(int* str) {
    sh1 = simplehash(str, 1949313259, 2091573227);
    sh2 = simplehash(str, 1997293877, 2117566807);
  }
  inline long long range_hash(int l, int r) {
    return ((long long)sh1.range_hash(l, r) << 32) ^ sh2.range_hash(l, r);
  }
} hList[12];
inline bool check(int l, int r) {
  if (l == r) return true;
  long long hhh = hList[0].range_hash(l, r);
  for (int i = 1; i < m; i++) {
    int fuck = where[i][arr[0][l]];
    if (fuck + r - l >= n) return false;
    if (hList[i].range_hash(fuck, fuck + r - l) != hhh) return false;
  }
  return true;
}
inline int bs(int st) {
  int low = st, mid, high = n - 1, ret = low;
  while (low <= high) {
    mid = (low + high) >> 1;
    if (check(st, mid)) {
      ret = max(ret, mid);
      low = mid + 1;
    } else
      high = mid - 1;
  }
  return ret;
}
long long solve() {
  long long ret = 0;
  for (int i = 0; i < n;) {
    int idx = bs(i);
    long long length = idx - i + 1;
    ret += (length * (length + 1)) / 2;
    i = idx + 1;
  }
  return ret;
}
int main() {
  int i, j;
  scanf("%d %d", &n, &m);
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &arr[i][j]);
      where[i][arr[i][j]] = j;
    }
    hList[i] = stringhash(arr[i]);
  }
  printf("%lld\n", solve());
  return 0;
}

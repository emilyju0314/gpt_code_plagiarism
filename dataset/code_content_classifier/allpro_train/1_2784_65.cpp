#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3", "omit-frame-pointer", "inline")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native,avx2")
using namespace std;
const long long mod = 1000000007;
mt19937 rng((int)chrono::steady_clock::now().time_since_epoch().count());
const long long mxN = 300010;
int N;
int mn[mxN];
int mx[mxN];
int lst[mxN];
int BITa[mxN];
int BITi[mxN];
void upd(int BIT[], int ind, int val) {
  while (ind < mxN) {
    BIT[ind] += val;
    ind |= ind + 1;
  }
}
int get(int BIT[], int ind) {
  long long res = 0;
  while (ind >= 0) {
    res += BIT[ind];
    ind = (ind & (ind + 1)) - 1;
  }
  return res;
}
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  while (t--) {
    int M, a;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
      mn[i] = mx[i] = i;
    }
    for (int i = 0; i < M; i++) {
      cin >> a;
      mn[a] = 1;
      if (!lst[a]) {
        mx[a] = max(mx[a], a + get(BITa, N) - get(BITa, a));
        upd(BITa, a, 1);
      } else {
        mx[a] = max(mx[a], get(BITi, M + 1) - get(BITi, lst[a]) + 1);
        upd(BITi, lst[a], -1);
      }
      upd(BITi, i + 1, 1);
      lst[a] = i + 1;
    }
    for (int i = 1; i <= N; i++) {
      if (!lst[i]) {
        mx[i] = max(mx[i], i + get(BITa, N) - get(BITa, i));
      } else {
        mx[i] = max(mx[i], get(BITi, M + 1) - get(BITi, lst[i]) + 1);
      }
    }
    for (int i = 1; i <= N; i++) {
      cout << mn[i] << ' ' << mx[i] << '\n';
    }
  }
  return 0;
}

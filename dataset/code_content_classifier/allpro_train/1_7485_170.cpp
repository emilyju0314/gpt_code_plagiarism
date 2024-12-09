#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 7;
const int INF = 1e9 + 7;
int n, a[N], Q, R[N], M, best, pos, res;
long long s[N];
void Enter() {
  cin >> n >> Q;
  for (int i = (1), _b = (n); i <= _b; ++i) {
    cin >> a[i];
    a[i + n] = a[i];
    a[i + n + n] = a[i];
  }
  for (int i = (1), _b = (3 * n); i <= _b; ++i) s[i] = s[i - 1] + a[i];
}
inline long long get(int l, int r) { return s[r] - s[l - 1]; }
void FindRight() {
  int j = 1;
  best = INF;
  for (int i = (1), _b = (2 * n); i <= _b; ++i) {
    while (j < i + n - 1 && get(i, j + 1) <= M) ++j;
    R[i] = j;
    if (i <= n && R[i] - i < best) {
      best = R[i] - i;
      pos = i;
    }
  }
}
void Process() {
  for (int iQ = (1), _b = (Q); iQ <= _b; ++iQ) {
    cin >> M;
    FindRight();
    res = INF;
    for (int z = (pos), _b = (R[pos] + 1); z <= _b; ++z) {
      int cur = z, cnt = 0;
      while (cur <= z + n - 1) {
        cur = R[cur] + 1;
        ++cnt;
      }
      res = min(res, cnt);
    }
    cout << res << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  Enter();
  Process();
  return 0;
}

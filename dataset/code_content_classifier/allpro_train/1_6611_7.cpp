#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
inline void amax(T &x, U y) {
  if (x < y) x = y;
}
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= 1000000007;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
  }
  return res;
}
long long tot[11] = {0};
long long ans = 0;
void find(long long st, long long rem, long long cur, long long val) {
  if (cur == 6) {
    ans += val;
    ans %= 1000000007;
    return;
  }
  for (int i = 0; i < rem + 1; i++) {
    long long tp = val * tot[i];
    tp %= 1000000007;
    tot[i]--;
    find(st, rem - i, cur + 1, tp);
    tot[i]++;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  long long cnt[12][12][2], m;
  cin >> m;
  vector<long long> v;
  long long t[] = {1, 2, 3, 4, 4, 5, 6, 6, 7, 8};
  long long t1[] = {0, 0, 0, 0, 1, 1, 1, 2, 2, 2};
  while (m > 0) {
    v.push_back(m % 10);
    m /= 10;
  }
  reverse(v.begin(), v.end());
  memset(cnt, 0, sizeof(cnt));
  cnt[0][0][1] = 1;
  for (int i = 1; i < ((v).size()) + 1; i++) {
    for (int l = 10 - 1; l >= 0; l--) {
      cnt[i][l][0] = cnt[i - 1][l][0] * 8 +
                     cnt[i - 1][l][1] * (v[i - 1] != 0 ? t[v[i - 1] - 1] : 0);
      if (l != 0)
        cnt[i][l][0] +=
            cnt[i - 1][l - 1][0] * 2 +
            cnt[i - 1][l - 1][1] * (v[i - 1] != 0 ? t1[v[i - 1] - 1] : 0);
      if (v[i - 1] == 4 || v[i - 1] == 7) {
        if (l == 0) continue;
        cnt[i][l][1] = cnt[i - 1][l - 1][1];
      } else
        cnt[i][l][1] = cnt[i - 1][l][1];
    }
  }
  for (int i = 0; i < 10; i++)
    tot[i] = cnt[((v).size())][i][0] + cnt[((v).size())][i][1];
  tot[0]--;
  for (int i = 1; i < ((v).size()) + 1; i++) find(i, i - 1, 0, tot[i]);
  cout << ans, cout << endl;
  return 0;
}

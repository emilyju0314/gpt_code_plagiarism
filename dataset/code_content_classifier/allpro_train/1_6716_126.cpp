#include <bits/stdc++.h>
using namespace std;
struct __s {
  __s() {
    srand(time(NULL));
    if (1) {
      ios_base::Init i;
      cin.sync_with_stdio(0);
      cin.tie(0);
    }
  }
  ~__s() {
    if (!1)
      fprintf(stderr, "Execution time: %.3lf s.\n",
              (double)clock() / CLOCKS_PER_SEC);
    int n;
    cin >> n;
  }
} __S;
int L, n, p, t;
int l[111111];
int r[111111];
int dp[100000][500];
int maxDp[111111];
int get(int l, int r) {
  int d = r - l;
  return d / p;
}
int findPos(int x, set<pair<pair<int, int>, int> > &s) {
  pair<pair<int, int>, int> p = make_pair(make_pair(x, 1e9 + 1), n);
  s.insert(p);
  set<pair<pair<int, int>, int> >::iterator i = s.find(p);
  int idx = -1;
  if (i != s.begin()) {
    i--;
    idx = (i->second);
  }
  s.erase(p);
  return idx;
}
int solve1() {
  set<pair<pair<int, int>, int> > s;
  for (int i = 0; i < (int)(n); i++) {
    int cnt = get(l[i], r[i]);
    int pos = r[i] - p * cnt - t;
    int j = findPos(pos, s);
    for (int k = 0; k < p; k++) {
      int R = r[i] - k;
      int cnt = get(l[i], R);
      dp[i][k] = cnt;
      int pos = R - p * cnt - t;
      if (j != -1 && pos < l[j]) j--;
      int res = 0;
      if (j != -1) {
        if (pos >= r[j])
          res = dp[j][0];
        else {
          int k = (r[j] - pos) % p;
          res = dp[j][k];
          res -= get(l[j], r[j] - k);
          res += get(l[j], pos);
        }
        if (j) res = max(res, maxDp[j - 1]);
      }
      dp[i][k] += res;
      maxDp[i] = max(maxDp[i], dp[i][k]);
      if (i) maxDp[i] = max(maxDp[i], maxDp[i - 1]);
    }
    s.insert(make_pair(make_pair(l[i], r[i]), i));
  }
  return maxDp[n - 1];
}
int solve2() {
  queue<pair<int, int> > q;
  int ans = 0;
  int CNT = 0;
  for (int i = 0; i < (int)(n); i++) {
    int cnt = CNT;
    for (int j = l[i];
         j + p <= r[i] || (q.size() && q.front().first + p <= r[i]); j += p) {
      while (q.size() && j >= q.front().first) {
        if (cnt <= q.front().second) {
          j = max(l[i], q.front().first);
          cnt = q.front().second;
        }
        CNT = max(CNT, q.front().second);
        q.pop();
      }
      if (j + p > r[i]) break;
      cnt++;
      q.push(make_pair((j + p + t), cnt));
      ans = max(ans, cnt);
    }
  }
  return ans;
}
int main(void) {
  cin >> L >> n >> p >> t;
  for (int i = 0; i < (int)(n); i++) {
    cin >> l[i] >> r[i];
  }
  if (p <= 120)
    cout << solve1() << '\n';
  else
    cout << solve2() << '\n';
  return 0;
}

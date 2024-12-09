#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
long long n, m, k, q;
pair<long long, long long> ara[N];
vector<long long> gem[N], bar;
long long dp[N][2];
long long ans = 0;
long long H;
set<long long> X;
map<long long, long long> mp;
long long id;
void mapping() {
  for (long long i = 0; i <= k; i++) {
    X.insert(ara[i].first);
  }
  for (long long i : X) {
    mp[i] = ++id;
    H = max(H, i);
  }
  for (long long i = 0; i <= k; i++) {
    long long row = mp[ara[i].first];
    gem[row].push_back(ara[i].second);
  }
  for (long long i = 1; i <= id; i++) sort(gem[i].begin(), gem[i].end());
}
long long funcL(long long x, long long index) {
  long long cnt = 0;
  if (gem[index].back() >= x) {
    cnt = ((x - gem[index].back()) < 0 ? -(x - gem[index].back())
                                       : (x - gem[index].back())) *
              2 +
          ((gem[index].front() - x) < 0 ? -(gem[index].front() - x)
                                        : (gem[index].front() - x));
  } else {
    cnt = ((gem[index].front() - x) < 0 ? -(gem[index].front() - x)
                                        : (gem[index].front() - x));
  }
  return cnt;
}
long long calcL(long long y, long long index) {
  long long cnt = 1e9;
  auto rt = lower_bound(bar.begin(), bar.end(), y);
  if (rt != bar.end()) {
    cnt =
        min(cnt, ((*rt - y) < 0 ? -(*rt - y) : (*rt - y)) + funcL(*rt, index));
  }
  if (rt != bar.begin()) {
    rt--;
    cnt =
        min(cnt, ((*rt - y) < 0 ? -(*rt - y) : (*rt - y)) + funcL(*rt, index));
  }
  return cnt;
}
long long funcR(long long x, long long index) {
  long long cnt = 0;
  if (gem[index].front() < x) {
    cnt = ((x - gem[index].front()) < 0 ? -(x - gem[index].front())
                                        : (x - gem[index].front())) *
              2 +
          ((gem[index].back() - x) < 0 ? -(gem[index].back() - x)
                                       : (gem[index].back() - x));
  } else {
    cnt = ((gem[index].back() - x) < 0 ? -(gem[index].back() - x)
                                       : (gem[index].back() - x));
  }
  return cnt;
}
long long calcR(long long y, long long index) {
  long long cnt = 1e9;
  auto rt = lower_bound(bar.begin(), bar.end(), y);
  if (rt != bar.end()) {
    cnt =
        min(cnt, ((*rt - y) < 0 ? -(*rt - y) : (*rt - y)) + funcR(*rt, index));
  }
  if (rt != bar.begin()) {
    rt--;
    cnt =
        min(cnt, ((*rt - y) < 0 ? -(*rt - y) : (*rt - y)) + funcR(*rt, index));
  }
  return cnt;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cin >> n >> m >> k >> q;
  ara[0] = make_pair(1, 1);
  for (long long i = 1; i <= k; i++) {
    cin >> ara[i].first >> ara[i].second;
  }
  for (long long i = 1; i <= q; i++) {
    long long c;
    cin >> c;
    bar.push_back(c);
  }
  sort(bar.begin(), bar.end());
  mapping();
  ans += H - 1;
  dp[1][0] = (gem[1].back() - 1) * 2;
  dp[1][1] = (gem[1].back() - 1);
  for (long long i = 2; i <= id; i++) {
    long long cnt = 1e9;
    long long y1 = gem[i - 1].front();
    long long y2 = gem[i - 1].back();
    dp[i][0] = min(dp[i - 1][0] + calcL(y1, i), dp[i - 1][1] + calcL(y2, i));
    dp[i][1] = min(dp[i - 1][0] + calcR(y1, i), dp[i - 1][1] + calcR(y2, i));
  }
  cout << ans + min(dp[id][0], dp[id][1]);
}

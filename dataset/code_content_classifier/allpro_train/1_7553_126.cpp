#include <bits/stdc++.h>
using namespace std;
double start_moment = 0;
double get_runtime() { return 1.0 * clock() / CLOCKS_PER_SEC; }
void reset_timer() { start_moment = get_runtime(); }
double timer_time() { return get_runtime() - start_moment; }
void runtime() { cout << fixed << setprecision(5) << get_runtime() << '\n'; }
template <class T>
void read(vector<T> &a, long long n) {
  T x;
  a.clear();
  for (long long i = 0; i < n; i++) {
    cin >> x;
    a.push_back(x);
  }
}
template <class T>
void write(vector<T> &a) {
  for (T x : a) cout << x << ' ';
  cout << '\n';
}
const long long INF = 1LL * 1001 * 1001 * 1001 * 1001 * 1001 * 1001;
const long long mod = 998244353;
const int N = 200005;
long long bpow(long long a, long long x) {
  if (!x) return 1;
  if (x & 1) return a * bpow(a, x - 1) % mod;
  long long b = bpow(a, x / 2);
  return b * b % mod;
}
int n, m;
vector<int> g[2][N];
long long dp[N][20];
pair<long long, long long> dist[N][2];
int main() {
  ios_base::sync_with_stdio(0);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 20; j++) {
      dp[i][j] = INF;
    }
    for (int j = 0; j < 2; j++) {
      dist[i][j] = {INF, INF};
    }
  }
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    g[0][a].push_back(b);
    g[1][b].push_back(a);
  }
  dp[1][0] = 0;
  priority_queue<vector<long long> > q;
  q.push({-dp[1][0], 1, 0});
  while (!q.empty()) {
    vector<long long> v = q.top();
    q.pop();
    long long len = -v[0];
    int u = (int)v[1];
    int step = (int)v[2];
    if (step == 19 || dp[u][step] < len) {
      continue;
    }
    for (int i = 0; i < g[step % 2][u].size(); i++) {
      int to = g[step % 2][u][i];
      if (dp[to][step] > dp[u][step] + 1) {
        dp[to][step] = dp[u][step] + 1;
        q.push({-dp[to][step], to, step});
      }
    }
    for (int i = 0; i < g[(step + 1) % 2][u].size(); i++) {
      int to = g[(step + 1) % 2][u][i];
      if (dp[to][step + 1] > dp[u][step] + 1 + (1 << step)) {
        dp[to][step + 1] = dp[u][step] + 1 + (1 << step);
        q.push({-dp[to][step + 1], to, step + 1});
      }
    }
  }
  long long ans = INF;
  for (int j = 0; j < 20; j++) {
    ans = min(ans, dp[n][j]);
  }
  if (ans != INF) {
    cout << ans << '\n';
    return 0;
  }
  priority_queue<pair<pair<long long, long long>, pair<long long, long long> > >
      qq;
  dist[1][0] = {0, 0};
  qq.push(make_pair(dist[1][0], make_pair(1, 0)));
  while (qq.size()) {
    pair<pair<long long, long long>, pair<long long, long long> > p = qq.top();
    qq.pop();
    int u = (int)p.second.first;
    int rev = (int)p.second.second;
    for (int i = 0; i < g[rev][u].size(); i++) {
      int to = g[rev][u][i];
      if (dist[to][rev] >
          make_pair(dist[u][rev].first, dist[u][rev].second + 1)) {
        dist[to][rev] = make_pair(dist[u][rev].first, dist[u][rev].second + 1);
        qq.push(
            make_pair(make_pair(-dist[to][rev].first, -dist[to][rev].second),
                      make_pair(to, rev)));
      }
    }
    if (dist[u][rev ^ 1] >
        make_pair(dist[u][rev].first + 1, dist[u][rev].second)) {
      dist[u][rev ^ 1] = make_pair(dist[u][rev].first + 1, dist[u][rev].second);
      qq.push(make_pair(
          make_pair(-dist[u][rev ^ 1].first, -dist[u][rev ^ 1].second),
          make_pair(u, rev ^ 1)));
    }
  }
  pair<long long, long long> p = min(dist[n][0], dist[n][1]);
  cout << (p.second + bpow(2, p.first) - 1 + mod) % mod << endl;
}

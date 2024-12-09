#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
void itval(istream_iterator<string> it) {}
template <typename T, typename... Args>
void itval(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  itval(++it, args...);
}
const long long int MOD = 1e9 + 7;
template <typename T>
inline void print(T x) {
  cout << x << "\n";
}
template <typename T>
inline void printvec(T x) {
  for (auto a : x) cout << a << ' ';
  cout << '\n';
}
struct custom {
  bool operator()(
      const pair<long long int, pair<long long int, long long int> > &p1,
      const pair<long long int, pair<long long int, long long int> > &p2)
      const {
    return p1.first < p2.first;
  }
};
long long int get_pow(long long int a, long long int b, long long int M = MOD) {
  long long int res = 1;
  while (b) {
    if (b & 1) res = (res * a) % M;
    a = (a * a) % M;
    b >>= 1;
  }
  return res;
}
const long long int N = 2e5 + 5, inf = 2e18;
int sparse_mat_max[N][22];
int log_value[N];
void compute_sparse() {
  log_value[1] = 0;
  for (int i = 2; i < N; i++) {
    log_value[i] = log_value[i / 2] + 1;
  }
  for (int j = 1; j < 22; j++) {
    for (long long int i = 0; i + (1ll << j) < N; i++) {
      sparse_mat_max[i][j] = max(sparse_mat_max[i][j - 1],
                                 sparse_mat_max[i + (1ll << (j - 1))][j - 1]);
    }
  }
}
inline int query(int L, int R) {
  int j = log_value[R - L + 1];
  return max(sparse_mat_max[L][j], sparse_mat_max[R - (1 << j) + 1][j]);
}
void solve() {
  int n, m;
  cin >> n >> m;
  if (m > n) {
    cout << -1;
    exit(0);
  }
  long long int x, y, k;
  cin >> x >> k >> y;
  vector<long long> a(n), b(m);
  for (long long int i = (long long int)0; i < (long long int)(n); i++) {
    cin >> a[i];
    sparse_mat_max[i][0] = a[i];
  }
  for (long long int i = (long long int)0; i < (long long int)(m); i++) {
    cin >> b[i];
  }
  compute_sparse();
  vector<long long> keep = {-1};
  int c = 0;
  for (long long int i = (long long int)0; i < (long long int)(n); i++) {
    if (c < m && a[i] == b[c]) {
      keep.push_back(i);
      c++;
    }
  }
  keep.push_back(n);
  if (c != m) {
    cout << -1;
    return;
  }
  long long int ans = 0, len = 0;
  for (long long int i = (long long int)1; i < (long long int)(keep.size());
       i++) {
    len = keep[i] - keep[i - 1] - 1;
    if (len > 0) {
      if (len < k) {
        int t = query(keep[i - 1] + 1, keep[i] - 1);
        int l = -1, r = -1;
        if (keep[i - 1] != -1) l = a[keep[i - 1]];
        if (keep[i] != n) r = a[keep[i]];
        if (l > t || r > t) {
          ans += (y * len);
        } else {
          cout << -1;
          return;
        }
      } else {
        if (k * y < x) {
          int t = query(keep[i - 1] + 1, keep[i] - 1);
          int l = -1, r = -1;
          if (keep[i - 1] != -1) l = a[keep[i - 1]];
          if (keep[i] != n) r = a[keep[i]];
          if (l > t || r > t) {
            ans += (y * len);
            continue;
          }
          long long int lef = len - k;
          ans += (x + lef * y);
          continue;
        }
        long long int md = len % k;
        ans += (x * (len / k) + y * md);
      }
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int test = 1;
  clock_t z = clock();
  for (long long int tes = (long long int)0; tes < (long long int)(test);
       tes++) {
    solve();
  }
  fprintf(stderr, "Total Time:%.4f\n", (double)(clock() - z) / CLOCKS_PER_SEC),
      fflush(stderr);
  return 0;
}

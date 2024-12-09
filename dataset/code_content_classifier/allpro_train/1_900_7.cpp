#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
string cts(char x) {
  string t(1, x);
  return t;
}
long long rand(long long a, long long b) { return a + rng() % (b - a + 1); }
const int MOD = 1e9 + 7;
template <typename T>
void chmax(T& a, T b) {
  a = max(a, b);
}
template <typename T>
void chmin(T& a, T b) {
  a = min(a, b);
}
struct ConvexHull {
  deque<pair<long long, long long> > dq;
  long long first(pair<long long, long long> line, long long x) {
    return line.first * x + line.second;
  }
  long long query(long long x) {
    while (dq.size() > 1) {
      if (first(dq[0], x) > first(dq[1], x)) {
        dq.pop_front();
      } else {
        break;
      }
    }
    return first(dq[0], x);
  }
  double intersect(long long m1, long long c1, long long m2, long long c2) {
    return (double)(c2 - c1) / (m1 - m2);
  }
  double intersect(pair<long long, long long> a, pair<long long, long long> b) {
    return intersect(a.first, a.second, b.first, b.second);
  }
  void insert(long long m, long long c) {
    pair<long long, long long> line = {m, c};
    while (dq.size() > 1) {
      int second = dq.size();
      if (intersect(dq[second - 1], line) <= intersect(dq[second - 2], line)) {
        dq.pop_back();
      } else {
        break;
      }
    }
    dq.push_back(line);
  }
} CH;
long long dp[(int)1e5 + 5], A[(int)1e5 + 5], B[(int)1e5 + 5];
int32_t __attribute__((optimize("Ofast"), target("arch=sandybridge"))) main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (long long i = 1; i <= (long long)n; ++i) cin >> A[i];
  for (long long i = 1; i <= (long long)n; ++i) cin >> B[i];
  CH.insert(B[1], 0);
  dp[1] = A[1];
  for (long long i = 2; i <= (long long)n; ++i) {
    dp[i] = CH.query(A[i]);
    CH.insert(B[i], dp[i]);
  }
  cout << dp[n];
}

#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
const long long LINF = 1e17;
const double pi = 3.1415926535897932;
const string endstr = "\n";
template <typename T>
T gcd(T a, T b) {
  return (a == 0) ? b : gcd(b % a, a);
}
template <typename T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
bool p_comp_fs(const pair<long long, long long> p1,
               const pair<long long, long long> p2) {
  return p1.first < p2.first;
};
bool p_comp_fg(const pair<long long, long long> p1,
               const pair<long long, long long> p2) {
  return p1.first > p2.first;
};
bool p_comp_ss(const pair<long long, long long> p1,
               const pair<long long, long long> p2) {
  return p1.second < p2.second;
};
bool p_comp_sg(const pair<long long, long long> p1,
               const pair<long long, long long> p2) {
  return p1.second > p2.second;
};
template <typename T>
vector<T> uniquen(vector<T> vec) {
  sort((vec).begin(), (vec).end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
  return vec;
}
inline long long popcnt(long long x) {
  return __builtin_popcountll((unsigned long long)x);
};
template <class T>
bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
bool check(long long x, long long s, vector<pair<long long, long long> > &P) {
  long long N = P.size();
  long long lcnt = 0, rcnt = 0, lsum = 0, rsum = 0;
  vector<pair<long long, long long> > midx;
  for (auto p : P) {
    if (p.second < x) {
      lcnt++;
      lsum += p.first;
    } else if (p.first > x) {
      rcnt++;
      rsum += p.first;
    } else {
      midx.push_back(p);
    }
  }
  if (lcnt > N / 2) return false;
  if (rcnt > N / 2) return true;
  long long sum = lsum + rsum;
  for (long long i = 0; i < N / 2 - lcnt; i++) sum += midx[i].first;
  long long rem = N - (lcnt + rcnt + (N / 2 - lcnt));
  sum += x * rem;
  return sum <= s;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long T;
  cin >> T;
  for (long long _ = 0; _ < T; _++) {
    long long N, S;
    cin >> N >> S;
    vector<pair<long long, long long> > PS(N);
    for (long long i = 0; i < N; i++) cin >> PS[i].first >> PS[i].second;
    sort((PS).begin(), (PS).end());
    long long ok = -1, ng = LINF;
    while (abs(ok - ng) > 1) {
      long long mid = (ok + ng) / 2;
      if (check(mid, S, PS))
        ok = mid;
      else
        ng = mid;
    }
    cout << ok << endstr;
  }
  return 0;
}

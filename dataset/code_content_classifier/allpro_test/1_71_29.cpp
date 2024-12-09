#include <bits/stdc++.h>
using namespace std;
struct point {
  long long x;
  long long y;
  long long i;
};
long long f(point a, point b) { return (a.x - b.x) * (a.y + b.y); }
long long f(point a, point b, point c) { return f(a, b) + f(b, c) + f(c, a); }
long double getdist(point a, point b) {
  long double dx = a.x - b.x;
  long double dy = a.y - b.y;
  return sqrt(dx * dx + dy * dy);
}
const long long N = (long long)2e5 + 7;
long long n, k;
point a[N];
void print(long double sol) {
  cout << fixed << setprecision(6) << sol << "\n";
  exit(0);
}
bool operator<(point a, point b) {
  if (a.x != b.x) return a.x < b.x;
  return a.y < b.y;
}
mt19937 rng((long long)(new char));
void upd(long double &sol, vector<long long> ord) {
  if (ord[0] != k) return;
  long double cur = 0;
  for (long long i = 1; i < (long long)ord.size(); i++) {
    cur += getdist(a[ord[i - 1]], a[ord[i]]);
  }
  sol = min(sol, cur);
}
long double getbrute() {
  vector<long long> ord(n);
  iota(ord.begin(), ord.end(), 1);
  long double sol = (long double)1e18;
  upd(sol, ord);
  while (next_permutation(ord.begin(), ord.end())) {
    upd(sol, ord);
  }
  return sol;
}
long double pref[N];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].y;
    a[i].i = i;
  }
  if (n == 3) {
    vector<long long> rem;
    for (long long i = 1; i <= n; i++) {
      if (k != i) {
        rem.push_back(i);
      }
    }
    assert((long long)rem.size() == 2);
    print(min(getdist(a[k], a[rem[0]]), getdist(a[k], a[rem[1]])) +
          getdist(a[rem[0]], a[rem[1]]));
  }
  point special;
  long long speciali;
  while (1) {
    long long i = rng() % n + 1;
    long long j = rng() % n + 1;
    while (i == j) {
      j = rng() % n + 1;
    }
    assert(1 <= min(i, j) && min(i, j) < max(i, j) && max(i, j) <= n);
    long long cnt = 0, bad = -1;
    for (long long k = 1; k <= n; k++) {
      bool ok = (f(a[i], a[j], a[k]) == 0);
      if (!ok) {
        bad = k;
      } else {
        cnt++;
      }
    }
    assert(cnt < n);
    if (cnt == n - 1) {
      special = a[bad];
      speciali = bad;
      break;
    }
  }
  bool caz = (k == speciali);
  vector<point> others;
  for (long long i = 1; i <= n; i++) {
    if (i != speciali) {
      others.push_back(a[i]);
    }
  }
  n = (long long)others.size();
  sort(others.begin(), others.end());
  long double sol = (long double)1e18;
  for (long long swp = 0; swp <= 1; swp++) {
    long long kinit = k;
    if (caz) {
      for (long long j = 1; j < (long long)others.size(); j++) {
        pref[j] = pref[j - 1] + getdist(others[j - 1], others[j]);
      }
      for (long long i = 0; i < (long long)others.size(); i++) {
        long double cur = getdist(special, others[i]);
        if (1 <= i) {
          cur += pref[i] - pref[0];
        }
        if (i != (long long)others.size() - 1) {
          cur += getdist(others[0], others[i + 1]);
          if (i + 2 <= (long long)others.size() - 1) {
            cur += pref[(long long)others.size() - 1] - pref[i + 1];
          }
        }
        sol = min(sol, cur);
      }
    } else {
      k = -1;
      for (long long i = 0; i < (long long)others.size(); i++) {
        if (others[i].i == kinit) {
          k = i;
          break;
        }
      }
      assert(k != -1);
      vector<point> path;
      for (long long j = k; j >= 0; j--) {
        path.push_back(others[j]);
      }
      for (long long j = k + 1; j < (long long)others.size(); j++) {
        path.push_back(others[j]);
      }
      long double total;
      {
        long double cur = 0;
        for (long long j = 1; j < (long long)path.size(); j++) {
          cur += getdist(path[j - 1], path[j]);
        }
        total = cur;
        cur += getdist(path.back(), special);
        sol = min(sol, cur);
      }
      {
        for (long long i = 0; i < (long long)path.size() - 1; i++) {
          long double cur = total - getdist(path[i], path[i + 1]);
          cur += getdist(path[i], special);
          cur += getdist(path[i + 1], special);
          sol = min(sol, cur);
        }
      }
    }
    k = kinit;
    reverse(others.begin(), others.end());
  }
  print(sol);
  return 0;
}

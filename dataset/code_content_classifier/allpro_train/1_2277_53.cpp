#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define mp make_pair
#define mt make_tuple
#define DESYNC                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
#define pb push_back
#define vi vector<int>
#define vii vector<ii>
#define all(x) x.begin(), x.end()
#define EPS 1e-9
#define INF 1e18
#define ROOT 1
#define curtime chrono::steady_clock::now().time_since_epoch().count
#define rep(i, beg, n, s) for (int i = beg; i < n; i += s)
using ll = long long;
using namespace std;
const double PI = acos(-1);
const int M = 1000000007;
// const int M = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int mod(int n, int m = M) {
  int ret = n % m;
  if (ret < 0) ret += m;
  return ret;
}

int exp(int n, int k, int m = M) {
  if (k == 0) return 1;
  if (k == 1) return n;
  int ax = exp(n, k / 2, m);
  ax = mod(ax * ax, m);
  if (k % 2) ax = mod(ax * n, m);
  return ax;
}

int gcd(int a, int b) {
  if (a == 0)
    return b;
  else
    return gcd(b % a, a);
}

/* LIBRARY INCLUDES */

/* END OF LIBRARY INCLUDES */

/*      TEMPLATE DEFINES      */
// #define FILE_INPUT
// #define PRINT_TEST_CASE
//#define MULTIPLE_TEST_CASE

/*      SOLUTION CODE      */

void solution(int testcase) {
#ifdef PRINT_TEST_CASE
  cout << "Case #" << testcase << ": ";
#endif
  // Code starts here
  int n;
  cin >> n;
  int v[n];
  bool side[n];
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    v[i]--;
    side[i] = false;
  }
  vector<vi> cycles;
  vector<bool> vis(n, false);
  for (int i = 0; i < n; i++) {
    if (vis[i]) continue;
    if (v[i] == i) continue;
    int cur = i;
    cycles.pb(vi());
    while (!vis[cur]) {
      cycles.back().pb(cur);
      vis[cur] = 1;
      cur = v[cur];
    }
  }

  vii swaps;

  auto change = [&](int x, int y) {
    // cout << "swapping " << x << " " << y << endl;
    swap(v[x], v[y]);
    swap(side[x], side[y]);
    side[x] = !side[x];
    side[y] = !side[y];
    swaps.pb(ii(x, y));
    // for (int i = 0; i < n; i++) cout << v[i] << " ";
    // cout << endl;
    // for (int i = 0; i < n; i++) cout << side[i] << " ";
    // cout << endl;
  };

  auto solve_one = [&](vi& c) {
    if (c.size() == 2) {
      // cout << "especial" << endl;
      // special case
      int any = -1;
      for (int i = 0; i < n; i++) {
        if (i != c.front() && i != c.back()) {
          any = i;
          break;
        }
      }
      change(any, c.front());
      change(any, c.back());
      change(c.front(), any);
      return;
    }
    int x = c.front();
    for (int i = 0; i < c.size() - 2; i++) {
      change(x, v[x]);
    }
    vi f;
    vi nf;
    for (int i = 0; i < c.size(); i++) {
      if (side[c[i]]) {
        f.pb(c[i]);
      } else if (v[c[i]] != c[i]) {
        nf.pb(c[i]);
      }
    }
    if (v[nf[0]] == f[1]) swap(f[0], f[1]);
    change(nf[0], f.back());
    change(f.front(), nf[0]);
    change(f.front(), f.back());
  };

  auto solve_two = [&](vi& c1, vi& c2) {
    change(c1.front(), c2.front());
    set<int> flip;
    flip.insert(c1.front());
    flip.insert(c2.front());
    while (true) {
      int x = *flip.begin();
      int y = *flip.rbegin();
      if (!side[v[x]]) {
        // use x
        change(x, v[x]);
      } else if (!side[v[y]]) {
        // use y
        change(y, v[y]);
      } else {
        // finished
        change(x, y);
        break;
      }
    }
  };

  for (int i = 0; i < cycles.size(); i += 2) {
    if (i + 1 >= cycles.size()) continue;

    solve_two(cycles[i], cycles[i + 1]);
  }

  if (cycles.size() % 2) solve_one(cycles.back());

  cout << swaps.size() << endl;
  for (ii x : swaps) cout << x.ff + 1 << " " << x.ss + 1 << endl;
}

#ifdef FILE_INPUT
freopen("equal.in", "r", stdin);
freopen("equal.out", "w", stdout);
#endif

int32_t main() {
  // DESYNC;
  int t = 1;
#ifdef MULTIPLE_TEST_CASE
  cin >> t;
#endif
  for (int _testcase = 1; _testcase <= t; _testcase++) solution(_testcase);
}
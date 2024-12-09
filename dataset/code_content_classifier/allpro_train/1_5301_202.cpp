#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const long long BIG = 1446803456761533460LL;
const int Big = 336860180;
const int INF = INT_MAX;
const vector<vector<int> > adj4({{0, 1}, {0, -1}, {1, 0}, {-1, 0}});
const vector<vector<int> > adj8(
    {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}});
int clk_ar[10];
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int powMod(int a, int b, int mod) {
  int n = 1;
  int p = a;
  while (b > 0) {
    if (b % 2 == 1) {
      n *= p;
      n %= mod;
    }
    p *= p;
    p %= mod;
    b /= 2;
  }
  return n;
}
int modularInverse(int a, int mod) { return powMod(a, mod - 2, mod); }
int binarysearch(int l, int r, bool (*bsfunction)(int)) {
  while (r - l > 1) {
    int mid = (l + r) / 2;
    bool val = bsfunction(mid);
    if (val) {
      r = mid;
    } else {
      l = mid;
    }
  }
  return l;
}
stringstream sss;
const int maxn = 100010;
const int sq = 400;
int ar[maxn];
pair<int, int> trans[maxn];
void MAIN() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < (n); ++i) {
    cin >> ar[i];
  }
  for (int i = (n)-1; i >= 0; --i) {
    int ii = i + ar[i];
    if (ii >= n) {
      trans[i] = make_pair(i, 0);
    } else if (ii / sq != i / sq) {
      trans[i] = make_pair(ii, 1);
    } else {
      trans[i] = make_pair(trans[ii].first, trans[ii].second + 1);
    }
  }
  for (int i = 0; i < (m); ++i) {
    int typ;
    cin >> typ;
    if (typ == 1) {
      int a;
      cin >> a;
      --a;
      int r = 0;
      while (a + ar[a] < n) {
        r += trans[a].second;
        a = trans[a].first;
      }
      cout << (a + 1) << ' ' << (r + 1) << '\n';
    } else {
      int a, b;
      cin >> a >> b;
      --a;
      ar[a] = b;
      for (int i = (a + 1) - 1; i >= (a - a % sq); --i) {
        int ii = i + ar[i];
        if (ii >= n) {
          trans[i] = make_pair(i, 0);
        } else if (ii / sq != i / sq) {
          trans[i] = make_pair(ii, 1);
        } else {
          trans[i] = make_pair(trans[ii].first, trans[ii].second + 1);
        }
      }
    }
  }
}
int TESTCASEN = 1;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  sss << R"(
8 5
10 1 1 10 1 2 1 2
1 1
0 1 3
1 1
0 3 4
1 2
    )";
  for (int test = 0; test < (TESTCASEN); ++test) {
    MAIN();
  }
  return 0;
}

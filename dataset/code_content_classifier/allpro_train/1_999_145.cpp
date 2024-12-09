#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v);
template <typename A, typename B>
ostream &operator<<(ostream &cout, pair<A, B> const &p) {
  return cout << "(" << p.first << ", " << p.second << ")";
}
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v) {
  cout << "[";
  for (int i = 0; i < v.size(); i++) {
    if (i) cout << ", ";
    cout << v[i];
  }
  return cout << "]";
}
template <typename A, typename B>
istream &operator>>(istream &cin, pair<A, B> &p) {
  cin >> p.first;
  return cin >> p.second;
}
mt19937 rng(steady_clock::now().time_since_epoch().count());
void usaco(string filename) {
  freopen((filename + ".in").c_str(), "r", stdin);
  freopen((filename + ".out").c_str(), "w", stdout);
}
const long double pi = 3.14159265358979323846;
const long long mod = 1000000007;
long long n, m, k, q, Q, T, l, r, x, y, z;
long long a[1000005];
long long b[1000005];
long long c[1000005];
string second, t;
long long ans = 0;
map<pair<int, int>, int> mk;
set<pair<int, int> > check;
pair<int, int> pts[100005];
map<int, vector<pair<int, int> > > locs;
map<int, int> pt;
pair<int, int> rev[100005];
void end() {
  cout << "NO" << endl;
  exit(0);
}
int get(pair<int, int> x) {
  if (mk.find(x) == mk.end()) return mod;
  if (check.find(x) != check.end()) return mk[x];
  int v = mk[x];
  pair<int, int> n1 = make_pair(x.first + 1, x.second);
  pair<int, int> n2 = make_pair(x.first, x.second + 1);
  int w = min(get(n1), get(n2));
  if (v > w) end();
  check.insert(x);
  return v;
}
int main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  };
  cin >> n;
  for (long long i = 0; i < (n); i++) {
    cin >> pts[i];
    mk[pts[i]] = 0;
    locs[pts[i].second - pts[i].first].push_back(pts[i]);
  }
  for (pair<int, vector<pair<int, int> > > x : locs)
    sort(locs[x.first].begin(), locs[x.first].end());
  for (int ele = 0; ele < n; ele++) cin >> a[ele];
  ;
  for (long long i = (n - 1); i >= 0; i--) {
    if (locs.find(a[i]) == locs.end()) end();
    if (pt.find(a[i]) == pt.end()) pt[a[i]] = locs[a[i]].size() - 1;
    int &v = pt[a[i]];
    if (v < 0) end();
    mk[locs[a[i]][v]] = i + 1;
    --v;
  }
  get(make_pair(0, 0));
  for (pair<pair<int, int>, int> x : mk) rev[x.second - 1] = x.first;
  cout << "YES" << endl;
  for (long long i = 0; i < (n); i++)
    cout << rev[i].first << " " << rev[i].second << '\n';
}

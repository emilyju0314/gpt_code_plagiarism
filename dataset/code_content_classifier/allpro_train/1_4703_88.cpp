#include <bits/stdc++.h>
using namespace std;
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
const int N = 2e5 + 9;
int n, m, p[N], sz[N];
struct Pt {
  long long x, y;
  Pt& operator=(const Pt& rhs) {
    x = rhs.x;
    y = rhs.y;
    return *this;
  }
  friend ostream& operator<<(ostream& os, const Pt& rhs) {
    return os << '(' << rhs.x << ',' << rhs.y << ')';
  }
  friend istream& operator>>(istream& is, Pt& rhs) {
    return is >> rhs.x >> rhs.y;
  }
};
Pt operator+(const Pt& lhs, const Pt& rhs) {
  return Pt{lhs.x + rhs.x, lhs.y + rhs.y};
}
Pt operator-(const Pt& lhs, const Pt& rhs) {
  return Pt{lhs.x - rhs.x, lhs.y - rhs.y};
}
bool operator<(const Pt& lhs, const Pt& rhs) {
  return make_pair(lhs.x, lhs.y) < make_pair(rhs.x, rhs.y);
}
bool operator>(const Pt& lhs, const Pt& rhs) { return rhs < lhs; }
bool operator<=(const Pt& lhs, const Pt& rhs) { return !(lhs > rhs); }
bool operator>=(const Pt& lhs, const Pt& rhs) { return !(lhs < rhs); }
long long operator*(const Pt& lhs, const Pt& rhs) {
  return lhs.x * rhs.x + lhs.y * rhs.y;
}
long long operator^(const Pt& lhs, const Pt& rhs) {
  return lhs.x * rhs.y - lhs.y * rhs.x;
}
vector<Pt> a, b, u, d;
bool inside(Pt pt) {
  if (pt <= a[0] || pt >= a[n - 1]) return 0;
  if (((a[0] - a[n - 1]) ^ (pt - a[n - 1])) > 0) {
    auto it = lower_bound(d.begin(), d.end(), pt);
    it--;
    Pt p1 = *it, p2 = *++it;
    if (((p1 - p2) ^ (pt - p2)) >= 0) return 0;
  } else {
    auto it = lower_bound(u.begin(), u.end(), pt);
    assert(it != u.begin());
    it--;
    Pt p1 = *it, p2 = *++it;
    if (((p1 - p2) ^ (pt - p2)) <= 0) return 0;
  }
  return 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> m;
  b.resize(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  u.push_back(a[0]);
  d.push_back(a[0]);
  for (int i = 1; i < n - 1; i++) {
    if (((a[0] - a[n - 1]) ^ (a[i] - a[n - 1])) > 0)
      d.push_back(a[i]);
    else
      u.push_back(a[i]);
  }
  u.push_back(a[n - 1]);
  d.push_back(a[n - 1]);
  for (int i = 0; i < m; i++) {
    if (!inside(b[i])) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}

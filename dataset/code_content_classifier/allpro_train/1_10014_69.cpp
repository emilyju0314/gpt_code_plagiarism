#include <bits/stdc++.h>
using namespace std;
template <typename TH>
void _dbg(const char* sdbg, TH h) {
  cerr << sdbg << "=" << h << "\n";
}
template <typename TH, typename... TA>
void _dbg(const char* sdbg, TH h, TA... t) {
  while (*sdbg != ',') cerr << *sdbg++;
  cerr << "=" << h << ",";
  _dbg(sdbg + 1, t...);
}
template <class C>
void mini(C& a4, C b4) {
  a4 = min(a4, b4);
}
template <class C>
void maxi(C& a4, C b4) {
  a4 = max(a4, b4);
}
template <class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> pair) {
  return out << "(" << pair.first << ", " << pair.second << ")";
}
template <class A, class B, class C>
struct Triple {
  A first;
  B second;
  C third;
  bool operator<(const Triple& t) const {
    if (first != t.first) return first < t.first;
    if (second != t.second) return second < t.second;
    return third < t.third;
  }
};
template <class T>
void ResizeVec(T&, vector<long long>) {}
template <class T>
void ResizeVec(vector<T>& vec, vector<long long> sz) {
  vec.resize(sz[0]);
  sz.erase(sz.begin());
  if (sz.empty()) {
    return;
  }
  for (T& v : vec) {
    ResizeVec(v, sz);
  }
}
template <class A, class B, class C>
ostream& operator<<(ostream& out, Triple<A, B, C> t) {
  return out << "(" << t.first << ", " << t.second << ", " << t.third << ")";
}
template <class T>
ostream& operator<<(ostream& out, vector<T> vec) {
  out << "(";
  for (auto& v : vec) out << v << ", ";
  return out << ")";
}
map<Triple<long long, long long, long long>, long long> memo;
long long Rec(long long l, long long r, long long dis, long long bd) {
  mini(bd, r);
  maxi(bd, l);
  if (memo.count({r - l, dis, bd - l})) {
    return memo[{r - l, dis, bd - l}];
  }
  long long m = (l + r) / 2;
  if (m - l > dis || (m - l == dis && m <= bd)) {
    return memo[{r - l, dis, bd - l}] =
               Rec(l, m, dis, bd) + Rec(m, r, dis, bd) + 1;
  } else {
    return 0;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  if (0) cout << fixed << setprecision(10);
  cin.tie(0);
  long long n, k;
  cin >> n >> k;
  if (k == 1) {
    cout << "1" << endl;
    return 0;
  }
  if (k == 2) {
    cout << n << endl;
    return 0;
  }
  k -= 2;
  (Rec(1, n, 1, 2));
  long long dis = 1, bd = n;
  long long kl = 1, kp = n;
  while (kl <= kp) {
    long long aktc = (kl + kp) / 2;
    if (Rec(1, n, aktc, n) >= k) {
      dis = aktc;
      kl = aktc + 1;
    } else {
      kp = aktc - 1;
    }
    (kl, kp);
  }
  (dis);
  kl = 1, kp = n;
  while (kl <= kp) {
    long long aktc = (kl + kp) / 2;
    if (Rec(1, n, dis, aktc) >= k) {
      bd = aktc;
      kp = aktc - 1;
    } else {
      kl = aktc + 1;
    }
  }
  cout << bd << endl;
  return 0;
}

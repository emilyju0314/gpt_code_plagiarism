#include <bits/stdc++.h>
using namespace std;

string to_string(string s) { return '"' + s + '"'; }
string to_string(bool b) { return b ? "true" : "false"; }
template <size_t N> string to_string(bitset<N> bs) {
  string res;
  for (size_t i = 0; i < N; ++i) res += '0' + bs[i];
  return res;
}
string to_string(vector<bool> v) {
  string res = "{";
  for (bool e : v) res += to_string(e) + ", ";
  return res += "}";
}

template <class T, class U> string to_string(pair<T, U> p);
template <class C> string to_string(C c) {
  string res = "{";
  for (auto e : c) res += to_string(e) + ", ";
  return res += "}";
}
template <class T, class U> string to_string(pair<T, U> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

void debug() { cerr << '\n'; }
template <class Head, class... Tail> void debug(Head head, Tail... tail) {
  cerr << ' ' << to_string(head), debug(tail...);
}
#ifdef LOCAL
#define DEBUG(...) cerr << "[" << #__VA_ARGS__ << "]:", debug(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

#ifdef LOCAL
constexpr int B = 3;
#else
constexpr int B = 128;
#endif
constexpr long long inf = 0x3f3f3f3fLL << 32;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<long long> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }
  struct Block {
    int m;
    long long laz;
    vector<long long> amin, bmin, d;
    int p;
  };
  vector<Block> bs((n + B - 1) / B);
  auto push = [&](int k) {
    for (int i = k * B; i < min((k + 1) * B, n); ++i) {
      a[i] += bs[k].laz;
    }
    bs[k].laz = 0;
  };
  auto build = [&](int k) {
    vector<int> idx;
    for (int i = k * B; i < min((k + 1) * B, n); ++i) {
      idx.push_back(i);
    }
    bs[k].m = idx.size();
    bs[k].laz = 0;
    sort(begin(idx), end(idx), [&](int i, int j) {
      return a[i] - b[i] < a[j] - b[j];
    });
    bs[k].amin.resize(bs[k].m + 1);
    bs[k].amin[bs[k].m] = inf;
    for (int t = bs[k].m; t--; ) {
      bs[k].amin[t] = min(a[idx[t]], bs[k].amin[t + 1]);
    }
    bs[k].bmin.resize(bs[k].m + 1);
    bs[k].bmin[0] = inf;
    for (int t = 0; t < bs[k].m; ++t) {
      bs[k].bmin[t + 1] = min(bs[k].bmin[t], b[idx[t]]);
    }
    bs[k].p = 0;
    while (bs[k].p < bs[k].m and a[idx[bs[k].p]] - b[idx[bs[k].p]] < 0) {
      ++bs[k].p;
    }
    bs[k].d.resize(bs[k].m);
    for (int t = 0; t < bs[k].m; ++t) {
      bs[k].d[t] = a[idx[t]] - b[idx[t]];
    }
  };
  auto add = [&](int l, int r, long long x) {
    if (l % B) {
      push(l / B);
      while (l < r and l % B) {
        a[l] += x;
        ++l;
      }
      build((l - 1) / B);
    }
    if (r % B) {
      push(r / B);
      while (l < r and r % B) {
        --r;
        a[r] += x;
      }
      build(r / B);
    }
    while (l < r) {
      int k = l / B;
      bs[k].laz += x;
      int ng = -1, ok = bs[k].m;
      while (ok - ng > 1) {
        int mid = (ng + ok) / 2;
        (bs[k].d[mid] + bs[k].laz >= 0 ? ok : ng) = mid;
      }
      bs[k].p = ok;
      l += B;
    }
  };
  auto acc = [&](int l, int r) {
    long long res = inf;
    if (l % B) {
      push(l / B);
      while (l < r and l % B) {
        res = min(res, max(a[l], b[l]));
        ++l;
      }
      build((l - 1) / B);
    }
    if (r % B) {
      push(r / B);
      while (l < r and r % B) {
        --r;
        res = min(res, max(a[r], b[r]));
      }
      build(r / B);
    }
    while (l < r) {
      int k = l / B;
      res = min(res, min(bs[k].amin[bs[k].p] + bs[k].laz, bs[k].bmin[bs[k].p]));
      l += B;
    }
    return res;
  };
  for (int k = 0; k < (int)bs.size(); ++k) {
    build(k);
    DEBUG(bs[k].amin);
    DEBUG(bs[k].bmin);
    DEBUG(bs[k].p);
  }
  while (q--) {
    int tp;
    cin >> tp;
    if (tp == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      --l;
      add(l, r, x);
    } else {
      int l, r;
      cin >> l >> r;
      --l;
      cout << acc(l, r) << '\n';
    }
  }
}


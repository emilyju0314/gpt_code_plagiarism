#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct outputer;
struct outputable {};
template <typename T>
inline auto sqr(T x) -> decltype(x * x) {
  return x * x;
}
template <typename T1, typename T2>
inline bool umx(T1& a, T2 b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T1, typename T2>
inline bool umn(T1& a, T2 b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
const int N = 100000;
const int M = 30;
struct Input {
  int n;
  pair<uint32_t, uint32_t> st[N], fn[N];
  bool read() {
    if (!(cin >> n)) {
      return 0;
    }
    for (int i = int(0); i < int(n); ++i) {
      scanf("%u%u%u%u", &st[i].first, &st[i].second, &fn[i].first,
            &fn[i].second);
    }
    return 1;
  }
  void init(const Input& input) { *this = input; }
};
struct Data : Input {
  int ans;
  void write() { cout << ans << endl; }
};
namespace Main {
const int K = 4 * N;
const int EQ = 0;
const int LE = 1;
const int GR = 2;
const int HI = 3;
const int LO = 4;
const int swp[5] = {0, 2, 1, 4, 3};
const int flp[5] = {0, 2, 1, 3, 4};
const bool is_less[5] = {0, 1, 0, 1, 0};
inline uint32_t get_last_one(uint32_t x) {
  uint32_t res = 1;
  for (int i = int(5) - 1; i >= int(0); --i) {
    if (x & -(res << (1 << i))) {
      res <<= (1 << i);
    }
  }
  return res;
}
inline pair<uint32_t, uint32_t> flip(pair<uint32_t, uint32_t> a) {
  return pair<uint32_t, uint32_t>(a.second, a.first);
}
inline pair<uint32_t, uint32_t> cut(pair<uint32_t, uint32_t> a, uint32_t d) {
  return pair<uint32_t, uint32_t>(a.first & -(d + d), a.second & -(d + d));
}
inline pair<pair<uint32_t, uint32_t>, int> calc2(pair<uint32_t, uint32_t> a,
                                                 uint32_t d) {
  uint32_t z = a.second & (d - 1);
  if (z == 0) {
    return make_pair(a, HI);
  }
  d = get_last_one(z);
  return make_pair(cut(a, d), LE);
}
inline pair<pair<uint32_t, uint32_t>, int> calc(pair<uint32_t, uint32_t> a,
                                                pair<uint32_t, uint32_t> b) {
  if (a == b) {
    return make_pair(a, 0);
  }
  uint32_t d =
      max(get_last_one(a.first ^ b.first), get_last_one(a.second ^ b.second));
  if ((a.first & d) && (b.second & d)) {
    return make_pair(cut(a, d), GR);
  }
  if ((a.second & d) && (b.first & d)) {
    return make_pair(cut(a, d), LE);
  }
  if (a.first & d) {
    auto res = calc2(b, d);
    return make_pair(res.first, swp[res.second]);
  }
  if (a.second & d) {
    auto res = calc2(flip(b), d);
    return make_pair(flip(res.first), swp[flp[res.second]]);
  }
  if (b.first & d) {
    auto res = calc2(a, d);
    return make_pair(res.first, res.second);
  }
  if (b.second & d) {
    auto res = calc2(flip(a), d);
    return make_pair(flip(res.first), flp[res.second]);
  }
  assert(0);
}
inline pair<uint32_t, uint32_t> common(pair<uint32_t, uint32_t> a,
                                       pair<uint32_t, uint32_t> b) {
  return calc(a, b).first;
}
inline bool cmp(pair<uint32_t, uint32_t> a, pair<uint32_t, uint32_t> b) {
  return is_less[calc(a, b).second];
}
inline uint64_t key(pair<uint32_t, uint32_t> a) {
  return (uint64_t(a.first) << 32) + a.second;
}
struct Solution : Data {
  int v_cnt;
  pair<uint32_t, uint32_t> a[K];
  unordered_map<uint64_t, int> num;
  int pr[K];
  int lvl[K];
  int inc[K], dec[K];
  set<int> bounds;
  void flip(int x) {
    if (bounds.count(x)) {
      bounds.erase(x);
    } else {
      bounds.insert(x);
    }
  }
  void solve() {
    for (int i = int(0); i < int(n); ++i) {
      a[v_cnt++] = st[i];
      a[v_cnt++] = fn[i];
    }
    sort(a, a + v_cnt, cmp);
    v_cnt = unique(a, a + v_cnt) - a;
    for (int i = int(v_cnt - 1) - 1; i >= int(0); --i) {
      a[v_cnt++] = common(a[i], a[i + 1]);
    }
    sort(a, a + v_cnt, cmp);
    v_cnt = unique(a, a + v_cnt) - a;
    for (int i = int(0); i < int(v_cnt); ++i) {
      num[key(a[i])] = i;
      lvl[i] = a[i].first + a[i].second;
    }
    {
      vector<int> q;
      q.emplace_back(0);
      pr[0] = -1;
      for (int i = int(1); i < int(v_cnt); ++i) {
        while (common(a[q.back()], a[i]) != a[q.back()]) {
          q.pop_back();
          assert(((int)(q).size()));
        }
        pr[i] = q.back();
        q.emplace_back(i);
      }
    }
    memset(inc, 0, sizeof inc);
    memset(dec, 0, sizeof dec);
    for (int i = int(0); i < int(n); ++i) {
      inc[num[key(st[i])]]++;
      inc[num[key(fn[i])]]++;
      dec[num[key(common(st[i], fn[i]))]] += 2;
    };
    ;
    ;
    ;
    for (int i = int(v_cnt) - 1; i >= int(0); --i) {
      if (inc[i]) {
        flip(lvl[i]);
        flip(lvl[i] + 1);
      }
      inc[i] -= dec[i];
      if (inc[i]) {
        assert(i);
        flip(lvl[pr[i]] + 1);
        flip(lvl[i]);
        inc[pr[i]] += inc[i];
      }
    }
    bounds.erase(0);
    ans = ((int)(bounds).size());
  }
  void clear() { *this = Solution(); }
};
}  // namespace Main
Main::Solution sol;
int main() {
  cout.setf(ios::showpoint | ios::fixed);
  cout.precision(20);
  sol.read();
  sol.solve();
  sol.write();
  return 0;
}

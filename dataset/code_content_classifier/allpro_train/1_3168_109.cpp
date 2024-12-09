#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-10;
const long long MOD = 1e9 + 7;
const long double PI = 3.1415926535897932384626433832795028841;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= MOD;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
  }
  return res;
}
ostream& operator<<(std::ostream& stream, const long long* arr) {
  int i = 0;
  cout << "{";
  while (arr[i] != INT_MAX) {
    cout << arr[i];
    if (arr[i + 1] != INT_MAX) cout << ",";
    i++;
  }
  cout << "}";
  return stream;
}
ostream& operator<<(std::ostream& stream, const vector<int> vec) {
  cout << "{";
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i];
    if (i != vec.size() - 1) cout << ",";
  }
  cout << "}";
  return stream;
}
ostream& operator<<(std::ostream& stream,
                    const pair<long long, long long>& vec) {
  cout << "(" << vec.first << ',' << vec.second << ")";
  return stream;
}
const int maxn = 1e5 + 5;
const int maxm = 1e5 + 5;
const int maxk = 1e5 + 5;
const int maxq = 1e5 + 5;
template <class T>
struct segtree_t {
  vector<T> t, lazy, flag_equal;
  int st, sz;
  T (*addition_fun)(T, T);
  T invalid_value;
  segtree_t() {}
  segtree_t(int start, int finish, T* arr, T (*add_fun)(T, T), T invalid_val) {
    int size = (finish + 1) * 2;
    int tree_size = 2;
    while (tree_size < size) tree_size *= 2;
    t = vector<T>(tree_size);
    lazy = vector<T>(tree_size);
    flag_equal = vector<T>(tree_size);
    st = start;
    sz = finish;
    addition_fun = add_fun;
    invalid_value = invalid_val;
    build(1, start, finish, arr);
  }
  void build(int i, int l, int r, T* arr) {
    if (l > r) return;
    lazy[i] = 0;
    flag_equal[i] = 0;
    if (l == r) {
      t[i] = arr[l];
    } else {
      build(i * 2, l, (l + r) / 2, arr);
      build(i * 2 + 1, (l + r) / 2 + 1, r, arr);
      t[i] = addition_fun(t[i * 2], t[i * 2 + 1]);
    }
  }
  void inc_range(int l, int r, T value) {
    if (l > r) return;
    inc_range_rec(1, st, sz, l, r, value);
  }
  void set_values(int l, int r, T value) {
    set_values_rec(1, st, sz, l, r, value);
  }
  void inc_range_rec(int i, int l, int r, int tl, int tr, T value) {
    if (lazy[i] != 0) {
      t[i] += lazy[i];
      if (l != r) {
        lazy[i * 2] += lazy[i];
        lazy[i * 2 + 1] += lazy[i];
      }
      lazy[i] = 0;
    }
    if (r < tl or l > tr) return;
    if (l > r) return;
    if (l >= tl and r <= tr) {
      if (l != r) {
        lazy[i * 2] += value;
        lazy[i * 2 + 1] += value;
      }
      t[i] += value;
    } else {
      inc_range_rec(i * 2, l, (l + r) / 2, tl, tr, value);
      inc_range_rec(i * 2 + 1, (l + r) / 2 + 1, r, tl, tr, value);
      t[i] = addition_fun(t[i * 2], t[i * 2 + 1]);
    }
  }
  T query_rec(int i, int l, int r, int tl, int tr) {
    if (flag_equal[i] != 0) {
      if (l != r) {
        t[i * 2] = t[i];
        t[i * 2 + 1] = t[i];
        flag_equal[i * 2] = 1;
        flag_equal[i * 2 + 1] = 1;
      }
      flag_equal[i] = 0;
    }
    if (r < tl or l > tr) return invalid_value;
    if (l > r) return invalid_value;
    if (lazy[i] != 0) {
      t[i] += lazy[i];
      if (l != r) {
        lazy[i * 2] += lazy[i];
        lazy[i * 2 + 1] += lazy[i];
      }
      lazy[i] = 0;
    }
    if (l >= tl and r <= tr) {
      return t[i];
    } else {
      T m1 = query_rec(i * 2, l, (l + r) / 2, tl, tr);
      T m2 = query_rec(i * 2 + 1, (l + r) / 2 + 1, r, tl, tr);
      if (m1 == invalid_value && m2 == invalid_value) return invalid_value;
      if (m1 == invalid_value) return m2;
      if (m2 == invalid_value) return m1;
      return addition_fun(m1, m2);
    }
  }
  T query(int l, int r) { return query_rec(1, st, sz, l, r); }
  void set_values_rec(int i, int l, int r, int tl, int tr, T value) {
    if (flag_equal[i] != 0) {
      if (l != r) {
        t[i * 2] = t[i];
        t[i * 2 + 1] = t[i];
        flag_equal[i * 2] = 1;
        flag_equal[i * 2 + 1] = 1;
      }
      flag_equal[i] = 0;
    }
    if (r < tl || l > tr) return;
    if (l > r) return;
    if (l >= tl and r <= tr) {
      t[i] = value;
      flag_equal[i] = 1;
    } else {
      set_values_rec(i * 2, l, (l + r) / 2, tl, tr, value);
      set_values_rec(i * 2 + 1, (l + r) / 2 + 1, r, tl, tr, value);
      t[i] = addition_fun(t[i * 2], t[i * 2 + 1]);
    }
  }
  ~segtree_t() {}
};
long long n, k;
int cn;
long long b[maxn];
pair<long long, long long> lr[maxq * 4];
long long min_lr[maxq * 4];
int int_cnt = 0;
vector<tuple<int, long long, long long, long long>> Q;
set<long long> events;
bool cmp(long long a, long long b) { return a < b; }
long long cmp_fun(long long a, long long b) { return min(a, b); }
int main() {
  cin >> n >> k;
  long long minvalue = LLONG_MAX;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    minvalue = min(minvalue, b[i]);
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    long long type;
    cin >> type;
    long long l, r;
    if (type == 1) {
      long long x;
      cin >> l >> r >> x;
      Q.push_back(make_tuple(type, l, r, x));
    } else if (type == 2) {
      cin >> l >> r;
      Q.push_back(make_tuple(type, l, r, 0));
    }
    events.insert(l);
    events.insert(r);
  }
  events.insert(1);
  events.insert(n * k);
  long long last = -1;
  for (set<long long>::iterator it = events.begin(); it != events.end(); it++) {
    if (last != -1 && last <= *it - 1) lr[int_cnt++] = make_pair(last, *it - 1);
    lr[int_cnt++] = make_pair(*it, *it);
    last = *it + 1;
  }
  segtree_t<long long> segA = segtree_t<long long>(1, n, b, cmp_fun, LLONG_MAX);
  for (int i = 0; i < int_cnt; i++) {
    int a_list = (lr[i].first - 1) / n + 1;
    int a_item = (lr[i].first - 1) % n + 1;
    int b_list = (lr[i].second - 1) / n + 1;
    int b_item = (lr[i].second - 1) % n + 1;
    if (a_list == b_list) {
      min_lr[i] = segA.query(a_item, b_item);
    } else if (a_list + 1 == b_list) {
      min_lr[i] = min(segA.query(1, b_item), segA.query(a_item, n));
    } else {
      min_lr[i] = minvalue;
    }
  }
  min_lr[int_cnt] = INT_MAX;
  segtree_t<long long> segB =
      segtree_t<long long>(0, int_cnt - 1, min_lr, cmp_fun, LLONG_MAX);
  for (int i = 0; i < Q.size(); i++) {
    tuple<int, long long, long long, long long> query = Q[i];
    long long real_left = get<1>(query);
    long long real_right = get<2>(query);
    int A1 = -1;
    int B1 = int_cnt;
    while (A1 + 1 != B1) {
      int h = (B1 + A1) / 2;
      if (lr[h].first <= real_left) {
        A1 = h;
      } else {
        B1 = h;
      }
    }
    int A2 = -1;
    int B2 = int_cnt;
    while (A2 + 1 != B2) {
      int h = (B2 + A2) / 2;
      if (lr[h].second >= real_right) {
        B2 = h;
      } else {
        A2 = h;
      }
    }
    long long left_b = A1;
    long long right_b = B2;
    if (get<0>(query) == 1) {
      segB.set_values(left_b, right_b, get<3>(query));
    } else {
      cout << segB.query(left_b, right_b) << '\n';
    }
  }
}

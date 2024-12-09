#include <bits/stdc++.h>
using namespace std;
const long long Q = 2e5 + 3;
const long long T = 1 << 16;
long long k, q, sz;
vector<array<long long, 3>> sweepline;
vector<array<long long, 3>> qu;
vector<long long> st[16 * 4 * T];
bool st_ans[16 * 4 * T];
bool ans[16 * 2 * T];
bool check(long long i, long long l, long long r) {
  if (l == r) {
    for (long long j = 0; j < 16; ++j) {
      if (st_ans[i + j]) {
        for (long long x : st[i + j]) {
          if (ans[x]) {
            return false;
          }
        }
      }
    }
    return true;
  }
  long long mid = (l + r) >> 1;
  if (!check(2 * i + 16, l, mid)) return false;
  if (!check(2 * i + 32, mid + 1, r)) return false;
  for (long long j = 0; j < 16; ++j) {
    st_ans[i + j] =
        st_ans[i + j] || st_ans[2 * i + 16 + j] || st_ans[2 * i + 32 + j];
    if (st_ans[i + j]) {
      for (long long x : st[i + j]) {
        if (ans[x]) {
          return false;
        }
      }
    }
  }
  return true;
}
void build(long long i, long long l, long long r) {
  if (l == r) {
    for (long long j = 0; j < 16; ++j) ans[l * 16 + j] = st_ans[i + j];
    return;
  }
  for (long long j = 0; j < 16; ++j) {
    if (st_ans[i + j]) {
      st_ans[2 * i + 16 + j] = true;
      st_ans[2 * i + 32 + j] = true;
    }
  }
  long long mid = (l + r) >> 1;
  build(2 * i + 16, l, mid);
  build(2 * i + 32, mid + 1, r);
}
void update(long long i, long long l, long long r, long long sl, long long sr,
            long long big, long long v) {
  if (l > sr || r < sl) return;
  if (sl <= l && r <= sr) {
    for (long long j = 0; j < 16; ++j) {
      if ((v >> j) & 1)
        st_ans[i + j] = true;
      else
        st[i + j].push_back(big * 16 + j + 16 * sz);
    }
    return;
  }
  long long mid = (l + r) >> 1;
  update(2 * i + 16, l, mid, sl, sr, big, v);
  update(2 * i + 32, mid + 1, r, sl, sr, big, v);
}
void add_edges(long long l, long long r, long long v) {
  long long big = l / sz;
  l %= sz;
  r %= sz;
  for (long long i = 0; i < 16; ++i)
    if ((v >> i) & 1) ans[big * 16 + i + 16 * sz] = true;
  update(0, 0, sz - 1, l, r, big, v);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> k >> q;
  for (long long i = 0; i < q; ++i) {
    long long l, r, v;
    cin >> l >> r >> v;
    sweepline.push_back({l, -1, v});
    sweepline.push_back({r, 1, v});
  }
  sort(sweepline.begin(), sweepline.end());
  long long curr = -1, cnt_ = 0, start = -1;
  for (long long i = 0; i < 2 * q; ++i) {
    auto arr = sweepline[i];
    if (arr[1] == -1) {
      if (curr != -1 && arr[2] != curr) {
        cout << "impossible\n";
        return 0;
      }
      curr = arr[2];
      if (!cnt_) start = arr[0];
      cnt_++;
    } else {
      if (cnt_ == 1) qu.push_back({start, arr[0], curr});
      cnt_--;
      if (!cnt_) curr = -1;
    }
  }
  sz = (1 << k);
  for (long long i = 0; i < qu.size(); ++i) {
    auto [l, r, v] = qu[i];
    if (l / sz == r / sz)
      add_edges(l, r, v);
    else {
      add_edges(l, (l / sz) * sz + sz - 1, v);
      add_edges((r / sz) * sz, r, v);
      for (long long j = (l / sz) * sz + sz; j < (r / sz) * sz; j += sz)
        add_edges(j, j + sz - 1, v);
    }
  }
  build(0, 0, sz - 1);
  if (!check(0, 0, sz - 1)) {
    cout << "impossible\n";
    return 0;
  }
  cout << "possible\n";
  for (long long i = 0; i < 32 * sz; i += 16) {
    long long x = 0;
    for (long long j = 0; j < 16; ++j)
      if (ans[i + j]) x += (1 << j);
    cout << x << "\n";
  }
}

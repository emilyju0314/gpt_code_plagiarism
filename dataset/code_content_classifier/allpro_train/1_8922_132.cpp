#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
const long long MOD = 1e9 + 7;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 1e9 + 7;
const double PI = acos(-1.0);
const double EPS = 1e-8;
int _;
using namespace std;
long long dat[MAXN << 2];
long long mk[MAXN << 2];
int N = MAXN - 1;
void push_down(int rt) {
  if (mk[rt]) {
    mk[rt << 1] += mk[rt];
    mk[rt << 1 | 1] += mk[rt];
    dat[rt << 1] += mk[rt];
    dat[rt << 1 | 1] += mk[rt];
    mk[rt] = 0;
  }
}
void push_up(int rt) { dat[rt] = max(dat[rt << 1], dat[rt << 1 | 1]); }
void build(int l, int r, int rt) {
  if (l == r) {
    dat[rt] = l;
    mk[rt] = 0;
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, rt << 1);
  build(mid + 1, r, rt << 1 | 1);
  push_up(rt);
}
void add(int ql, int qr, int val, int l, int r, int rt) {
  if (ql <= l && qr >= r) {
    dat[rt] += val;
    mk[rt] += val;
    return;
  }
  push_down(rt);
  int mid = (l + r) >> 1;
  if (ql <= mid) add(ql, qr, val, l, mid, rt << 1);
  if (qr > mid) add(ql, qr, val, mid + 1, r, rt << 1 | 1);
  push_up(rt);
}
long long query(int ql, int qr, int l, int r, int rt) {
  if (ql <= l && qr >= r) {
    return dat[rt];
  }
  push_down(rt);
  long long res = -LINF;
  int mid = (l + r) >> 1;
  if (ql <= mid) res = max(res, query(ql, qr, l, mid, rt << 1));
  if (qr > mid) res = max(res, query(ql, qr, mid + 1, r, rt << 1 | 1));
  push_up(rt);
  return res;
}
vector<pair<int, int>> vis;
int main() {
  int Q;
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> Q;
  char op;
  vis.push_back(make_pair(0, 0));
  int t, d;
  build(1, N, 1);
  while (Q--) {
    cin >> op;
    if (op == '?') {
      cin >> t;
      vis.push_back(make_pair(0, 0));
      cout << (t + 1 - query(t + 1, t + 1, 1, N, 1) + query(1, t, 1, N, 1) - t)
           << endl;
    } else if (op == '+') {
      cin >> t >> d;
      vis.push_back(make_pair(t, d));
      add(t + 1, N, -d, 1, N, 1);
    } else if (op == '-') {
      cin >> t;
      vis.push_back(make_pair(0, 0));
      add(vis[t].first + 1, N, vis[t].second, 1, N, 1);
    }
  }
  return 0;
}

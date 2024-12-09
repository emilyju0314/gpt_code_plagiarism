#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) (v).begin(), (v).end()
#define reps(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep(i, n) reps(i, 0, n)

template<class T1, class T2> void chmin(T1 &a, T2 b){if(a>b)a=b;}
template<class T1, class T2> void chmax(T1 &a, T2 b){if(a<b)a=b;}

typedef pair<int, int> Pi;
typedef tuple<int, int, int> Ti;
typedef vector<int> vint;

const int inf = 1LL << 55;
const int mod = 1e9 + 7;

struct SegmentTree {
  vector<Pi> data;
  vector<Pi> lazy;
  int sz;
  SegmentTree(int n) {
    sz = 1; while(sz < n) sz <<= 1;
    data.resize(2*sz-1, Pi(0, 0));
    lazy.resize(2*sz-1, Pi(0, 0));
  }
  void merge(Pi& p, Pi q) {
    //cout<<p.second<<" "<<q.first<<endl;
    if(p.second == q.first-1) {
      if(p.first == 0) p = q;
      else p.second = q.second;
    } else {
      p = Pi(-1, -1);
    }
  }
  void merge2(Pi& p, Pi q) {
    if(p.first == 0) p = q;
    else if(p.second == q.first-1) p.second = q.second;
    else p = Pi(-1, -1);
  }
  void push(int k, int l, int r) {
    if(lazy[k].first) {
      merge(data[k], lazy[k]);
      if(r - l > 1) {
	merge2(lazy[2*k+1], lazy[k]);
	merge2(lazy[2*k+2], lazy[k]);
      }
      if(lazy[k].first != -1) lazy[k] = Pi(0, 0);
    }
  }
  void update(int a, int b, int x, int k, int l, int r, bool flag) {
    push(k, l, r);
    if(r <= a || b <= l) return;
    if(a <= l && r <= b) {
      //cout<<a<<" "<<b<<" "<<x<<" "<<l<<" "<<r<<endl;
      if(flag) merge2(lazy[k], Pi(x, x));
      push(k, l, r);
      return;
    }
    update(a, b, x, 2*k+1, l, (l+r)/2, flag);
    update(a, b, x, 2*k+2, (l+r)/2, r, flag);
  }
  void update(int a, int b, int x, bool flag = true) {
    update(a, b, x, 0, 0, sz, flag);
  }
  int query(int a, int b, int x, int k, int l, int r) {
    push(k, l, r);
    if(r <= a || b <= l) return 0;
    if(a <= l && r <= b) return data[k].first == 1 && data[k].second == x;
    return query(a, b, x, 2*k+1, l, (l+r)/2) + query(a, b, x, 2*k+2, (l+r)/2, r);
  }
  int query(int a, int b, int x) {
    return query(a, b, x, 0, 0, sz);
  }
};

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  int N, K, T;
  cin >> N >> K >> T;

  SegmentTree seg(N);

  rep(i, T) {
    int l, r, x;
    cin >> l >> r >> x;
    --l;
    seg.update(l, r, x);
  }
  int ans = 0;
  rep(i, N) {
    ans += seg.query(i, i+1, K);
  }
  cout << ans << endl;

  return 0;
}
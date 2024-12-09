#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, inf = 1061109567;
const long long infll = 4557430888798830399;
const int N = 3e5 + 5;
struct Seg {
  int l, r, p;
  bool operator<(const Seg &rhs) const { return r < rhs.r; }
} s[N];
class PIT {
 private:
  struct Node {
    int mn, lChild, rChild;
    Node(int _mn = -inf) {
      mn = _mn;
      lChild = rChild = -1;
    }
  } t[N * 20];
  int curSz = 0;
  void build(int l, int r, int x) {
    if (l == r) {
      t[x] = Node();
      return;
    }
    int m = (l + r) >> 1;
    t[x].lChild = ++curSz;
    t[x].rChild = ++curSz;
    build(l, m, t[x].lChild);
    build(m + 1, r, t[x].rChild);
    t[x].mn = -inf;
  }
  void upd(int l, int r, int pos, int val, int x, int oldNode) {
    if (l == r) {
      t[x].mn = max(t[oldNode].mn, val);
      return;
    }
    t[x] = t[oldNode];
    int m = (l + r) >> 1;
    if (pos <= m) {
      int newl = ++curSz, oldl = t[x].lChild;
      t[x].lChild = newl;
      upd(l, m, pos, val, newl, oldl);
    } else {
      int newr = ++curSz, oldr = t[x].rChild;
      t[x].rChild = newr;
      upd(m + 1, r, pos, val, newr, oldr);
    }
    t[x].mn = min(t[t[x].lChild].mn, t[t[x].rChild].mn);
  }
  int get(int l, int r, int s, int e, int x) {
    if (l > e || r < s) return inf;
    if (s <= l && r <= e) return t[x].mn;
    int m = (l + r) >> 1;
    return min(get(l, m, s, e, t[x].lChild), get(m + 1, r, s, e, t[x].rChild));
  }

 public:
  int n;
  vector<int> roots;
  void init(int _n) {
    n = _n;
    roots.push_back(0);
    build(0, n - 1, 0);
  }
  void upd(int pos, int val) {
    ++curSz;
    int lstRoot = roots.back();
    roots.push_back(curSz);
    upd(0, n - 1, pos, val, curSz, lstRoot);
  }
  int get(int l, int r, int root) { return get(0, n - 1, l, r, root); }
  int getLatestRoot() { return roots.back(); }
} st;
int n, m, k;
vector<int> allr;
map<int, int> ver;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) cin >> s[i].l >> s[i].r >> s[i].p, s[i].p--;
  sort(s, s + k);
  for (int i = 0; i < k; i++) allr.push_back(s[i].r);
  sort(allr.begin(), allr.end());
  allr.resize(unique(allr.begin(), allr.end()) - allr.begin());
  st.init(n);
  for (int i = 0; i < k; i++) {
    st.upd(s[i].p, s[i].l);
    ver[s[i].r] = st.getLatestRoot();
  }
  for (int i = 0; i < m; i++) {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    a--, b--;
    int bigr = upper_bound(allr.begin(), allr.end(), y) - allr.begin() - 1;
    if (bigr == -1)
      cout << "no\n";
    else {
      int tmp = allr[bigr];
      int mnl = st.get(a, b, ver[tmp]);
      if (mnl >= x)
        cout << "yes\n";
      else
        cout << "no\n";
    }
    cout.flush();
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
template <typename T>
void maxtt(T &t1, T t2) {
  t1 = max(t1, t2);
}
template <typename T>
void mintt(T &t1, T t2) {
  t1 = min(t1, t2);
}
bool debug = 0;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
string direc = "RDLU";
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(int &x, int y, int mod = 1000000007) {
  assert(y >= 0);
  x += y;
  if (x >= mod) x -= mod;
  assert(x >= 0 && x < mod);
}
void et(int x = -1) {
  printf("%d\n", x);
  exit(0);
}
long long fastPow(long long x, long long y, int mod = 1000000007) {
  long long ans = 1;
  while (y > 0) {
    if (y & 1) ans = (x * ans) % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
long long gcd1(long long x, long long y) { return y ? gcd1(y, x % y) : x; }
vector<pair<int, char>> mp[100035];
char fac[100035];
map<string, int> mpc;
int strId, Ans[100035], dfn[100035];
vector<int> spos[100035 * 2];
int qylr(int id, int l, int r) {
  if (r < l) return 0;
  return upper_bound(spos[id].begin(), spos[id].end(), r) -
         lower_bound(spos[id].begin(), spos[id].end(), l);
}
struct mb {
  int u, v, id;
  string x, rx = "";
  void rd(int i) {
    id = i;
    cin >> u >> v >> x;
    if (mpc.find(x) == mpc.end()) mpc[x] = ++strId;
    for (int i = (int)x.size() - 1; ~i; i--) rx.push_back(x[i]);
    if (mpc.find(rx) == mpc.end()) mpc[rx] = ++strId;
  }
} qs[100035];
struct kmp {
  int nxt[200];
  void init(string &str) {
    int k = -1, j = 0;
    nxt[0] = -1;
    int plen = (int)str.size();
    while (j < plen) {
      while (k != -1 && str[k] != str[j]) k = nxt[k];
      nxt[++j] = ++k;
    }
  }
  int Kmp(string &s, string &p) {
    int j = 0, k = 0, ans = 0, slen = (int)s.size(), plen = (int)p.size();
    while (j < slen) {
      while (k != -1 && s[j] != p[k]) k = nxt[k];
      j++;
      k++;
      if (k == plen) {
        ans++;
        k = nxt[k];
      }
    }
    return ans;
  }
} KP;
struct Hld {
  int fa[100035], bigSon[100035], sz[100035], deep[100035], fap[100035][20];
  int head[100035];
  int dfid = 0;
  void calSize(int x, int pa, char fc) {
    sz[x] = 1;
    fa[x] = pa;
    deep[x] = deep[pa] + 1;
    fac[x] = fc;
    fap[x][0] = pa;
    int mx = 0;
    for (auto cp : mp[x])
      if (cp.first != pa) {
        int c = cp.first;
        calSize(c, x, cp.second);
        sz[x] += sz[c];
        if (mx < sz[c]) {
          mx = sz[c];
          bigSon[x] = c;
        }
      }
  }
  void init() {
    for (int j = 1; (1 << j) <= n; j++)
      for (int i = 1; i <= n; i++) fap[i][j] = fap[fap[i][j - 1]][j - 1];
  }
  void build(int x, int H) {
    head[x] = H;
    dfn[x] = ++dfid;
    if (mp[x].size() == 1) {
      vector<int> ins;
      for (int tmp = x;; tmp = fa[tmp]) {
        ins.push_back(tmp);
        if (tmp == H) break;
      }
      reverse(ins.begin(), ins.end());
      int N = ins.size();
      for (int(i) = 0; (i) < (int)(N); (i)++) {
        string x = "";
        for (int j = i; j < min(N, i + 100); j++) {
          x.push_back(fac[ins[j]]);
          if (mpc.find(x) != mpc.end()) {
            spos[mpc[x]].push_back(dfn[ins[i]]);
          }
        }
      }
    }
    if (bigSon[x] != 0) build(bigSon[x], H);
    for (auto c : mp[x])
      if (c.first != fa[x] && c.first != bigSon[x]) {
        build(c.first, c.first);
      }
  }
  int lca(int x, int y) {
    while (head[x] != head[y]) {
      if (deep[head[x]] < deep[head[y]]) {
        swap(x, y);
      }
      x = fa[head[x]];
    }
    return deep[x] < deep[y] ? x : y;
  }
  string apped;
  int TT = 0;
  void up(int x, int ff, string &s, int sn, int sid) {
    while (deep[head[x]] > deep[ff]) {
      int H = head[x];
      TT += qylr(sid, dfn[head[x]], dfn[x] - sn + 1);
      if (sn != 1) {
        int tmp = x;
        for (int i = 18; i >= 0; i--) {
          if (deep[fap[tmp][i]] >= deep[head[x]] + sn - 2) tmp = fap[tmp][i];
        }
        while (deep[tmp] > deep[head[x]] + sn - 2) tmp = fa[tmp];
        int bfLen = deep[tmp] - deep[H] + 1 + sn - 1;
        string S = "";
        while (tmp != ff && S.size() < bfLen) {
          S += fac[tmp];
          tmp = fa[tmp];
        }
        for (int(j) = 0; (j) < (int)(apped.size()); (j)++)
          if (S.size() == bfLen)
            break;
          else
            S += apped[j];
        reverse(S.begin(), S.end());
        TT += KP.Kmp(S, s);
      }
      x = fa[H];
    }
    TT += qylr(sid, dfn[ff] + 1, dfn[x] - sn + 1);
    if (sn <= 1) return;
    int tmp = x;
    for (int i = 18; i >= 0; i--) {
      if (deep[fap[tmp][i]] >= deep[ff] + sn - 1) tmp = fap[tmp][i];
    }
    while (deep[tmp] > deep[ff] + sn - 1) tmp = fa[tmp];
    if (ff == tmp) return;
    int bfLen = deep[tmp] - deep[ff] + sn - 1;
    string S = "";
    while (tmp != ff && S.size() < bfLen) {
      S += fac[tmp];
      tmp = fa[tmp];
    }
    for (int(j) = 0; (j) < (int)(apped.size()); (j)++)
      if (S.size() == bfLen)
        break;
      else
        S += apped[j];
    reverse(S.begin(), S.end());
    TT += KP.Kmp(S, s);
  }
  bool DB = false;
  void down(int x, int ff, string &s, int sn, int sid) {
    while (deep[head[x]] > deep[ff]) {
      int H = head[x];
      if (DB && deep[x] == 128) {
        int tmp = x;
        while (1) {
          cout << dfn[tmp] << " ";
          if (tmp == H) break;
          tmp = fa[tmp];
        }
        cout << endl;
        int id = mpc["qx"];
        cout << spos[id].size() << endl;
        for (int z : spos[id])
          if (z <= dfn[x] && z >= dfn[H]) cout << z << " ";
        exit(0);
      }
      TT += qylr(sid, dfn[head[x]], dfn[x] - (sn - 1));
      if (sn != 1) {
        int tmp = x;
        for (int i = 18; i >= 0; i--) {
          if (deep[fap[tmp][i]] >= deep[head[x]] + sn - 2) tmp = fap[tmp][i];
        }
        while (deep[tmp] > deep[head[x]] + sn - 2) tmp = fa[tmp];
        int bfLen = deep[tmp] - deep[H] + 1 + sn - 1;
        string S = "";
        while (tmp != ff && S.size() < bfLen) {
          S += fac[tmp];
          tmp = fa[tmp];
        }
        reverse(S.begin(), S.end());
        TT += KP.Kmp(S, s);
      }
      x = fa[H];
    }
    TT += qylr(sid, dfn[ff] + 1, dfn[x] - sn + 1);
  }
  void cal(int qid) {
    int x = qs[qid].u, y = qs[qid].v;
    if (x == y) return;
    int ff = lca(x, y);
    apped = "";
    int tmp = y;
    for (int i = 18; i >= 0; i--) {
      if (deep[fap[tmp][i]] >= deep[ff] + 100) tmp = fap[tmp][i];
    }
    while (deep[tmp] > deep[ff]) {
      apped += fac[tmp];
      tmp = fa[tmp];
    }
    reverse(apped.begin(), apped.end());
    TT = 0;
    KP.init(qs[qid].rx);
    up(x, ff, qs[qid].rx, (int)qs[qid].rx.size(), mpc[qs[qid].rx]);
    KP.init(qs[qid].x);
    down(y, ff, qs[qid].x, (int)qs[qid].x.size(), mpc[qs[qid].x]);
    Ans[qs[qid].id] = TT;
    if (DB) exit(0);
  }
} ynk;
void fmain(int tid) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  debug = 0;
  for (int(i) = 0; (i) < (int)(n - 1); (i)++) {
    int u, v;
    char c;
    cin >> u >> v >> c;
    mp[u].push_back({v, c});
    mp[v].push_back({u, c});
  }
  cin >> m;
  for (int(i) = 1; (i) <= (int)(m); (i)++) {
    qs[i].rd(i);
  }
  ynk.calSize(1, 0, ' ');
  ynk.build(1, 1);
  ynk.init();
  for (int(i) = 1; (i) <= (int)(m); (i)++) {
    ynk.cal(i);
    if (debug && i == 10944) {
      cout << qs[i].u << " " << qs[i].v << " " << qs[i].x;
      return;
    }
  }
  for (int(i) = 1; (i) <= (int)(m); (i)++) cout << Ans[i] << endl;
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}

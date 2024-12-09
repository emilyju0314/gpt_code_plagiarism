/* template.cpp {{{ */
#include <bits/stdc++.h>
using namespace std;
#define get_macro(a, b, c, d, name, ...) name
#define rep(...) get_macro(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define rrep(...) get_macro(__VA_ARGS__, rrep4, rrep3, rrep2, rrep1)(__VA_ARGS__)
#define rep1(n) rep2(i_, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) rep4(i, a, b, 1)
#define rep4(i, a, b, s) for (ll i = (a); i < (ll)(b); i += (ll)(s))
#define rrep1(n) rrep2(i_, n)
#define rrep2(i, n) rrep3(i, 0, n)
#define rrep3(i, a, b) rrep4(i, a, b, 1)
#define rrep4(i, a, b, s) for (ll i = (ll)(b) - 1; i >= (ll)(a); i -= (ll)(s))
#define each(x, c) for (auto &&x : c)
#define fs first
#define sc second
#define all(c) begin(c), end(c)
using ui = unsigned;
using ll = long long;
using ul = unsigned long long;
using ld = long double;
const int inf = 1e9 + 10;
const ll inf_ll = 1e18 + 10;
const ll mod = 1e9 + 7;
const ll mod9 = 1e9 + 9;
const int dx[]{-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[]{0, -1, 0, 1, -1, -1, 1, 1};
template<class T, class U> void chmin(T &x, const U &y){ x = min<T>(x, y); }
template<class T, class U> void chmax(T &x, const U &y){ x = max<T>(x, y); }
struct prepare_ { prepare_(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(12); } } prepare__;
/* }}} */

int h, w;
string s[60];
int a[60][10];
bool vis[60][10];

int main(){
  while (cin >> w >> h, h){
    memset(a, -1, sizeof(a));
    rrep(i, h) cin >> s[i];
    int ii = 0;
    rep(i, h) rep(j, w){
      if (s[i][j] == '.') continue;
      char c = s[i][j];
      queue<pair<int, int>> q;
      s[i][j] = '.';
      a[i][j] = ii;
      q.emplace(i, j);
      while (q.size()){
        int x, y;
        tie(x, y) = q.front(), q.pop();
        rep(k, 4){
          int nx = x + dx[k];
          int ny = y + dy[k];
          if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
          if (s[nx][ny] == c){
            s[nx][ny] = '.';
            a[nx][ny] = ii;
            q.emplace(nx, ny);
          }
        }
      }
      ii++;
    }
    bool res = true;
    rep(i, ii){
      memset(vis, 0, sizeof(vis));
      int sx, sy;
      rep(x, h) rep(y, w) if (a[x][y] == i) sx = x, sy = y;
      queue<pair<int, int>> q;
      int sm = sy * 2 + 1, ct = 1;
      vis[sx][sy] = true;
      q.emplace(sx, sy);
      int l = 9999, r = -9999;
      while (q.size()){
        int x, y;
        tie(x, y) = q.front(), q.pop();
        if (a[x][y] == i && (x == 0 || (x > 0 && a[x - 1][y] != -1 && a[x - 1][y] != a[x][y]))) chmin(l, y * 2), chmax(r, (y + 1) * 2);
        rep(j, 4){
          int nx = x + dx[j];
          int ny = y + dy[j];
          if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
          if (a[nx][ny] != a[x][y]) continue;
          if (vis[nx][ny]) continue;
          vis[nx][ny] = true;
          sm += ny * 2 + 1;
          ct++;
          q.emplace(nx, ny);
        }
        int nx = x + 1, ny = y;
        if (nx >= h) continue;
        if (a[nx][ny] == -1) continue;
        if (vis[nx][ny]) continue;
        vis[nx][ny] = true;
        sm += ny * 2 + 1;
        ct++;
        q.emplace(nx, ny);
      }
      //cout << (double)(l) << " " << ((double)(sm) / ct) << " " << (double)(r) << endl;
      if (sm <= l * ct || r * ct <= sm) res = false;
    }
    cout << (res ? "STABLE\n" : "UNSTABLE\n");
  }
}
#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define int ll
using VI = vector<int>;
using VVI = vector<VI>;
using PII = pair<int, int>;

#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
#define PB push_back

const ll LLINF = (1LL<<60);
const int INF = (1LL<<30);
const int MOD = 1000000007;

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
template <typename T> bool IN(T a, T b, T x) { return a<=x&&x<b; }
template<typename T> T ceil(T a, T b) { return a/b + !!(a%b); }
template<class S,class T>
ostream &operator <<(ostream& out,const pair<S,T>& a){
  out<<'('<<a.first<<','<<a.second<<')';
  return out;
}
template<class T>
ostream &operator <<(ostream& out,const vector<T>& a){
  out<<'[';
  REP(i, a.size()) {out<<a[i];if(i!=a.size()-1)out<<',';}
  out<<']';
  return out;
}

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

bool able[21][21][21];
signed main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int cnt = 0;
  while(true) {
    int p, q;
    cin >> p >> q;
    if(!p) break;
    vector<string> s(p), t(q);
    REP(i, p) cin >> s[i];
    REP(i, q) cin >> t[i];

    memset(able, true, sizeof(able));
    map<VI, int> mp;
    int a=0, b=0, c=0;
    REP(i, p-1) {
      // i行目の括弧の数
      REP(j, s[i].size()) {
        if(s[i][j]=='(') {
          a++;
        } else if(s[i][j]=='{') {
          b++;
        } else if(s[i][j]=='[') {
          c++;
        } else if(s[i][j]==')') {
          a--;
        } else if(s[i][j]=='}') {
          b--;
        } else if(s[i][j]==']') {
          c--;
        }
      }
      // i+1行目で行の先頭の'.'の数
      int num = 0;
      REP(j, s[i+1].size()) {
        if(s[i+1][j] != '.') {
          num = j;
          break;
        }
      }
      mp[{a, b, c}] = num;
      // a*R + b*C + c*S = num になるような (R, C, S)
      FOR(R, 1, 21) FOR(C, 1, 21) FOR(S, 1, 21) {
        if(a*R + b*C + c*S != num) {
          able[R][C][S] = false;
        }
      }
    }

    int R=-1, C=-1, S=-1;
    FOR(i, 1, 21) FOR(j, 1, 21) FOR(k, 1, 21) {
      if(able[i][j][k]) {
        if(R == -1) R = i;
        else if(R != i) R = -2;
        if(C == -1) C = j;
        else if(C != j) C = -2;
        if(S == -1) S = k;
        else if(S != k) S = -2;
      }
    }
    // cout << R << "," << C << "," << S << endl;
    // for(auto i: mp) cout << i << endl;

    a = b = c = 0;
    cout << 0;
    cnt++;
    REP(i, q-1) {
      // cout << "i:" << i << endl;
      REP(j, t[i].size()) {
        if(t[i][j]=='(') {
          a++;
        } else if(t[i][j]=='{') {
          b++;
        } else if(t[i][j]=='[') {
          c++;
        } else if(t[i][j]==')') {
          a--;
        } else if(t[i][j]=='}') {
          b--;
        } else if(t[i][j]==']') {
          c--;
        }
      }
      // cout << a << " " << b << " " << c << endl;
      bool flag = true;
      if(a == 0 && b == 0 && c == 0) { cout << " 0"; flag = false; }
      for(auto j: mp) {
        if(!flag) break;
        VI v = j.first;
        if(v[0] > a || v[1] > b || v[2] > c
          || (!v[0] && a) || (!v[1] && b) || (!v[2] && c)) {
          continue;
        }
        bool cond1 = !a || v[0]%a==0,
             cond2 = !b || v[1]%b==0,
             cond3 = !c || v[2]%c==0;
        if(cond1 && cond2 && cond3 && v[0]*b == v[1]*a && v[1]*c == v[2]*b) {
          // cout << v << endl;
          int tmp = -1;
          if(a != 0) tmp = v[0]/a;
          else if(b != 0) tmp = v[1]/b;
          else if(c != 0) tmp = v[2]/c;
          cout << " " << tmp * j.second;
          flag = false;
          break;
        }
      }
      if(!flag) continue;
      if((a && R < 0) || (b && C < 0) || (c && S < 0)) {
        cout << " -1";
      } else {
        cout << " " << a*R + b*C + c*S;
      }
    }
    cout << endl;
  }

  return 0;
}


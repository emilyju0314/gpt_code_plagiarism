#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <climits>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <bitset>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define chmax(a,b) (a<b?(a=b,1):0)
#define chmin(a,b) (a>b?(a=b,1):0)
#define valid(y,x,h,w) (0<=y&&y<h&&0<=x&&x<w)
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1<<29;
const double PI = acos(-1);
const double EPS = 1e-8;

const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};

template <class T>
struct dice {
  T t,b,n,s,e,w;              // top bottom north south east west
  int x, y;
  dice() {t=' ';}
  dice(int y, int x) : y(y),x(x) {
    t=0,b=1,n=2,s=3,e=4,w=5;
  }
  dice(T t, T b, T n, T s, T e, T w) : t(t),b(b),n(n),s(s),e(e),w(w) {}
  void roll(T &a, T &b, T &c, T &d) { swap(a,b); swap(b,c); swap(c,d); }
  void roll_x() { roll(t, n, b, s); }
  void roll_y() { roll(t, w, b, e); }
  void roll_z() { roll(s, e, n, w); }
  vector<dice> all_rolls() {
    vector<dice> ret;
    for (int k=0; k<6; (k&1?roll_y():roll_x()),++k)
      for (int i=0; i<4; roll_z(), ++i)
        ret.push_back(*this);
    return ret;
  }
  void roll(int d) {
    if (d == 0) roll(t, s, b, n);
    else if (d == 1) roll(t, w, b, e);
    else if (d == 2) roll(t, n, b, s);
    else roll(t, e, b, w);
    x+=dx[d];
    y+=dy[d];
  }
  void toTable(T *res) {
    res[0]=t;res[1]=b;res[2]=n;
    res[3]=s;res[4]=e;res[5]=w;
  }
};

typedef dice<char> Dice;

Dice di[8][24];
Dice cube[2][2][2];

int posx[8] = {0,1,0,1,0,1,0,1};
int posy[8] = {0,0,1,1,0,0,1,1};
int posz[8] = {0,0,0,0,1,1,1,1};

const int dx3[6] = {0,0,-1,1,0,0};
const int dy3[6] = {0,0,0,0,1,-1};
const int dz3[6] = {1,-1,0,0,0,0};

bool check(int x, int y, int z, vector<char> &v) {
  char table[6];
  cube[x][y][z].toTable(table);

  // if (x==1) {
  //   cout << " ";
  //   REP(i,6) cout << table[i] << ","; cout << endl;
  // }

  REP(i,6) {
    int xx=x+dx3[i];
    int yy=y+dy3[i];
    int zz=z+dz3[i];
    int p = -1;
    if (xx<0) p=0;
    else if (xx>=2) p=1;
    else if (yy<0) p=2;
    else if (yy>=2) p=3;
    else if (zz<0) p=4;
    else if (zz>=2) p=5;

    // if (x==1) {
    //   if (p>=0) cout << v[p] << " ";
    //   cout << p << " " << table[i] << endl;
    // }

    if (p==-1 ^ table[i]=='#') return 0;                 // 内側は必ず黒．外側は黒以外
    if (p!=-1 && v[p]!='.'&& v[p]!=table[i]) return 0; // 外側の色
    if (p>=0) v[p] = table[i];
  }
  return 1;
}

bool solve(int cnt, int S, vector<char> v) {
  // cout << cnt << endl;
  // FOR(it, v) cout << *it; cout << endl;
  if (cnt == 8) {
    set<char> st;
    FOR(it, v) st.insert(*it);
    return st.size() == 6;
  }

  REP(i,8) {
    if (S>>i&1) continue;
    REP(j,24) {
      int x = posx[cnt];
      int y = posy[cnt];
      int z = posz[cnt];
      cube[x][y][z] = di[i][j];
      vector<char> nxt(v);
      if (!check(x,y,z,nxt)) continue;
      // cout << i << " " << j << endl;
      if (solve(cnt+1, S|1<<i, nxt)) return 1;
    }
  }
  return 0;
}


bool visited[50][50];
char c[50][50];

int main() {
  int h,w;
  cin >> h >> w;
  REP(i,h)REP(j,w)cin>>c[i][j];
  char array[8][6];
  int num = 0;
  REP(i,h)REP(j,w)if(c[i][j]!='.'&&!visited[i][j]) {
    queue<Dice> Q;
    Q.push(Dice(i,j));
    visited[i][j] = 1;
    while(!Q.empty()) {
      Dice now = Q.front(); Q.pop();
      array[num][now.b] = c[now.y][now.x];
      REP(k,4) {
        int y=now.y+dy[k];
        int x=now.x+dx[k];
        if (!valid(y,x,h,w)) continue;
        if (c[y][x] == '.') continue;
        if (!visited[y][x]) {
          visited[y][x] = 1;
          Dice nxt = now;
          nxt.roll(k);
          Q.push(nxt);
        }
      }
    }
    num++;
  }
  assert(num == 8);
  REP(i,num) {
    // REP(j,6) cout << array[i][j] << " "; cout << endl;
    char *a = array[i];
    Dice tmp(a[0],a[1],a[2],a[3],a[4],a[5]);
    vector<Dice> V = tmp.all_rolls();
    REP(j,V.size()) {
      di[i][j] = V[j];
    }
  }
  vector<char> v(6,'.');
  cout << (solve(0,0,v)?"Yes":"No") << endl;
}
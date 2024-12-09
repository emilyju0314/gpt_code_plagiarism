#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

#define all(v) (v).begin(), (v).end()
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,b) FOR(i,0,b)
#define reps FOR
#define eb emplace_back
#define pb eb

template<class T> inline bool MX(T &l, const T &r) { return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l, const T &r) { return l>r?l=r,1:0;}

using LL = long long;
using pii = pair<int, int>;
using pll = pair<LL, LL>;

int N;
int M;
int mpy[514];
int mpx[514];
int ans[514][514];

void Ground(int s, int t, int y, int x, int b, int rot) {
  rep(k, rot) { 
    rep(i, 2) {
      rep(j, 2) {
        int ny[] = {1, 0, 1, 0};
        int nx[] = {0, 0, 1, 1};
        int idx = i*2 + j;
        ans[y*2+ny[idx]][x*2+nx[idx]] = ans[s*2+i][t*2+j];
      }
    }
  }
  
  rep(i, 2) {
    if (b >> i & 1) {
      swap(ans[y*2+i][x*2], ans[y*2+i][x*2+1]);
    }
  }
}

void Try(int idx, int st, int y, int x) {
  assert(x == mpy[y]);
  pii p(-1, -1);
  int fy = y;
  int i = 0;
  while (1) {
    int b = 0;
    if (i < 16) {
      b = st >> (2*i) & 3;
    }
    if (p.X != -1) assert(p == pii(y, y));
    bool upper = x < y;
    Ground(y, x, x, mpy[x], b, upper?3:1);
    if (fy == x) break;
    p = pii(x, x);
    tie(y, x) = pii(x, mpy[x]);
    ++i;
  }
}

void Construct(int idx) {
  int y = 0;
  int x = idx;
  rep(i, M) {
    mpy[y] = x;
    mpx[x] = y;
    y++;
    x++;
    y %= M;
    x %= M;
  }

  rep(y, M) {
    int x = mpy[y];
    if (ans[y*2][x*2]) continue;
  
    int lim = 256;
    rep(st, lim) {
      rep(i, 2) {
        rep(j, 2) {
          ans[y*2+i][x*2+j] = 4*idx+i*2+j;
        }
      }
      
      Try(idx, st, y, x);

      int cnt = 0;
      rep(i, 2) {
        rep(j, 2) {
          cnt += (ans[y*2+i][x*2+j] == 4*idx+i*2+j);
        }
      }
      if (cnt == 4) goto L_FOUND;
    }
    assert(0);
L_FOUND:
    continue;
  }
}

int main() {
  cin >> N;
  if (N == 1) {
    cout << "Yes" << endl;
    cout << "1" << endl;
    return 0;
  }

  if (N%2) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;

  M = N/2;
  rep(i, M) {
    rep(j, 2) {
      ans[i*2+j][i*2+j] = 1;
    }
    ans[i*2][i*2+1] = 2;
    ans[i*2+1][i*2] = 3;
  }

  reps(i, 1, M) {
    Construct(i);
  }
  rep(i, N) {
    rep(j, N) {
      if (j) cout << " ";
      cout << ans[i][j];
    }
    cout << endl;
  }
}


#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<cstdio>
#include<climits>
#include<cmath>
#include<cstring>
#include<string>
#include<sstream>
#include<numeric>
#include<cassert>

#define f first
#define s second
#define mp make_pair

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define rep(i,s,n) for(int i=(s); i<(int)(n); i++)
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define ALL(c) (c).begin(), (c).end()
#define IN(x,s,g) ((x) >= (s) && (x) < (g))
#define ISIN(x,y,w,h) (IN((x),0,(w)) && IN((y),0,(h)))
#define print(x) printf("%d\n",x)

using namespace std;

typedef unsigned int uint;
typedef long long ll;

const int _dx[] = {0,1,0,-1};
const int _dy[] = {-1,0,1,0};

int getInt(){
  int ret = 0,c;
  c = getchar();
  while(!isdigit(c)) c = getchar();
  while(isdigit(c)){
    ret *= 10;
    ret += c - '0';
    c = getchar();
  }
  return ret;
}

bool f[7][7];
bool tmp[7][7];
int sum;
int xs, ys;
int w, h;

void check(int y, int x){
  REP(i, 4){
    int yy = y + _dy[i];
    int xx = x + _dx[i];
    if(ISIN(xx, yy, w, h) && tmp[yy][xx]){
      tmp[yy][xx] = false;
      check(yy, xx);
    }
  }
}

bool solve(int y, int x, int cnt){
  if(cnt != 2 && cnt != sum){
    if(abs(y - ys) + abs(x - xs) == 1)
      return false;
  }

  bool ret = false;
  f[y][x] = false;

  if(sum == cnt){
    if(abs(y - ys) + abs(x - xs) == 1)
      ret = true;
  }else{
    /* check */
    memcpy(tmp, f, sizeof(tmp));
    //REP(i, h) REP(j, w) tmp[i][j] = f[i][j];
    check(y, x);
    bool ok = true;
    REP(i, h) REP(j, w) if(tmp[i][j]) ok = false;

    if(ok){
      REP(i, 4){
        int yy = y + _dy[i];
        int xx = x + _dx[i];

        if(ISIN(xx, yy, w, h) && f[yy][xx]){
          if(solve(yy, xx, cnt+1)){
            ret = true;
            break;
          }
        }
      }
    }
  }

  f[y][x] = true;
  return ret;
}

int main(){
  while(true){
    w = getInt();
    h = getInt();

    bool ans = false;

    if(w + h == 0) break;

    xs = ys = -1;
    sum = 0;

    REP(i,h) REP(j,w){
      f[i][j] = getInt() == 0 ? true : false;
      if(f[i][j]) sum++;
      if(ys == -1 && f[i][j]){
        ys = i; xs = j;
      }
    }

    if(h == 7 && w == 7 && sum == 7 * 7) ans = false;
    else if(h == 7 && w == 7 && sum == 7 * 7 - 1){
      REP(i,h) REP(j,w) if(!f[i][j]){
        if((i + j) % 2 == 0) ans = true;
        else ans = false;
      }
    }
    else if(ys != -1) ans = solve(ys, xs, 1);

    puts(ans ? "Yes" : "No");
  }
  return 0;
}
#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

struct data {
  int x,h;
  data(){}
  data(int x,int h):x(x),h(h){}
  bool operator<(const data& e)const {
    if( h != e.h ) return h < e.h;
    return x < e.x;
  }
};

int n;
data a[55];
int dp[5][55];
int ma;

// kosu,bango
int solve(int p,int q)
{
  int s,t;
  ma = max(ma,q);
  if( q == n ) return a[q-1].x;
  if( dp[p][q] >= 0 ) return dp[p][q];
  s = 100*50000*3+100000;
  t = 100*50000*3+100000;
  if( (a[q].h-a[q-1].h) >= a[q].x+(p+1)*a[q-1].x ) {
    s = solve(1,q+1)+a[q].x+a[q-1].x;
    //if( q == 1 ) printf(";;%d\n",a[q].x+a[q-1].x);
  }
  if( p < 3 ) {
    //printf("::%d %d\n",a[q].h-a[q-1].h,abs(a[q-1].x-a[q].x)*(p+1));
    if( (a[q].h-a[q-1].h) >= abs(a[q-1].x-a[q].x)*(p+1) ) {
      t = solve(p+1,q+1)+abs(a[q-1].x-a[q].x);
      //printf("%d %d::%d\n",p,q,t);
    }
  }
  return dp[p][q] = min(s,t);
}

int main(void)
{
  int res;
  for(;;) {
    scanf("%d",&n); if(!n) break;
    memset(dp,-1,sizeof(dp));
    for( int i = 1; i <= n; i++ ) {
      scanf("%d%d",&a[i].x,&a[i].h);
    }
    ++n;
    ma = 0;
    a[0].x = 0;
    a[0].h = 0;
    sort(a,a+n);
    /*
    for( int i = 0; i < n; i++ ) {
      printf("%d %d\n",a[i].x,a[i].h);
    }
    */
    res = solve(0,1);
    if( ma != n ) {
      printf("NG %d\n",ma);
    } else {
      printf("OK %d\n",res);
    }
  }
  return 0;
}
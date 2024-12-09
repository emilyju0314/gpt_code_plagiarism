#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <sstream>
#include <cassert>
#include <list>
#include <ctime>
#include <numeric>
using namespace std;
static const double EPS = 1e-6;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PI;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define SZ(a) (int(a.size()))
#define F first
#define S second
const double pi=acos(-1);
int dx[]={0,1,0,-1,1,1,-1,-1},dy[]={1,0,-1,0,1,-1,1,-1};

PI lastr[50000],lastc[50000];

int main(){
  int r,c,q;
  while(cin>>r>>c>>q,r){
    memset(lastr,0,sizeof(lastr));
    memset(lastc,0,sizeof(lastc));
    rep(i,q){
      int a,b,o;
      cin>>a>>b>>o;
      if(a)lastc[b]=mp(o,i+1);
      else lastr[b]=mp(o,i+1);
    }


    //rep(i,r)cout<<'('<<lastr[i].F<<','<<lastr[i].S<<") ";cout<<endl;
    //rep(i,c)cout<<'('<<lastc[i].F<<','<<lastc[i].S<<") ";cout<<endl;
    vector<int> rs,rd;
    rep(i,r){
      if(lastr[i].F)rs.pb(lastr[i].S);
      else rd.pb(lastr[i].S);
    }
    sort(ALL(rs));
    sort(ALL(rd));
    ll ans=0;
    rep(i,c){
      if(lastc[i].F){
        ans+=SZ(rs);
        if(SZ(rd) && rd[0]<lastc[i].S)
          ans+=distance(rd.begin(),lower_bound(ALL(rd),lastc[i].S));
      }else if(lastc[i].S==0){
        ans+=SZ(rs);
      }else{
        if(SZ(rs) && rs.back()>lastc[i].S){
          ans+=SZ(rs)-distance(rs.begin(),lower_bound(ALL(rs),lastc[i].S));
        }
      }
      //cout<<ans<<' ';
    }
    cout<<ans<<endl;
  }
}
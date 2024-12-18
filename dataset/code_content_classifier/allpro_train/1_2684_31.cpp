#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>

#define REP(i,n) for(long long i=0;i<n;++i)
#define REPR(i,n) for(long long i=n;i>=0;--i)
#define REPI(itr,v) for(auto itr=v.begin();itr!=v.end();++itr)
#define REPIR(itr,v) for(auto itr=v.rbegin();itr!=v.rend();++itr)
#define FOR(i,a,b) for(long long i=a;i<b;++i)
#define SORT(v,n) sort(v, v+n)
#define SORTV(v) sort(v.begin(), v.end())
#define ALL(v) v.begin(),v.end()
#define llong long long
#define INF 999999999
#define MOD 1000000007
#define pb push_back
#define pf push_front
#define MP make_pair
#define SV(v) {for(long long sitr=0;sitr<v.size();++sitr){cin>>v[sitr];}}

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

using namespace std;

typedef pair<int,int> pii;

int main(){

  int h, w;
  cin >> h >> w;

  vector<string> s(h);
  REP(i,h){
    cin >> s[i];
  }

  vector<pii> v;
  
  for(int i = 0; i < h; ++i){
    REP(j,w){
      if(s[i][j] == 'B'){
        v.pb(MP(i, j));
        break;
      }
    }
    for(int j = w - 1; j >= 0; --j){
      if(s[i][j] == 'B'){
        v.pb(MP(i, j));
        break;
      }
    }
  }

  for(int j = 0; j < w; ++j){
    REP(i,h){
      if(s[i][j] == 'B'){
        v.pb(MP(i, j));
        break;
      }
    }
    for(int i = h - 1; i >= 0; --i){
      if(s[i][j] == 'B'){
        v.pb(MP(i, j));
        break;
      }
    }
  }

 
  int ans = 0;
  REPI(itr1, v){
    REPI(itr2, v){
      ans = max(ans, abs(itr1->first - itr2->first) + abs(itr1->second - itr2->second));
    }
  }

  cout << ans << endl;

  return 0;
}



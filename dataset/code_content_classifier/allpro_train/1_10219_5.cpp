#include <algorithm>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
 
using namespace std;
 
typedef long long ll;
 
#define sz size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(c) (c).begin(), (c).end()
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define per(i,a,b) for(ll i=b-1LL;i>=(a);--i)
#define clr(a, b) memset((a), (b) ,sizeof(a))
#define ctos(c) string(1,c)
#define print(x) cout<<#x<<" = "<<x<<endl;
 
#define MOD 1000000007

ll da[500100];
ll db[500100];

int main() {
  clr(da,-1);
  clr(db,-1);
  string a,b;
  cin>>a>>b;
  ll index = 0;
  rep(i,0,a.sz){
    if(a[i]==b[index]){
      da[i] = index;
      index++;
    }
  }
  index = b.sz-1;
  per(i,0,a.sz){
    if(a[i]==b[index]){
      db[i] = index;
      index--;
    }
  }
  ll flag = 1;
  rep(i,0,500100){
    if(da[i]!=db[i])flag = 0;
  }
  if(flag==1){
    cout << "yes" << endl;
  }
  else{
    cout << "no" << endl;
  }
  return 0;
}
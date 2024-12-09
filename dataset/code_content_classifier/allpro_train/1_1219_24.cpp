#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

ll M;
int N;
string C;

ll val[10];

void add(ll &a,ll b){
  a=(a+b)%MOD;
}

int main(){
  cin>>M;
  cin>>C;
  N=C.size();

  vector<int> v;
  for(int i=0;i<=9;i++) v.push_back(i);

  ll ten=1;
  for(int i=N-1;i>=0;i--){
    add(val[C[i]-'0'],ten);
    ten=ten*10%MOD;
  }

  do{
    if(v[C[0]-'0']==0&&N>1) continue;
    ll res=0;
    for(int j=0;j<=9;j++){
      ll c=v[j]*val[j]%MOD;
      add(res,c);
    }
    res=(res+MOD)%MOD;
    if(res==M){
      string ans="";
      for(int i=0;i<N;i++) ans+=char(v[C[i]-'0']+'0');
      cout<<ans<<endl;
      return 0;
    }
  }while(next_permutation(v.begin(),v.end()));

  cout<<-1<<endl;

  return 0;
}


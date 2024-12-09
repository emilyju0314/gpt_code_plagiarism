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
using namespace std;
static const double EPS = 1e-5;
typedef long long ll;
typedef pair<int,int> PI;
typedef vector<int> vi;
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define F first
#define S second
 
 
int main(){
  int n;
  while(cin>>n,n){
    int m;
    cin>>m;
    m--;
    int hit;
    cin>>hit;
    hit--;

    int d;
    cin>>d;
    string sen[d];
    rep(i,d)cin>>sen[i];

    int ans=-1;

    int dan=0,hon=m;
    while(dan<d){
      if(hon && sen[dan][hon-1]=='1'){
	hon--;
      }else if(hon+1<n && sen[dan][hon]=='1')++hon;
      ++dan;
      //cout<<dan<<" "<<hon<<endl;
    }
    if(hon==hit){
      cout<<0<<endl;
      continue;
    }

    rep(i,d){
      rep(j,n-1){
	if(sen[i][j]=='1')continue;
	if(j && sen[i][j-1]=='1')continue;
	if(j+2<n && sen[i][j+1]=='1')continue;
	sen[i][j]='1';
	dan=0,hon=m;
	while(dan<d){
	  if(hon && sen[dan][hon-1]=='1'){
	    hon--;
	  }else if(hon+1<n && sen[dan][hon]=='1')++hon;
	  ++dan;
	}
	sen[i][j]='0';
	if(hon==hit){
	  cout<<i+1<<" "<<j+1<<endl;
	  goto NEXT;
	}
      }
    }
    cout<<1<<endl;
  NEXT:;
  }
}
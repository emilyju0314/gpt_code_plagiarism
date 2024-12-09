#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

typedef long long ll;
const ll INF=(1LL<<50);

ll DecToBaseNum(ll num,int base){
  string s;
  ll res=0;
  while(num){
    stringstream ss;
    ss<<(num%base);
    if(num%base>9)return -1;
    s=ss.str()+s;
    num/=base;
  }
  for(int i=0;i<s.size();i++)res=res*10+(s[i]-'0');
  return res;
}

ll A,B,C;
int main(){
  while(cin>>A>>B>>C&&!(A==-1&&B==-1&&C==-1)){
    bool ok=false;
    for(int i=2;i<=16;i++){
      ll a=DecToBaseNum(A,i);
      if(a==B){
	ok=true;
	break;
      }
    }
    if(!ok)cout<<-1<<endl;
    else{
      ll cur=B;
      ok=true;
      for(int i=A+1;i<=C;i++){
	ll nxt=INF;
	for(int j=2;j<=16;j++){
	  ll a=DecToBaseNum(i,j);
	  if(a>=cur&&nxt>a)nxt=a;
	}
	if(nxt==INF){
	  ok=false;
	  break;
	}
	cur=nxt;
      }
      if(!ok)cout<<-1<<endl;
      else cout<<cur<<endl;
    }
  }
  return 0;
}
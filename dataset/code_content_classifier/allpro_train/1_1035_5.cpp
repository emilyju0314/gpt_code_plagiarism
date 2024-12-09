#include<iostream>
#include<vector>
#include<set>
#include<cassert>
#include<cmath>
using namespace std;
typedef long long lint;
typedef vector<int>vi;
typedef pair<lint,lint>pll;
typedef pair<pll,lint>pplll;

pll fundamental_unit(lint d){
  vi ans;
  lint x=0,z=1;//(x+y*sqrt(d))/z
  lint sqrtd=floor(sqrt(d));
  set<pll>seen;
  while(1){
    if(seen.count(pll(x,z)))break;
    seen.insert(pll(x,z));
    lint q=((x+sqrtd)/z);
    if(0){
      cerr<<"x,z=("<<x<<"+sqrt(d))/"<<z<<endl;
      cerr<<"q="<<q<<endl;
    }
    ans.push_back(q);
    x-=q*z;
    lint norm=x*x-d;
    x=-x;
    z=-norm/z;
  }
  // recover
  lint num=0,den=1;
  for(int i=(int)ans.size()-2;i>=0;--i){
    lint z=num+ans[i]*den;
    num=den;den=z;
  }
  if(den*den-d*num*num==-1){
    lint x=den*den+d*num*num;
    lint y=2*den*num;
    den=x;num=y;
  }
  assert(den*den-d*num*num==1);
  return pll(den,num);
}

pll solve(lint n){
  for(int i=0;i<=200;++i)
    if(i*i==2*n)
      return pll(i,1);
  return fundamental_unit(2*n);
}

int main(){
  for(int t=1;;++t){
    lint n;
    cin>>n;
    if(n==0)break;
    pll ans=solve(n);
    cout<<"Case "<<t<<": "<<ans.first<<" "<<ans.second<<endl;
  }
}


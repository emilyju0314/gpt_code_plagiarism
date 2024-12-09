#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
typedef long long lint;
typedef vector<int>vi;
typedef pair<int,int>pii;
typedef pair<lint,lint>pll;
#define rep(i,n)for(int i=0;i<(int)(n);++i)

const int DEBUG=0;


const int N=62;
const lint inf=1LL<<61;
pll dpa[N],dpb[N];

pll mul(pll a,lint b){
  return pll(a.first*b,a.second+1);
}

pll rev(pll a){
  return pll(a.first,-a.second);
}

const int PUL=0;


int main(){
  int n;
  cin>>n;
  vector<lint>a(n);
  if(PUL){
    rep(i,n)a[i]=-2;
  }else{
    rep(i,n)cin>>a[i];
  }
  rep(i,N){
    dpa[i]=pll(-inf,1);
    dpb[i]=pll(inf,-1);
  }
  dpa[n]=dpb[n]=pll(1,0);
  for(int i=n-1;i>=0;--i){
    for(int j=i+1;j<=n;++j){
      dpa[i]=max(dpa[i],max(rev(mul(rev(dpa[j]),a[i])),rev(mul(dpb[j],a[i]))));
      dpb[i]=min(dpb[i],min(mul(rev(dpa[j]),a[i]),mul(dpb[j],a[i])));
    }
    if(DEBUG){
      cerr<<"dpa["<<i<<"]="<<dpa[i].first<<" "<<dpa[i].second<<endl;
      cerr<<"dpb["<<i<<"]="<<dpb[i].first<<" "<<dpb[i].second<<endl;
    }
  }
  pll ma=pll(-inf,1);
  rep(i,n+1)ma=max(ma,dpa[i]);
  pll idx(inf,inf);
  rep(i,n+1){
    if(ma.first==dpa[i].first){
      idx=min(idx,pll(-dpa[i].second,i));
    }
  }
  int cur=idx.second;
  int rem=-ma.second;
  pll val=rev(ma);
  vi ans;
  while(rem>0){
    if(DEBUG){
      cerr<<"cur="<<cur<<endl;
      cerr<<"rem="<<rem<<endl;
      cerr<<"val="<<val.first<<" "<<val.second<<endl;
    }
    int nxt=-1;
    for(int j=cur+1;j<=n;++j){
      if(mul(dpb[j],a[cur])==val){
	nxt=j;
	val=dpb[j];
	break;
      }
      if(mul(rev(dpa[j]),a[cur])==val){
	nxt=j;
	val=rev(dpa[j]);
	break;
      }
    }
    ans.push_back(cur);
    cur=nxt;
    rem--;
  }
  cout<<ans.size()<<endl;
  rep(i,ans.size()){
    cout<<ans[i]+1<<endl;
  }
}


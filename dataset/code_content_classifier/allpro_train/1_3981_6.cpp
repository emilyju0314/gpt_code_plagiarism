#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

signed main(){  
  cin.tie(0);
  ios::sync_with_stdio(0);
  Int n;
  string a,b;
  cin>>n>>a>>b;
  if(a.size()<b.size()) a=string(b.size()-a.size(),'0')+a;
  if(a.size()>b.size()) b=string(a.size()-b.size(),'0')+b;

  const Int l=a.size();

  
  const Int BS = 600;
  vector<Int> cnt(l/BS+1,0),sft(l/BS+1,0);
  auto calc=[&](Int x){
    Int y=x*BS;
    cnt[x]=0;
    sft[x]=-l*2;
    for(Int i=0;i<BS;i++){
      if(y+i>=l) break;
      if(b[y+i]=='1') chmax(sft[x],cnt[x]+(a[y+i]=='1')+l-(y+i+1));
      cnt[x]+=a[y+i]=='1'||b[y+i]=='1';
    }
    //cout<<x<<":"<<cnt[x]<<" "<<sft[x]<<endl;
  };
  
  for(Int i=0;i<l;i+=BS) calc(i/BS);
  
  Int ans=0;
  auto recalc=[&](){
    ans=0;
    Int tmp=0;
    for(Int i=0;i<l;i+=BS){
      Int x=i/BS;
      chmax(ans,tmp+sft[x]);
      tmp+=cnt[x];
    }
  };
  
  for(Int i=0;i<n;i++){
    char c;
    cin>>c;
    if(c=='Q'){
      recalc();
      cout<<ans<<endl;
      continue;
    }
    Int p;
    cin>>p;
    p++;
    if(c=='A') a[l-p]=!(a[l-p]-'0')+'0';
    if(c=='B') b[l-p]=!(b[l-p]-'0')+'0';

    calc((l-p)/BS);
  }
  
  return 0;
}


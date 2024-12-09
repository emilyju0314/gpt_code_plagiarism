#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
const Int MAX = 305;
const Int MAX2 = MAX*2;
signed ex[MAX2][MAX2];
signed dp[MAX2+2][MAX2+2];
signed main(){
  Int h,w;
  cin>>h>>w;
  vector<string> s(h);
  for(Int i=0;i<h;i++) cin>>s[i];

  using P = pair<Int, Int>;
  vector<P> vp;
  memset(ex,0,sizeof(ex));
  for(Int i=0;i<h;i++){
    for(Int j=0;j<w;j++){
      if(s[i][j]!='#') continue;
      vp.emplace_back(1+i+j,1+i-j+w);
      ex[1+i+j][1+i-j+w]=1;      
    }
  }
  
  auto ch=
    [&](Int i,Int j)->Int{
      if(i<0||i>=MAX2) return 0;
      if(j<0||j>=MAX2) return 0;
      return ex[i][j];
    };
  
  const Int LIM = h+w;
  Int ans=0;
  for(Int k=1;k<=LIM;k++){
    for(Int i=0;i<MAX2;i++)
      for(Int j=1;j<MAX2;j++)
        dp[i][j+1]=dp[i][j]+(ch(i,j)&&ch(i,j-k));

    for(P p:vp){
      Int i,j;
      tie(i,j)=p;
      if(i-k>=0)  ans+=dp[i-k][min(MAX2-1,j+k+1)]-dp[i-k][j];
      if(i+k<MAX2) ans+=dp[i+k][min(MAX2-1,j+k+1)]-dp[i+k][j];
    }

    for(Int j=0;j<MAX2;j++)
      for(Int i=0;i<MAX2;i++)
        dp[j][i+1]=dp[j][i]+(ch(i,j)&&ch(i-k,j));
    
    for(P p:vp){
      Int i,j;
      tie(i,j)=p;
      if(j-k>=0)  ans+=dp[j-k][min(MAX2-1,i+k+1)]-dp[j-k][i];
      if(j+k<MAX2) ans+=dp[j+k][min(MAX2-1,i+k+1)]-dp[j+k][i];   
    }            
  }

  //cout<<ans<<endl;
  for(P p:vp){
    Int i,j;
    tie(i,j)=p;
    for(Int k=1;k<=LIM;k++){
      if(ch(i+k,j)&&ch(i,j+k)) ans--;
      if(ch(i+k,j)&&ch(i,j-k)) ans--;
      if(ch(i-k,j)&&ch(i,j+k)) ans--;
      if(ch(i-k,j)&&ch(i,j-k)) ans--;
    }
  }
  cout<<ans<<endl;
  return 0;
}

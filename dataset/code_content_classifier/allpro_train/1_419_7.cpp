#include<bits/stdc++.h>
using namespace std;
using Int = long long;

template<typename T1,typename T2> void chmin(T1 &a,T2 b){if(a>b) a=b;};
template<typename T1,typename T2> void chmax(T1 &a,T2 b){if(a<b) a=b;};

const Int MAX = 114514;
Int dp[3][3][10][MAX];
signed main(){
  Int n;
  while(cin>>n,n){
    memset(dp,0,sizeof(dp));
    if(n&1){
      dp[1][1][1][1]=1;
      dp[0][0][0][1]=1;
      for(Int i=1;i<n;i++){
	for(Int j=0;j<2;j++){
	  for(Int k=0;k<2;k++){
	    for(Int l=0;l<=8;l++){
	      dp[j][0][l][i+1]+=dp[j][k][l][i];
	      if(!k) dp[j][1][l+1][i+1]+=dp[j][k][l][i];
	    }
	  }
	}
      }
      Int ans=0;
      for(Int j=0;j<2;j++)
	for(Int k=0;k<2;k++)
	  if(!j||!k) ans+=dp[j][k][8][n];
      for(Int i=1;i<=8;i++) ans*=i;
      cout<<ans<<endl;
    }else{      
      dp[1][1][1][1]=1;
      dp[2][2][1][1]=1;
      dp[0][0][0][1]=1;
      for(Int i=1;i<n/2;i++){
	for(Int j=0;j<3;j++){
	  for(Int k=0;k<3;k++){
	    for(Int l=0;l<=8;l++){
	      dp[j][0][l][i+1]+=dp[j][k][l][i];
	      for(Int nk=1;nk<3;nk++)
		if(k!=nk) dp[j][nk][l+1][i+1]+=dp[j][k][l][i];
	    }
	  }
	}
      }
      Int ans=0;
      for(Int j=0;j<3;j++)
	for(Int k=0;k<3;k++)
	  if(j+k!=3) ans+=dp[j][k][8][n/2];      
      for(Int i=1;i<=8;i++) ans*=i;
      cout<<ans<<endl;
    }
  }
  return 0;
}
 



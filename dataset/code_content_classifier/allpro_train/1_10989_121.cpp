#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int N;

int dp[2][101][100050];

const int INF=1e9;

void chmin(int &a,int b){
    if(a>b) a=b;
}

void solve(){
    vector<int> P(N);
    for(int i=0;i<N;i++) cin>>P[i];

    for(int i=0;i<2;i++){
        for(int j=0;j<=N;j++){
            for(int k=0;k<=1000*N;k++){
                dp[i][j][k]=INF;
            }
        }
    }

    dp[0][0][0]=0;
    int t=0;
    int rest=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            for(int k=0;k<=rest;k++){
                if(dp[t][j][k]==INF) continue;

                chmin(dp[1-t][j][k],dp[t][j][k]);

                int thousand=(1000-P[i]%1000)%1000;
                rest=max(rest,k+thousand);
                if(thousand>=500) chmin(dp[1-t][j+1][k+thousand-500],dp[t][j][k]+P[i]);
                else chmin(dp[1-t][j][k+thousand],dp[t][j][k]+P[i]);

                int z=0;
                if(thousand==0) z=500;
                else if(thousand<500) z=500-thousand;
                if(z==0) continue;
                if(z>k) continue;

                chmin(dp[1-t][j+1][k-z],dp[t][j][k]+P[i]);
            }
        }

        for(int j=0;j<=i;j++){
            for(int k=0;k<=rest;k++){
                dp[t][j][k]=INF;
            }
        }
        t=1-t;
    }

    int ma=0,mi=INF;
    for(int j=N;j>=0;j--){
        for(int k=0;k<=1000*N;k++){
            if(dp[t][j][k]==INF) continue;
            ma=j;
            mi=min(mi,dp[t][j][k]);
        }
        if(ma>0) break;
    }
    cout<<ma<<" "<<mi<<endl;
}

int main(){
  while(1){
      cin>>N;
      if(N==0) break;
      solve();
  }

  return 0;
}


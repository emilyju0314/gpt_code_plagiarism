#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll dp[2010][2010];
ll a[2010];
//ll cnt;
ll solve(int n,int l){
//cnt++;
if(n==l+1)return dp[n][l]=0;
if(dp[n][l]>-1)return dp[n][l];
ll ans=a[n-1]-a[l];
return dp[n][l]=ans+min(solve(n,l+1),solve(n-1,l));
}

int main()
{
        int n;
        cin>>n;
        for(int i=0;i<n;i++){cin>>a[i];
        }

        for(int i=0;i<n+2;i++){
            for(int j=0;j<n+2;j++)dp[i][j]=-1;
        }


        sort(a,a+n);
        solve(n,0);
        cout<<dp[n][0]<<endl;
//cout<<cnt;
    return 0;
}

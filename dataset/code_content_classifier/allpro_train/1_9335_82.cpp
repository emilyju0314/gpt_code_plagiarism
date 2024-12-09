#include<bits/stdc++.h>
#define ll long long
#define N 310
using namespace std;
ll C[N][N],f[N][N],s[N][N];
int n,K,mod;
int main(){
    scanf("%d%d%d",&n,&K,&mod); 
    C[0][0]=1;for(int i=1;i<=n;C[i][0]=1,i++)for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    for(int j=0;j<=K;j++)f[1][j]=1,s[1][j]=K-j+1;
    for(int i=2;i<=n+1;i++){
        for(int j=0;j<=K;j++)for(int k=1;k<i;k++)f[i][j]=(f[i][j]+f[i-k][j]*s[k][j+1]%mod*C[i-2][k-1])%mod;  
        for(int j=K;j>=0;j--)s[i][j]=(f[i][j]+s[i][j+1])%mod;
    }
    printf("%lld",f[n+1][0]);           
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;

int c[2001][2001];

int main(){
    c[0][0]=1;
    for(int i=1;i<=2000;i++){
        for(int j=0;j<=i;j++){
            if(j==0)c[i][j]=1;
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
        }
    }
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        if(n-k<i-1)cout<<0<<endl;
        else cout<<((ll)c[k-1][i-1]*c[n-k+1][i])%MOD<<endl;
    }
}

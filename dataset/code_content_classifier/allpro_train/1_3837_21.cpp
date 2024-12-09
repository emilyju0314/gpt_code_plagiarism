#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;
const int N=1e6+50;
const int mod=1e9+7;
char s[4000];
int n,m;
int b[N];
set<int> S;
void solve()
{
    bool zero=1;
    int ans=1;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s+1);
        for(int j=1;j<=m;j++)
        {
            if(s[j]=='0') zero=0;
            else ans=ans*2%mod;
        }
    }
    if(zero) ans=(ans+mod-zero)%mod;
    printf("%d\n",ans);
}
int main(){
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
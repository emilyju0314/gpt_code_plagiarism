#include<bits/stdc++.h>
using namespace std;
const int N=20;
pair<int,int> a[N][N];
int n,S,m[N],ans;

void solve(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>m[i];
        for(int j=0;j<m[i];++j)
            cin>>a[i][j].first>>a[i][j].second,a[i][j].first--;
    }
    S=1<<n;
    for(int i=0;i<S;++i){
        for(int j=0;j<n;++j)
            if((i>>j)&1){
                for(int k=0;k<m[j];++k)
                    if(((i>>a[j][k].first)&1)!=a[j][k].second)goto G;
            }
        ans=max(ans,__builtin_popcount(i));
        G:;
    }
    printf("%d\n",ans);
}
int main(){
    solve();

    return 0;
}
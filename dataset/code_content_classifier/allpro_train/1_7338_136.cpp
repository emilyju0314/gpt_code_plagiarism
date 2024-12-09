#include <bits/stdc++.h>
using namespace std;
vector<int> a[200005];
int d[200005];
bool vis[200005]={false};
int go(int x){
    if(vis[x]!=0)
        return d[x];
    vis[x]=1;
    for(int i=0;i<a[x].size();i++){
        d[x]=max(d[x],go(a[x][i])+1);
    }
    return d[x];
}
int main()
{
    int x,y,i,j,k,n,m;
    cin>>n>>m;
    for(i=0;i<m;i++){
        cin>>x>>y;
        a[x].push_back(y);
    }
    int ans=0;
    for(i=1;i<=n;i++){
        if(!vis[i])
            ans=max(ans,go(i));
    }
    cout<<ans;
}

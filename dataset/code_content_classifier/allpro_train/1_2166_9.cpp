#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m,a[100010],b[100010],j,k,ans;
priority_queue<ll> Q;
void Ad(ll c,ll d){
    for(;j<n&&a[j]<c;j++)Q.push(b[j]);
    for(;k>d;k--)if(!Q.empty()){ans+=Q.top(); Q.pop();}
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i]>>b[i];
    j=0,k=n+1,ans=0;
    for(int i=0;i<m;i++){
	ll c,d;cin>>c>>d;Ad(c,d);
    }
    Ad(2e9,1);
    cout<<ans<<endl;
    return 0;
}


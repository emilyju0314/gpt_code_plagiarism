#include<bits/stdc++.h>
#define N 100000
using namespace std;
int p[N],q[N],r[N],s[2*N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x,y,a,b,c,temp;
    cin>>x>>y>>a>>b>>c;
    for(int i=0;i<a;i++)cin>>p[i];
    for(int i=0;i<b;i++)cin>>q[i];
    for(int i=0;i<c;i++)cin>>r[i];
    sort(p,p+a);
    sort(q,q+b);
    sort(r,r+c);
    copy(p+a-x,p+a,s);
    copy(q+b-y,q+b,s+x);
    sort(s,s+x+y);
    int i=0;
    for(int j=c-1;j>=0;j--){
        if(s[i]>=r[j])break;
        s[i++] = r[j];
    }
    long long ans=0LL;
    for(int i=0;i<(x+y);i++)ans+=s[i];
    cout<<ans<<"\n";
    return 0;
}
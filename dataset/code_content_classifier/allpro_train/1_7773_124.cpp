#include<bits/stdc++.h>
using namespace std;
int k,n,x[200000];
int ans=1000000000;
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>x[i];
    for(int i=0;i<n-k+1;i++){
        int a=x[i];
        int b=x[i+k-1];
        int dis=min(abs(0-a)+(b-a),abs(0-b)+(b-a));
        ans=min(ans,dis);
    }
    cout<<ans<<endl;
    return 0;
}
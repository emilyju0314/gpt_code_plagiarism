#include<bits/stdc++.h>
using namespace std;
using ll=long long;
unordered_map<ll,int> m;
ll N,A,ans;
int main(){
    cin>>N;
    while(N--){
        cin>>A;
        m[A]=1-m[A];
    }
    for(auto& x:m)
        ans+=x.second;
    cout<<ans<<endl;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll x,ans;
    cin>>x;
    ans=x/11*2;
    x%=11;
    ans+=(x+5)/6;
    cout<<ans<<endl;
    return 0;
}
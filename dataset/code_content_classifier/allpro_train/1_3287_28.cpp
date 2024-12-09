#include <iostream>
using namespace std;
typedef long long int ll;
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll a,b; cin >> a >> b;
    ll ans=1e12;
    for(ll k=1;k<=a;k++){
        ll c=(b*k+a-1)/a*a;
        if(c/a<c/b+c%b){
            ans=min(ans,c);
            break;
        }
    }
    if(ans==1e12){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
}


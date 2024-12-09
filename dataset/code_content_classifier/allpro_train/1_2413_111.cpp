#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=1e5+5;
ll f(ll n){
    if(n<0)return -1e9;
    return n - n%2;
}
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll a[7];for(ll i=0;i<7;i++)cin>>a[i];
    cout<<a[1] + max(f(a[0])+f(a[3])+f(a[4]) , f(a[0]-1) + f(a[3]-1) + f(a[4]-1) + 3);
}


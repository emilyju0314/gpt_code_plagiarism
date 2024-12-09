#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n, mod = 1e9+7, ans = 0;
    cin >> n;
    ll a=1, b=1, c=1;
    for(int i = 0; i < n; i++){
        a = (a*10) % mod;
        b = (b*9) % mod;
        c = (c*8) % mod;
    }

    cout << ((a - b - b + c) % mod + mod) % mod << endl;
}
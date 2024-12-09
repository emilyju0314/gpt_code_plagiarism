#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define mod 998244353
#define ll long long

using namespace std;

ll power(ll x, ll y, ll p) {
    ll res = 1; 
    x = x % p; 
  
    while (y > 0) {
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1; 
        x = (x*x) % p; 
    } 
    return res;
}

int main() {
    string n;
    cin >> n;
    
    ll ans = 0;
    vector<ll> power10(n.size()+1);
    power10[0] = 1;
    for (int i = 1; i <= n.size(); i++) {
        power10[i] = (power10[i-1] * 10) % mod;
    }
    
    for (int i = 0; i < n.size(); i++) {
        ll digit = n[i] - '0';
        ans = (ans * 10 + digit) % mod;
        ans = (ans * power(10, n.size() - i - 1, mod) + digit) % mod;
    }
    
    ll result = (2 * power(10, n.size()-1, mod) - ans + mod) % mod;
    
    cout << result << endl;
    
    return 0;
}
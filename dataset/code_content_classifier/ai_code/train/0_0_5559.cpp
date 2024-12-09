#include <iostream>
#include <vector>

#define ll long long
#define MOD 1000000007

using namespace std;

ll power(ll a, ll b, ll m) {
    ll ans = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            ans = (ans * a) % m;
        }
        a = (a * a) % m;
        b /= 2;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        ll d, m;
        cin >> d >> m;
        
        ll ans = 1;
        for(int i = 0; i < 30; i++) {
            if((1 << i) > d) {
                break;
            }
            ans = (ans * ((min((1 << i), d) - (1 << i-1) + 1) % m)) % m;
        }
        
        cout << (ans - 1 + m) % m << endl;
    }
    
    return 0;
}
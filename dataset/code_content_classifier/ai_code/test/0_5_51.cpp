#include <iostream>
#include <vector>
typedef long long ll;

void solve(ll n) {
    ll l, r;
    if (n % 2 == 0) {
        l = -n / 2;
        r = n / 2;
    } else {
        l = -(n - 1) / 2;
        r = (n + 1) / 2;
    }
    std::cout << l << " " << r << "\n";
}

int main() {
    int t;
    std::cin >> t;
    
    std::vector<ll> testCases(t);
    for (int i = 0; i < t; i++) {
        std::cin >> testCases[i];
    }
    
    for (int i = 0; i < t; i++) {
        solve(testCases[i]);
    }
    
    return 0;
}
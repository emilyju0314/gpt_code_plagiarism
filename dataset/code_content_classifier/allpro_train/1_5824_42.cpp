#include <iostream>

using namespace std;

long long gcd(long long a, long long b){
    return b ? gcd(b, a % b) : a;
}

long long lcm(long long a, long long b){
    return a / gcd(a, b) * b;
}

long long solve() {
    long long n; cin >> n;
    long long mod = 1e9 + 7;
    long long ans = n;
    long long k = 1;
    for (int i = 1; i <= 100; ++i){
        k = lcm(k, i);
        ans = (ans + n / k) % mod;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
}

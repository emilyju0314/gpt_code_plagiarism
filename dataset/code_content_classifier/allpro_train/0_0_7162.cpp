#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int K;
    string S;
    cin >> K >> S;
    
    int N = S.length();
    
    vector<long long> fact(N + K + 1, 1);
    for(int i = 1; i <= N + K; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    
    auto modpow = [](long long base, int exp, int mod) {
        long long result = 1;
        while(exp > 0) {
            if(exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    };
    
    auto modinv = [&modpow](int num, int mod) {
        return modpow(num, mod - 2, mod);
    };
    
    long long ans = fact[N + K];
    long long inv = modinv(fact[N], MOD);
    inv = modinv(fact[K], MOD) * inv % MOD;
    
    ans = ans * inv % MOD;
    
    cout << ans << endl;
    
    return 0;
}
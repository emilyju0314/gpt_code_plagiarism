#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 998244353;
void add(int64_t& a, int64_t b){
    a = (a+b) % MOD;
}
void mul(int64_t& a, int64_t b){
    a = a*b % MOD;
}

int64_t power_mod(int64_t num, int64_t power){
    int64_t prod = 1;
    num %= MOD;
    while(power > 0){
        if(power&1) prod = prod * num % MOD;
        num = num * num % MOD;
        power >>= 1;
    }
    return prod;
}

int main() {
    int N;
    cin >> N;
    int64_t ans = 0;
    for(int i=0; i<N; i++){
        int x;
        cin >> x;
        add(ans, x * power_mod(x+1, i) % MOD * power_mod(2, N-i-1));
    }
    cout << ans << endl;
    return 0;
}

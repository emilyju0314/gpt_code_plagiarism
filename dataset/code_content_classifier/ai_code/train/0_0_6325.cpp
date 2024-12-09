#include <iostream>
#define MOD 1000000007

long long power(long long x, long long y){
    if(y==0) return 1;
    if(y==1) return x;
    long long res = power(x, y/2)%MOD;
    res = (res*res)%MOD;
    if(y%2!=0) res = (res*x)%MOD;
    return res;
}

int main() {
    int n, l, r;
    std::cin >> n >> l >> r;

    long long total_ways = 0;
    for(int i = 0; i <= (r-l); i++){
        int x = i;
        int y = (r-l+1)-i;
        long long tmp = (power(y, n) - power(x, n) + MOD) % MOD;
        tmp = (tmp * power(r-l+1, MOD-2)) % MOD;
        total_ways = (total_ways + tmp) % MOD;
    }

    std::cout << total_ways << std::endl;

    return 0;
}
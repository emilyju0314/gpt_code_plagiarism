#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1000000007;

long long power(long long a, long long b){
    long long res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

int main() {
    int N;
    long long M;
    cin >> N >> M;
    
    vector<long long> fact(N*2+1);
    fact[0] = 1;
    for (int i = 1; i <= N*2; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    
    long long answer = fact[N*2];
    answer = (answer * power(fact[N], MOD-2)) % MOD;
    answer = (answer * power(fact[N], MOD-2)) % MOD;
    
    answer = (answer * power(2, N)) % MOD;
    
    cout << answer << endl;
    
    return 0;
}
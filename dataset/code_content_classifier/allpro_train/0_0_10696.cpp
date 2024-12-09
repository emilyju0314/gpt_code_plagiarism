#include <iostream>
using namespace std;

#define MOD 1000000007

long long moduloSum(long long n, long long m) {
    long long sum = 0;
    for(long long i = 1; i <= m; i++) {
        sum = (sum + n % i) % MOD;
    }
    return sum;
}

int main() {
    long long n, m;
    cin >> n >> m;
    
    long long result = moduloSum(n, m);
    cout << result << endl;
    
    return 0;
}
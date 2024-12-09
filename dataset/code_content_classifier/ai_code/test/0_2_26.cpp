#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

vector<long long> factorial(200001, 1);

void precomputeFactorials() {
    for(int i = 1; i <= 200000; i++) {
        factorial[i] = (factorial[i-1] * i) % MOD;
    }
}

long long binomialCoefficient(int n, int k) {
    long long numerator = factorial[n];
    long long denominator = (factorial[k] * factorial[n-k]) % MOD;
    
    return (numerator * denominator) % MOD;
}

int main() {
    precomputeFactorials();
    
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        long long answer = binomialCoefficient(2 * n, n);
        
        cout << answer << endl;
    }
    
    return 0;
}
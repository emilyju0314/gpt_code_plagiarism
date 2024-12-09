#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int m;
    cin >> m;
    
    vector<int> primes(m);
    for (int i = 0; i < m; i++) {
        cin >> primes[i];
    }
    
    long long result = 1;
    
    for (int i = 0; i < m; i++) {
        long long power = primes[i];
        while (power <= 1e5) {
            power *= primes[i];
        }
        
        power /= primes[i];
        result = (result * power) % MOD;
    }
    
    cout << result << endl;
    
    return 0;
}
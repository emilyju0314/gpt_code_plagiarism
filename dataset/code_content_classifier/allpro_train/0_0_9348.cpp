#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool is_prime(int n) {
    if(n <= 1) return false;
    if(n == 2) return true;
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    int N, P;
    while(true) {
        cin >> N >> P;
        if(N == -1 && P == -1) break;
        
        vector<int> primes;
        for(int i = N + 1; primes.size() < 2; i++) {
            if(is_prime(i)) primes.push_back(i);
        }
        
        int count = 0;
        for(int i = 0; i < primes.size(); i++) {
            for(int j = i; j < primes.size(); j++) {
                count++;
                if(count == P) {
                    cout << primes[i] + primes[j] << endl;
                }
            }
        }
    }
    
    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<int, long long>> primeFactors;

long long phi(long long n) {
    long long result = n;
    for(auto pf : primeFactors) {
        int p = pf.first;
        while(n % p == 0) {
            n /= p;
        }
        result /= p;
        result *= (p - 1);
    }
    return result;
}

int main() {
    int m;
    cin >> m;
    
    for(int i = 0; i < m; i++) {
        int p;
        long long a;
        cin >> p >> a;
        primeFactors.push_back({p, a});
    }
    
    long long k;
    cin >> k;
    
    long long ans = 0;
    
    for(int i = 0; i < k; i++) {
        ans = phi(ans);
    }
    
    cout << primeFactors.size() << endl;
    for(auto pf : primeFactors) {
        cout << pf.first << " " << pf.second << endl;
    }
    
    return 0;
}
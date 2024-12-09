#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the prime factorization of a number
vector<int> primeFactorization(int n) {
    vector<int> factors;
    int count = 0;
    
    while (n % 2 == 0) {
        count++;
        n /= 2;
    }
    if (count) factors.push_back(count);
    
    for (int i = 3; i * i <= n; i += 2) {
        count = 0;
        while (n % i == 0) {
            count++;
            n /= i;
        }
        if (count) factors.push_back(count);
    }
    
    if (n > 2) factors.push_back(1);
    
    return factors;
}

// Function to calculate the greatest common divisor of a sequence
int gcdSeq(vector<int> factors) {
    int ans = factors[0];
    
    for (int i = 1; i < factors.size(); i++) {
        ans = __gcd(ans, factors[i]);
    }
    
    return ans;
}

int elegantCount(int n) {
    int count = 0;
    
    for (int i = 2; i <= n; i++) {
        vector<int> factors = primeFactorization(i);
        if (gcdSeq(factors) == 1) count++;
    }
    
    return count;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        
        cout << elegantCount(n) << endl;
    }
    
    return 0;
}
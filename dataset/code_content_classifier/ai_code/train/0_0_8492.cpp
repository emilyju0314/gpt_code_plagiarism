#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> getPrimeFactors(int n) {
    vector<int> factors;
    for (int i = 2; i*i <= n; i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) {
        factors.push_back(n);
    }
    return factors;
}

int countDivisors(int n) {
    int count = 1;
    for (int i = 2; i*i <= n; i++) {
        int exp = 0;
        while (n % i == 0) {
            exp++;
            n /= i;
        }
        count *= exp + 1;
    }
    if (n > 1) {
        count *= 2;
    }
    return count;
}

int minOperations(int a, int b) {
    // Calculate the number of divisors for a and b
    int divisors_a = countDivisors(a);
    int divisors_b = countDivisors(b);
    
    // If a and b already have the same number of divisors, return 0
    if (divisors_a == divisors_b) {
        return 0;
    }
    
    // If a has more divisors than b, swap them
    if (divisors_a > divisors_b) {
        swap(a, b);
        swap(divisors_a, divisors_b);
    }
    
    // Find common prime factors of a and b
    vector<int> factors_a = getPrimeFactors(a);
    
    int min_ops = 1e9;
    
    for (int factor : factors_a) {
        int temp_a = a;
        int temp_ops = 0;
        while (countDivisors(temp_a) < divisors_b) {
            temp_a *= factor;
            temp_ops++;
        }
        min_ops = min(min_ops, temp_ops);
    }
    
    return min_ops;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int a, b;
        cin >> a >> b;
        
        int answer = minOperations(a, b);
        cout << answer << endl;
    }
    
    return 0;
}
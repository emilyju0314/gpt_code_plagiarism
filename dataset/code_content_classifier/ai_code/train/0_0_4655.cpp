#include <iostream>
#include <vector>
using namespace std;

int countDivisors(int n) {
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
    vector<int> counts(primes.size(), 0);
    
    for (int i = 2; i <= n; i++) {
        int num = i;
        for (int j = 0; j < primes.size(); j++) {
            while (num % primes[j] == 0) {
                num /= primes[j];
                counts[j]++;
            }
        }
    }
    
    int total = 1;
    for (int i = 0; i < counts.size(); i++) {
        total *= (counts[i] + 1);
    }
    
    return total;
}

int main() {
    int n;
    cin >> n;
    
    int divisors = countDivisors(n);
    int result = 0;
    
    if (divisors == 75) {
        result++;
    }
    
    cout << result << endl;
    
    return 0;
}
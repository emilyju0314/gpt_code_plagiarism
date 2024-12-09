#include <iostream>
#include <cmath>

using namespace std;

int countPrimes(int n) {
    int count = 0;
    
    while (n % 2 == 0) {
        n /= 2;
        count++;
    }
    
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            n /= i;
            count++;
        }
    }
    
    if (n > 2) {
        count++;
    }
    
    return count;
}

int main() {
    int l, r;
    cin >> l >> r;
    
    int ans = 0;
    
    for (int i = l; i <= r; i++) {
        int numPrimes = countPrimes(i);
        if (countPrimes(numPrimes) == 1) {
            ans++;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
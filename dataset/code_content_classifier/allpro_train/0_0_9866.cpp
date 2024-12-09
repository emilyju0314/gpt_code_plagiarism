#include <iostream>
#include <vector>
#include <cmath>

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    
    return true;
}

int main() {
    int m, n;
    
    while (std::cin >> m >> n) {
        if (m == 0 && n == 0) break;
        
        std::vector<int> caves(m + 1, 0); // 0 indicates not visited, 1 indicates prime cave
        
        int countPrime = 0;
        int lastPrime = 0;
        
        for (int i = 2; i <= m; i++) {
            if (isPrime(i)) caves[i] = 1;
        }
        
        int curr = n;
        int maxPrimeCount = 0;
        
        while (true) {
            if (caves[curr] == 1) {
                countPrime++;
                lastPrime = curr;
            }
            
            if (countPrime > maxPrimeCount) maxPrimeCount = countPrime;
            
            if (curr % 3 == 1 || curr % 3 == 0) {
                int next1 = curr + 1;
                int next2 = curr + 1 - (curr / 3);
                int next3 = curr + 2;
                
                if (next1 <= m && caves[next1] == 1) curr = next1;
                else if (next2 <= m && caves[next2] == 1) curr = next2;
                else if (next3 <= m && caves[next3] == 1) curr = next3;
                else break;
            } else {
                int next1 = curr - 1;
                int next2 = curr - 4;
                int next3 = curr - 1 - (curr / 3);
                
                if (next1 > 0 && caves[next1] == 1) curr = next1;
                else if (next2 > 0 && caves[next2] == 1) curr = next2;
                else if (next3 > 0 && caves[next3] == 1) curr = next3;
                else break;
            }
        }
        
        if (maxPrimeCount == 0) {
            std::cout << "0 0" << std::endl;
        } else {
            std::cout << maxPrimeCount << " " << lastPrime << std::endl;
        }
    }
    
    return 0;
}
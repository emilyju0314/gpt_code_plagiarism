#include <iostream>
#include <vector>
#include <cmath>

bool isPrime(int n) {
    if(n <= 1) {
        return false;
    }
    
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int t;
    std::cin >> t;
    
    while(t--) {
        int n;
        std::cin >> n;
        
        std::vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }
        
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
        }
        
        if(!isPrime(sum)) {
            std::cout << n << std::endl;
            for(int i = 1; i <= n; i++) {
                std::cout << i << " ";
            }
            std::cout << std::endl;
        } else {
            int x = 2;
            std::cout << x << std::endl;
            for(int i = 1; i < n; i++) {
                if(!isPrime(arr[i])) {
                    std::cout << 1 << " " << i+1 << std::endl;
                    break;
                }
            }
        }
    }
    return 0;
}
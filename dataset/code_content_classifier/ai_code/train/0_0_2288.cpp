#include <iostream>
#include <string>

int main() {
    long long n, m;
    std::cin >> n >> m;
    
    std::string x, y;
    std::cin >> x >> y;
    
    long long len = x.length();
    long long hammingDistance = 0;
    
    for (long long i = 0; i < n * len; i++) {
        if (x[i % len] != y[i % m * len / n]) {
            hammingDistance++;
        }
    }
    
    std::cout << hammingDistance << std::endl;
    
    return 0;
}
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<int> b(n);
    
    b[n-1] = a[n-1];
    for(int i = n-2; i >= 0; i--) {
        b[i] = a[i] + b[i+1];
    }
    
    for(int i = 0; i < n; i++) {
        std::cout << b[i] << " ";
    }
    
    return 0;
}
#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;
    
    std::string x;
    std::cin >> x;
    
    std::vector<int> b(n);
    for(int i = 0; i < n; i++) {
        b[i] = x[i] - '0';
    }
    
    for(int i = k; i < n; i++) {
        b[i] = b[i % k];
    }
    
    int m = n;
    
    for(int i = 0; i < n; i++) {
        if(b[i] > b[i % k]) {
            break;
        } else if(b[i] < b[i % k]) {
            m++;
            break;
        }
    }
    
    std::cout << m << std::endl;
    for(int i = 0; i < m; i++) {
        std::cout << b[i % k];
    }
    
    return 0;
}
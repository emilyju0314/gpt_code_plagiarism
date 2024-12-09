#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    std::vector<int> b(n);
    
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    for(int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    
    long long good_pairs = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i] + a[j] > b[i] + b[j]) {
                good_pairs++;
            }
        }
    }
    
    std::cout << good_pairs << std::endl;
    
    return 0;
}
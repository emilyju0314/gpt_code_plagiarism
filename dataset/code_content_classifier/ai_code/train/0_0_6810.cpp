#include <iostream>
#include <vector>
#include <string>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::string swaps;
    std::cin >> swaps;
    
    bool sorted = true;
    for(int i = 0; i < n-1; i++) {
        if(a[i] > a[i+1]) {
            if(swaps[i] == '0') {
                sorted = false;
                break;
            }
        }
    }
    
    if(sorted) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    
    return 0;
}
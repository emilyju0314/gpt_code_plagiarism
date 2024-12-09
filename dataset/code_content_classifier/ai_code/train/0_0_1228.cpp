#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<int> inc, dec;
    for (int i = 0; i < n; i++) {
        if (inc.empty() || a[i] > inc.back()) {
            inc.push_back(a[i]);
        } else if (dec.empty() || a[i] < dec.back()) {
            dec.push_back(a[i]);
        } else {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }
    
    std::reverse(dec.begin(), dec.end());
    
    std::cout << "YES" << std::endl;
    std::cout << inc.size() << std::endl;
    for (int i : inc) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    std::cout << dec.size() << std::endl;
    for (int i : dec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
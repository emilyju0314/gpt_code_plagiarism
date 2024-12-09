#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::sort(a.begin(), a.end());
    
    if(n % 2 == 0) {
        if(a[0] == a[n/2 - 1] && a[n/2] == a[n-1]) {
            std::cout << a[n/2] - a[0] << std::endl;
        } else {
            std::cout << -1 << std::endl;
        }
    } else {
        if(a[0] == a[n/2] && a[n/2] == a[n-1]) {
            std::cout << a[n/2] - a[0] << std::endl;
        } else {
            std::cout << -1 << std::endl;
        }
    }
    
    return 0;
}
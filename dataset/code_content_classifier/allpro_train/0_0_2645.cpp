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
        for(int i = 1; i < n; i += 2) {
            std::swap(a[i], a[i-1]);
        }
    } else {
        for(int i = 1; i < n-1; i += 2) {
            std::swap(a[i], a[i-1]);
        }
    }
    
    bool z_sorted = true;
    for(int i = 1; i < n; i++) {
        if(i % 2 == 0 && a[i] < a[i-1]) {
            z_sorted = false;
            break;
        }
        if(i % 2 == 1 && a[i] > a[i-1]) {
            z_sorted = false;
            break;
        }
    }
    
    if(z_sorted) {
        for(int i = 0; i < n; i++) {
            std::cout << a[i] << ' ';
        }
    } else {
        std::cout << "Impossible";
    }
    
    return 0;
}
#include <iostream>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    int a[n];
    
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::sort(a, a + n);
    
    for(int i = 0; i < n; i++) {
        std::cout << a[i] + i << " ";
    }
    
    return 0;
}
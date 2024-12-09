#include <iostream>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    int a[n];
    for(int i=0; i<n; i++) {
        std::cin >> a[i];
    }
    
    int count = 0;
    for(int i=0; i<n; i+=2) {
        count += (a[i] / 2);
    }
    
    std::cout << count << std::endl;
    
    return 0;
}
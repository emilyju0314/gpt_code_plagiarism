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
    
    std::sort(a.begin(), a.end());
    
    int count = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            count++;
        }
    }
    
    std::cout << count << std::endl;
    
    return 0;
}
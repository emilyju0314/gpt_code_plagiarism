#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;
    
    for(int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        
        std::vector<int> a(n);
        for(int j = 0; j < n; j++) {
            std::cin >> a[j];
        }
        
        // Sort the array in ascending order
        std::sort(a.begin(), a.end());
        
        // The maximal possible minimum in a will be the minimum element in the array after removing the first n-1 elements
        std::cout << a[n-1] << std::endl;
    }
    
    return 0;
}
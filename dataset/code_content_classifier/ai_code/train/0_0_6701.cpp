#include <iostream>
#include <unordered_set>

int main() {
    int n, m;
    std::cin >> n >> m;
    
    int arr[n];
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    
    std::unordered_set<int> distinct_nums;
    int distinct_count = 0;
    
    for(int i = n-1; i >= 0; i--) {
        distinct_nums.insert(arr[i]);
        distinct_count = distinct_nums.size();
    }
    
    for(int i = 0; i < m; i++) {
        int l;
        std::cin >> l;
        std::cout << distinct_count << std::endl;
    }
    
    return 0;
}
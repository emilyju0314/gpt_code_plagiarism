#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

std::string canBePermutation(int n, std::vector<int>& a, std::string& colors) {
    std::unordered_set<int> unique_nums;
    std::vector<int> nums = a;
    
    for(int i = 0; i < n; i++) {
        if(colors[i] == 'R') {
            nums[i] = n+1; // increase red elements so they become out of range
        }
    }
    
    for(int i = 1; i <= n; i++) {
        unique_nums.insert(i);
    }
    
    // Sort the array
    std::sort(nums.begin(), nums.end());
    
    // Remove out of range element (n+1)
    nums.pop_back();
    
    if(std::unique(nums.begin(), nums.end()) - nums.begin() == n && std::unordered_set<int>(nums.begin(), nums.end()) == unique_nums) {
        return "YES";
    }
    
    return "NO";
}

int main() {
    int t;
    std::cin >> t;
    
    while(t--) {
        int n;
        std::cin >> n;
        
        std::vector<int> a(n);
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        
        std::string colors;
        std::cin >> colors;
        
        std::cout << canBePermutation(n, a, colors) << std::endl;
    }
    
    return 0;
}
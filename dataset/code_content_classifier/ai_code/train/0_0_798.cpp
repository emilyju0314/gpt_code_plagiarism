#include <iostream>
#include <vector>
#include <algorithm>

int mex(std::vector<int>& v) {
    std::sort(v.begin(), v.end());
    int mex = 0;
    for(int num : v) {
        if(num == mex) {
            mex++;
        }
    }
    return mex;
}

int main() {
    int t;
    std::cin >> t;
    
    while(t--) {
        int n;
        std::cin >> n;
        
        std::vector<int> set(n);
        for(int i = 0; i < n; i++) {
            std::cin >> set[i];
        }
        
        int minA = 101; // Initialize with a large number
        int minB = 101; // Initialize with a large number
        
        for(int num : set) {
            if(num < minA) {
                minB = minA;
                minA = num;
            } else if(num < minB) {
                minB = num;
            }
        }
        
        // Create two subsets A and B based on minA and minB
        std::vector<int> A, B;
        for(int num : set) {
            if(num == minA) A.push_back(num);
            else B.push_back(num);
        }
        
        int result = mex(A) + mex(B);
        std::cout << result << std::endl;
    }
    
    return 0;
}
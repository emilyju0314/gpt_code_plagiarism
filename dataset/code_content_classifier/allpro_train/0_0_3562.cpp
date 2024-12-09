#include <iostream>
#include <vector>
#include <algorithm>

bool isLucky(int num) {
    while(num > 0) {
        int digit = num % 10;
        if(digit != 4 && digit != 7) {
            return false;
        }
        num /= 10;
    }
    return true;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    
    std::vector<int> permutation;
    for(int i = 1; i <= n; i++) {
        permutation.push_back(i);
    }
    
    int luckyCount = 0;
    do {
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(isLucky(i+1) && isLucky(permutation[i])) {
                count++;
            }
        }
        if(count == k) {
            luckyCount++;
        }
    } while (std::next_permutation(permutation.begin(), permutation.end()));
    
    if(luckyCount == 0) {
        std::cout << "-1" << std::endl;
    } else {
        std::cout << luckyCount << std::endl;
    }
    
    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_set>

int minElementsToRemoveToMakeBeautifulArray(std::vector<int>& arr) {
    std::unordered_set<int> s(arr.begin(), arr.end());
    
    int result = 0;
    
    for(int num : arr) {
        bool isBeautiful = false;
        for(int i = 1; i * i <= num; i++) {
            if(num % i == 0) {
                if(s.count(i) > 0 || s.count(num / i) > 0) {
                    isBeautiful = true;
                    break;
                }
            }
        }
        if(!isBeautiful) {
            result++;
        }
    }
    
    return result;
}

int main() {
    int t;
    std::cin >> t;
    
    while(t--) {
        int n;
        std::cin >> n;
        
        std::vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }
        
        int result = minElementsToRemoveToMakeBeautifulArray(arr);
        std::cout << result << std::endl;
    }
    
    return 0;
}
#include <iostream>
#include <vector>

bool isPalindrome(std::vector<int>& a, int start, int end) {
    while (start < end) {
        if (a[start] != a[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

std::string hasPalindrome(std::vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n-2; i++) {
        for (int j = i+2; j < n; j++) {
            if (isPalindrome(a, i, j)) {
                return "YES";
            }
        }
    }
    
    return "NO";
}

int main() {
    int t;
    std::cin >> t;
    
    while (t--) {
        int n;
        std::cin >> n;
        
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        
        std::cout << hasPalindrome(a) << std::endl;
    }
    
    return 0;
}
#include <iostream>
#include <string>

std::string removeRepeatingBlocks(std::string str) {
    size_t n = str.size();
    std::string ans;
    
    for (size_t i = 0; i < n; i++) {
        int j = i + 1;
        while (j < n && str[j] == str[j % (i + 1)]) {
            j++;
        }
        
        if (j == i + 1) {
            ans += str[i];
        } else {
            i = j - 1;
        }
    }
    
    return ans;
}

int main() {
    std::string input;
    std::cin >> input;
    
    std::string result = removeRepeatingBlocks(input);
    
    std::cout << result << std::endl;
    
    return 0;
}
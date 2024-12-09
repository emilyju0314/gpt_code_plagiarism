#include <iostream>
#include <string>

int countPrettySubstrings(const std::string& s) {
    int count = 0;
    for (int i = 0; i < s.size(); ++i) {
        int open = 0, unknown = 0;
        for (int j = i; j < s.size(); ++j) {
            if (s[j] == '(') {
                open++;
            } else if (s[j] == ')') {
                open--;
            } else {
                unknown++;
            }
            
            if (open + unknown < 0) {
                break;
            }
            
            if (open - unknown == 0) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    std::string s;
    std::cin >> s;
    
    int result = countPrettySubstrings(s);
    std::cout << result << std::endl;
    
    return 0;
}
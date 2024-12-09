#include <iostream>
#include <string>

int main() {
    int n;
    std::string s;
    
    // read input
    std::cin >> n;
    std::cin >> s;
    
    int depth = 0;
    std::string result = "";
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            if (depth % 2 == 0) {
                result += '0';
            } else {
                result += '1';
            }
            depth++;
        } else {
            if (depth % 2 == 0) {
                result += '1';
            } else {
                result += '0';
            }
            depth--;
        }
    }
    
    std::cout << result << std::endl;
    
    return 0;
}
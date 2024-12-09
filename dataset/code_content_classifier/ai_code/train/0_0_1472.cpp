#include <iostream>
#include <string>

int countValidTrees(std::string str) {
    int count = 0;
    int opens = 0;
    
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            opens++;
        } else {
            count += opens * 2;
        }
    }
    
    return count;
}

int main() {
    std::string input;
    std::cin >> input;
    
    int result = countValidTrees(input);
    std::cout << result << std::endl;
    
    return 0;
}
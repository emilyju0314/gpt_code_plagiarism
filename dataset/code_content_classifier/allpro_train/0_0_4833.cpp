#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    std::string result;

    for(char c : s) {
        if(c == '0') {
            result.push_back('0');
        } else if(c == '1') {
            result.push_back('1');
        } else if(c == 'B') {
            if(!result.empty()) {
                result.pop_back();
            }
        }
    }

    std::cout << result << std::endl;

    return 0;
}
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s;
    std::cin >> s;
    
    for (int i = s.length(); i > 0; i--) {
        std::string temp = s.substr(s.length()-i);
        std::string result = "";
        for (int j = 0; j < temp.length(); j++) {
            if (j < temp.length()-1 && temp[j] == temp[j+1]) {
                result += temp[j];
            } else {
                result += temp[j];
                break;
            }
        }
        if (result.length() > 10) {
            std::cout << result.substr(0, 5) << "..." << result.substr(result.length()-2) << std::endl;
        } else {
            std::cout << result << std::endl;
        }
    }
    
    return 0;
}
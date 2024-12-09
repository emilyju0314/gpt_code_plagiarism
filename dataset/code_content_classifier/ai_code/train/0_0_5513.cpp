#include <iostream>
#include <string>

int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;

    int count = 0;
    std::string temp = s1;
    
    while (temp.length() < s2.length()) {
        temp += s1;
        count++;
    }

    if (temp.find(s2) != std::string::npos) {
        std::cout << count + 1 << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }

    return 0;
}
#include <iostream>
#include <string>

int main() {
    std::string w;
    std::cin >> w;

    int count[26] = {0};

    for(char c : w) {
        count[c - 'a']++;
    }

    bool isBeautiful = true;
    for(int i = 0; i < 26; i++) {
        if(count[i] % 2 != 0) {
            isBeautiful = false;
            break;
        }
    }

    if(isBeautiful) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}
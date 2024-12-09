#include <iostream>
#include <vector>
#include <string>

bool canMakeShiritori(std::vector<std::string> words) {
    if(words.size() < 2) {
        return false;
    }

    std::string current = words[0];
    char last = current.back();

    for(int i = 1; i < words.size(); i++) {
        if(words[i][0] == last) {
            last = words[i].back();
        } else {
            return false;
        }
    }

    if(last == current[0]) {
        return true;
    }

    return false;
}

int main() {
    int n;
    while(std::cin >> n) {
        if(n == 0) {
            break;
        }

        std::vector<std::string> words(n);
        for(int i = 0; i < n; i++) {
            std::cin >> words[i];
        }

        if(canMakeShiritori(words)) {
            std::cout << "OK" << std::endl;
        } else {
            std::cout << "NG" << std::endl;
        }
    }

    return 0;
}
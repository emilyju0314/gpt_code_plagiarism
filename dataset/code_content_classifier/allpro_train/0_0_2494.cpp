#include <iostream>
#include <map>

int main() {
    std::string S;
    std::cin >> S;

    std::map<char, int> freq;
    for(char c : S) {
        freq[c]++;
    }

    if(freq.size() == 2) {
        bool flag = true;
        for(auto& pair : freq) {
            if(pair.second != 2) {
                flag = false;
                break;
            }
        }
        if(flag) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}
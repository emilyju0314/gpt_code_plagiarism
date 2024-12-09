#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        std::string s;
        std::cin >> s;

        int ones = 0;
        int zeros = 0;

        for(char c : s) {
            if(c == '1') {
                ones++;
            } else {
                zeros++;
            }
        }

        if(std::min(ones, zeros) % 2 == 0) {
            std::cout << "NET" << std::endl;
        } else {
            std::cout << "DA" << std::endl;
        }
    }

    return 0;
}
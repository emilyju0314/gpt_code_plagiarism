#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    int num_links = 0;
    int num_pearls = 0;

    for(char c : s) {
        if(c == '-') {
            num_links++;
        } else {
            num_pearls++;
        }
    }

    if(num_pearls == 0 || num_links % num_pearls == 0) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
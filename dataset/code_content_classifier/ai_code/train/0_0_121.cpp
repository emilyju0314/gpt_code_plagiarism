#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::string level;
    std::cin >> level;

    for (int i = 0; i < n; i++) {
        int d = i + 1;
        for (int j = 0; j < n; j++) {
            std::string seq = "";
            for (int k = 0; k < 5; k++) {
                if (j + k * d < n && level[j + k * d] == '*') {
                    seq += '*';
                } else {
                    seq += '.';
                }
            }
            if (seq == "*****") {
                std::cout << "yes" << std::endl;
                return 0;
            }
        }
    }

    std::cout << "no" << std::endl;
    
    return 0;
}
#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::string s;
        std::cin >> n >> s;

        int countT = 0;
        int countM = 0;
        for (char c : s) {
            if (c == 'T') {
                countT++;
            } else {
                countM++;
            }
        }

        if (countT != 2 * countM) {
            std::cout << "NO" << std::endl;
        } else {
            int tCount = 0;
            for (char c : s) {
                if (c == 'T') {
                    tCount++;
                } else {
                    tCount--;
                }
                if (tCount < 0) {
                    std::cout << "NO" << std::endl;
                    break;
                }
            }
            if (tCount == 0) {
                std::cout << "YES" << std::endl;
            }
        }
    }

    return 0;
}
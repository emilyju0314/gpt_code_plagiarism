#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;

    std::string suffixes[] = {"po", "desu", "masu", "mnida"};

    while (t--) {
        std::string sentence;
        std::cin >> sentence;

        for (int i = 0; i < 4; i++) {
            if (sentence.rfind(suffixes[i]) == sentence.size() - suffixes[i].size()) {
                if (i == 0) {
                    std::cout << "FILIPINO" << std::endl;
                } else if (i < 3) {
                    std::cout << "JAPANESE" << std::endl;
                } else {
                    std::cout << "KOREAN" << std::endl;
                }
                break;
            }
        }
    }

    return 0;
}
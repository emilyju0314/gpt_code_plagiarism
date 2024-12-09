#include <iostream>
#include <vector>

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::vector<int> iceCreams(10, 0);
        for (int i = 0; i < n; ++i) {
            int c;
            std::cin >> c;
            ++iceCreams[c];
        }

        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < iceCreams[i]; ++j) {
                std::cout << "*";
            }
            if (iceCreams[i] == 0) {
                std::cout << "-";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
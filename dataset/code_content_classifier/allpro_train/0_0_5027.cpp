#include <iostream>

int main() {
    int cnt_1, cnt_2, cnt_3, cnt_4;
    std::cin >> cnt_1 >> cnt_2 >> cnt_3 >> cnt_4;

    if (cnt_1 == 0 && cnt_3 == 0) {
        if (cnt_4 > cnt_2) {
            std::cout << 0 << std::endl;
        } else if (cnt_4 == cnt_2 && cnt_2 > 0) {
            std::cout << 1 << std::endl;
        } else {
            std::cout << 1 << std::endl;
        }
    } else {
        std::cout << 0 << std::endl;
    }

    return 0;
}
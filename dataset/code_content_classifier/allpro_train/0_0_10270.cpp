#include <iostream>
#include <string>

int main() {
    int a00, a01, a10, a11;
    std::cin >> a00 >> a01 >> a10 >> a11;

    if (a00 + a01 + a10 + a11 == 0) {
        std::cout << "Impossible" << std::endl;
    } else if (a00 == 0 && a01 == 0 && a10 == 0) {
        std::string s(a11 + 1, '1');
        std::cout << s << std::endl;
    } else if (a00 == 0 && a01 == 0 && a11 == 0) {
        std::string s(a10 + 1, '1');
        std::cout << "0" << s << std::endl;
    } else if (a00 == 0 && a10 == 0 && a11 == 0) {
        std::string s(a01 + 1, '0');
        std::cout << s << "1" << std::endl;
    } else if (a01 == 0 && a10 == 0 && a11 == 0) {
        std::string s(a00 + 1, '0');
        std::cout << s << "1" << std::endl;
    } else {
        if ((a11 + a01 != a10 + a00) || (a11 + a01 <= 1) || (a11 < 1) || (a01 < 1)) {
            std::cout << "Impossible" << std::endl;
        } else {
            std::string s = "1";

            a11--;
            a01--;

            while (a11 > 0 && a01 > 0) {
                s += "10";
                a11--;
                a01--;
            }

            if (a11 > 0) {
                s += "1";
                a11--;
            }

            if (a01 > 0) {
                s += "0";
                a01--;
            }

            for (int i = 0; i < a00; i++) {
                s = "0" + s;
            }

            for (int i = 0; i < a10; i++) {
                s += "0";
            }

            std::cout << s << std::endl;
        }
    }

    return 0;
}
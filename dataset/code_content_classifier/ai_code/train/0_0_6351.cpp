#include <iostream>
#include <string>

int main() {
    int b, d;
    std::cin >> b >> d;

    std::string a, c;
    std::cin >> a >> c;

    int max_p = 0;
    int p = 0;
    for (int i = 1; i <= d; i++) {
        if (a.find(c) != std::string::npos) {
            p = (b - 1) / i + 1;
            if (p > max_p) {
                max_p = p;
            }
        } else {
            break;
        }
        c = c + c;
    }

    std::cout << max_p << std::endl;

    return 0;
}
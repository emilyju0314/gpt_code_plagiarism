#include <iostream>
#include <string>

int main() {
    int a, b;
    std::cin >> a >> b;

    std::string str1, str2;
    for (int i = 0; i < a; i++) {
        str1 += (char)(b + '0');
    }
    for (int i = 0; i < b; i++) {
        str2 += (char)(a + '0');
    }

    if (str1 < str2) {
        std::cout << str1 << std::endl;
    } else {
        std::cout << str2 << std::endl;
    }

    return 0;
}
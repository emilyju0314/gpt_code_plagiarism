#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    int current_pos = 0; // 0 represents North Pole

    for (int i = 0; i < n; i++) {
        int ti;
        std::string diri;
        std::cin >> ti >> diri;

        if (current_pos == 0 && diri != "South") {
            std::cout << "NO" << std::endl;
            return 0;
        } else if (current_pos == 20000 && diri != "North") {
            std::cout << "NO" << std::endl;
            return 0;
        }

        if (diri == "North") {
            current_pos += ti;
        } else if (diri == "South") {
            current_pos -= ti;
        }

        if (current_pos < 0 || current_pos > 20000) {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }

    if (current_pos == 0) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
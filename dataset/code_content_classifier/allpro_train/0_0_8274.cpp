#include <iostream>
#include <string>

bool sameConfiguration(std::string bessieConfig, std::string elsieConfig) {
    for (int i = 0; i < 4; i++) {
        if (bessieConfig[i] != elsieConfig[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string bessieTop, bessieBottom, elsieTop, elsieBottom;

    std::cin >> bessieTop >> bessieBottom >> elsieTop >> elsieBottom;

    std::string bessieConfiguration = bessieTop + bessieBottom;
    std::string elsieConfiguration = elsieTop + elsieBottom;

    if (sameConfiguration(bessieConfiguration, elsieConfiguration)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
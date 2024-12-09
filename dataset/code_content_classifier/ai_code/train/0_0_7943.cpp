#include <iostream>
#include <string>

int main() {
    int N;
    std::cin >> N;

    std::string n_str = std::to_string(N);
    
    if (n_str.find('7') != std::string::npos) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}
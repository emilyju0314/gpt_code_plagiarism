#include <iostream>
#include <string>

int main() {
    int K;
    std::cin >> K;

    std::string result = "";
    for (int i = 0; i < K; i++) {
        result += "ACL";
    }

    std::cout << result << std::endl;

    return 0;
}
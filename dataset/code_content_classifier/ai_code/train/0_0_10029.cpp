#include <iostream>
#include <string>

int main() {
    std::string S;
    std::cin >> S;

    int festIndex = S.find("FESTIVAL");
    std::string festivalName = S.substr(0, festIndex);

    std::cout << festivalName << std::endl;

    return 0;
}
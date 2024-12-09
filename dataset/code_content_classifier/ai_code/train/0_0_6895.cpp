#include <iostream>
#include <string>

int main() {
    std::string stations, firstSeq, secondSeq;
    std::cin >> stations >> firstSeq >> secondSeq;

    size_t firstPos = stations.find(firstSeq);
    size_t secondPos = stations.rfind(secondSeq);

    if (firstPos != std::string::npos && secondPos != std::string::npos && firstPos < secondPos) {
        std::cout << "forward" << std::endl;
    } else if (firstPos != std::string::npos && secondPos != std::string::npos && firstPos > secondPos) {
        std::cout << "backward" << std::endl;
    } else if (stations.find(secondSeq + firstSeq) != std::string::npos) {
        std::cout << "both" << std::endl;
    } else {
        std::cout << "fantasy" << std::endl;
    }

    return 0;
}
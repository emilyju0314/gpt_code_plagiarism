#include <iostream>
#include <string>

int main() {
    std::string today;
    std::cin >> today;

    std::string tomorrow;
    if(today == "Sunny") {
        tomorrow = "Cloudy";
    } else if(today == "Cloudy") {
        tomorrow = "Rainy";
    } else {
        tomorrow = "Sunny";
    }

    std::cout << tomorrow << std::endl;

    return 0;
}
#include <iostream>
#include <string>

int main() {
    int x;
    std::cin >> x;

    int num_of_3 = x / 100;
    std::string id = "ai1333";
    
    for (int i = 0; i < num_of_3; i++) {
        id += "3";
    }

    std::cout << id << std::endl;

    return 0;
}
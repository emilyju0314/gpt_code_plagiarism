#include <iostream>
#include <string>
#include <algorithm>

bool isSameLayout(std::string layout1, std::string layout2) {
    std::sort(layout1.begin(), layout1.end());
    std::sort(layout2.begin(), layout2.end());
    
    return layout1 == layout2;
}

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore(); // Ignore newline

    for (int i = 0; i < n; i++) {
        std::string record1, record2;
        std::getline(std::cin, record1);
        std::getline(std::cin, record2);
        std::string hyphen;
        std::cin >> hyphen;
        std::cin.ignore(); // Ignore newline
        
        if (record1 != "" && record2 != "") {
            bool result = isSameLayout(record1, record2);
            if (result) {
                std::cout << "true" << std::endl;
            } else {
                std::cout << "false" << std::endl;
            }
        } else {
            std::cout << "false" << std::endl;
        }
    }

    return 0;
}
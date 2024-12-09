#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;

    std::vector<int> positionsToDelete;
    int j = 0;

    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] == s2[j]) {
            j++;
        } else {
            positionsToDelete.push_back(i);
        }
    }

    if (j == s2.length()) {
        std::cout << positionsToDelete.size() << std::endl;
        for (int i = 0; i < positionsToDelete.size(); i++) {
            std::cout << positionsToDelete[i] + 1 << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "0" << std::endl;
    }

    return 0;
}
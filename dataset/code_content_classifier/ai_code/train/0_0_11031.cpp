#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::vector<int> pages;
    std::istringstream iss(input);
    std::string page;
    while (std::getline(iss, page, ',')) {
        pages.push_back(std::stoi(page));
    }

    std::sort(pages.begin(), pages.end());
    std::vector<std::string> result;

    for (int i = 0; i < pages.size(); i++) {
        int left = pages[i];
        while (i + 1 < pages.size() && pages[i + 1] == pages[i] + 1) {
            i++;
        }
        int right = pages[i];
        if (left == right) {
            result.push_back(std::to_string(left));
        } else {
            result.push_back(std::to_string(left) + "-" + std::to_string(right));
        }
    }

    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i];
        if (i < result.size() - 1) {
            std::cout << ",";
        }
    }
    
    return 0;
}
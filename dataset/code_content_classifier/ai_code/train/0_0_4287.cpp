#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::string s;
    std::cin >> s;

    int n;
    std::cin >> n;

    std::vector<std::string> pages(n);
    for (int i = 0; i < n; i++) {
        std::cin >> pages[i];
    }

    std::string result = s;
    std::sort(pages.begin(), pages.end());

    for (const std::string& page : pages) {
        if (page.find(s) == 0) {
            result = page;
            break;
        }
    }

    std::cout << result << std::endl;

    return 0;
}
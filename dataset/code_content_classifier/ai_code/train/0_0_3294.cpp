#include <iostream>
#include <vector>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> input(2*n-2);
    for (int i = 0; i < 2*n-2; i++) {
        std::cin >> input[i];
    }

    std::string result;
    for (int i = 0; i < 2*n-2; i++) {
        if (input[i].size() == n-1) {
            if (result.empty()) {
                result += 'P';
            } else {
                if (result.back() == 'P') {
                    result += 'S';
                } else {
                    result += 'P';
                }
            }
        } else if (input[i].size() == 1) {
            if (result.size() < n-1) {
                result += 'P';
            } else {
                result += 'S';
            }
        }
    }

    std::cout << result << std::endl;

    return 0;
}
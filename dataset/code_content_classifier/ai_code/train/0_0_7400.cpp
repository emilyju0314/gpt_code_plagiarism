#include <iostream>
#include <string>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::string p;
    std::cin >> p;

    std::string occurrences;
    std::cin >> occurrences;

    std::string result = "";

    for (int i = 0; i < n; i++) {
        if (occurrences[i] == '1') {
            result += p;
            i += p.size() - 1;
        } else {
            for (int j = 0; j < k; j++) {
                if (p.find('a' + j) == std::string::npos) {
                    result += 'a' + j;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n - p.size() + 1; i++) {
        if (result.substr(i, p.size()) == p) {
            continue;
        }
        bool valid = false;
        for (int j = 0; j < p.size(); j++) {
            if (result[i + j] == p[j]) {
                valid = true;
                break;
            }
        }
        if (!valid) {
            std::cout << "No solution" << std::endl;
            return 0;
        }
    }

    std::cout << result << std::endl;

    return 0;
}
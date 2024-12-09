#include <iostream>
#include <string>
#include <vector>

std::string makeEbneNumber(int n, std::string s) {
    int sum = 0;
    for (char c : s) {
        sum += c - '0';
    }

    std::string result = s;
    for (int i = 0; i < n; i++) {
        if (((sum - (s[i] - '0')) % 2 == 0) && ((s[i] - '0') % 2 != 0)) {
            result.erase(i, 1);
            break;
        }
    }

    if (result.empty() || (result[0] == '0')) {
        return "-1";
    } else {
        return result;
    }
}

int main() {
    int t;
    std::cin >> t;

    std::vector<std::pair<int, std::string>> cases;
    for (int i = 0; i < t; i++) {
        int n;
        std::string s;
        std::cin >> n >> s;
        cases.push_back(std::make_pair(n, s));
    }

    for (const auto& c : cases) {
        std::string result = makeEbneNumber(c.first, c.second);
        std::cout << result << std::endl;
    }

    return 0;
}
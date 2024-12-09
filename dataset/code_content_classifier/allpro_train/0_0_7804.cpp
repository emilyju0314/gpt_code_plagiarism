#include <iostream>
#include <string>

std::string reverseString(const std::string& s) {
    std::string reversed = s;
    std::reverse(reversed.begin(), reversed.end());
    return reversed;
}

bool compareStrings(const std::string& a, const std::string& b, int i, int j) {
    std::string substring1 = a.substr(i + 1, j - i - 1);
    std::string substring2 = a.substr(j, a.length() - j) + a.substr(0, i + 1);
    return substring1 + reverseString(substring2) == b;
}

int main() {
    std::string a, b;
    std::cin >> a >> b;

    int i = -1, j = -1;
    for (int start = 0; start < a.length(); ++start) {
        int end = start + b.length();
        if (end > a.length()) {
            end = end - a.length();
            if (compareStrings(a, b, start, end)) {
                i = start;
                j = end;
                break;
            }
        } else if (compareStrings(a, b, start, end)) {
            i = start;
            j = end;
            break;
        }
    }

    if (i == -1) {
        std::cout << "-1 -1" << std::endl;
    } else {
        std::cout << i << " " << j << std::endl;
    }

    return 0;
}
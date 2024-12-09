#include <iostream>
#include <string>

int countPrettyStrings(const std::string& s) {
    int n = s.length();
    int answer = 0;

    for (int i = 0; i < n; i++) {
        int open = 0, close = 0;
        for (int j = i; j < n; j++) {
            if (s[j] == '(') {
                open++;
            } else if (s[j] == ')') {
                close++;
            } else {
                open++;
                close++;
            }
            if (open == close) {
                answer++;
            }
        }
    }

    return answer;
}

int main() {
    std::string s;
    std::cin >> s;

    int answer = countPrettyStrings(s);
    std::cout << answer << std::endl;

    return 0;
}
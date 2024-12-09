#include <iostream>
#include <string>
#include <vector>

const int MOD = 1e9 + 7;

int countRSBS(const std::string& s) {
    int n = s.size();
    std::vector<int> left(n, 0);
    std::vector<int> right(n, 0);

    int leftCount = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            leftCount++;
        } else {
            if (leftCount > 0) {
                left[i]++;
                leftCount--;
            }
        }
    }

    int rightCount = 0;
    for (int i = n-1; i >= 0; i--) {
        if (s[i] == ')') {
            rightCount++;
        } else {
            if (rightCount > 0) {
                right[i]++;
                rightCount--;
            }
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(' && left[i] > 0) {
            result = (result + 1 + left[i] + right[i]) % MOD;
        }
    }

    return result;
}

int main() {
    std::string s;
    std::cin >> s;

    int result = countRSBS(s);
    std::cout << result << std::endl;

    return 0;
}
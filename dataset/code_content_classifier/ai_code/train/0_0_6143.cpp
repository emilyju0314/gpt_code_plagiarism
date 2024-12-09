#include <iostream>
#include <vector>
#include <algorithm>

bool isPalindrome(std::string s) {
    return s == std::string(s.rbegin(), s.rend());
}

int main() {
    int N, L;
    std::cin >> N >> L;

    std::vector<std::string> strings(N);
    for(int i = 0; i < N; i++) {
        std::cin >> strings[i];
    }

    std::vector<std::string> left, right;
    for(int i = 0; i < N; i++) {
        std::string rev = strings[i];
        std::reverse(rev.begin(), rev.end());

        if(std::find(strings.begin() + i + 1, strings.end(), rev) != strings.end()) {
            left.push_back(strings[i]);
            right.push_back(rev);
        }
    }

    if(left.size() == 0) {
        std::cout << std::endl;
    } else {
        std::sort(left.begin(), left.end());
        std::sort(right.begin(), right.end());

        std::string middle;
        for(int i = 0; i < N; i++) {
            if(strings[i] == right[0]) {
                middle = strings[i];
                break;
            }
        }

        std::cout << std::accumulate(left.begin(), left.end(), std::string("")) << middle << std::accumulate(right.rbegin(), right.rend(), std::string("")) << std::endl;
    }

    return 0;
}
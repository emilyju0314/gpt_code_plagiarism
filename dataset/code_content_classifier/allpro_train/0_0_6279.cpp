#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    if(n > 26) {
        std::cout << -1 << std::endl;
    } else {
        std::vector<int> charCount(26, 0);
        int changes = 0;

        for(char c : s) {
            charCount[c - 'a']++;
        }

        for(int count : charCount) {
            if(count > 1) {
                changes += count - 1;
            }
        }

        std::cout << changes << std::endl;
    }

    return 0;
}
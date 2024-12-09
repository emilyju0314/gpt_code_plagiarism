#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    // Read values assigned to letters
    std::unordered_map<char, int> likes;
    for (char c = 'a'; c <= 'z'; c++) {
        int value;
        std::cin >> value;
        likes[c] = value;
    }

    // Read the input string
    std::string s;
    std::cin >> s;

    // Count the number of interesting substrings
    int count = 0;

    for (int i = 0; i < s.length(); i++) {
        char start = s[i];
        int sum = 0;

        // Check the substring starting from s[i]
        for (int j = i + 1; j < s.length(); j++) {
            char end = s[j];
            sum += likes[end];

            if (end == start && sum == 0) {
                count++;
            }
        }
    }

    std::cout << count << std::endl;

    return 0;
}
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s;
    std::cin >> s;

    int min_operations = s.length();
    for(int i = 0; i < s.length() - 1; i++) {
        // Find the longest consecutive substring of the same character
        int count = 1;
        while(s[i] == s[i+1] && i+1 < s.length()) {
            i++;
            count++;
        }
        min_operations = std::min(min_operations, static_cast<int>(s.length()) - count);
    }

    std::cout << min_operations << std::endl;

    return 0;
}
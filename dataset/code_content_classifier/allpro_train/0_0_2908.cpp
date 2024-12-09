#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    int min_length = s.length(); // Start with the uncompressed version length
    for (int i = 1; i <= s.length(); i++) {
        std::string compressed;
        int count = 1;
        for (int j = 0; j < s.length(); j += i) {
            if (s.substr(j, i) == s.substr(j + i, i)) {
                count++;
            } else {
                if (count > 1) {
                    compressed += std::to_string(count);
                }
                compressed += s.substr(j, i);
                count = 1;
            }
        }
        if (count > 1) {
            compressed += std::to_string(count);
        }

        min_length = std::min(min_length, (int)compressed.length());
    }

    std::cout << min_length << std::endl;

    return 0;
}
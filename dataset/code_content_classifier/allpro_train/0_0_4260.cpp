#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        int k;
        std::cin >> k;

        std::string s;
        std::cin >> s;

        int last_moment = 0;
        int angry_count = 0;

        for (int j = 0; j < k; j++) {
            if (s[j] == 'A') {
                angry_count++;
                last_moment = std::max(last_moment, angry_count);
            } else {
                angry_count = 0;
            }
        }

        std::cout << last_moment << std::endl;
    }

    return 0;
}
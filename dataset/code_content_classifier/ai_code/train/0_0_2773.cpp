#include <iostream>
#include <string>

int main() {
    std::string s, t;
    std::cin >> s >> t;

    int zero_count = 0, one_count = 0;
    for (char ch : s) {
        if (ch == '0') zero_count++;
        else one_count++;
    }

    int valid_pairs = 0;
    for (int i = 1; i <= t.length() / 2; i++) {
        std::string r0 = t.substr(0, i);
        std::string r1 = t.substr(i, t.length()-i);

        if ((r0.length() == zero_count && r1.length() == one_count) || 
            (r1.length() == zero_count && r0.length() == one_count)) {
            if (r0 != r1) valid_pairs++;
        }
    }

    std::cout << valid_pairs << std::endl;

    return 0;
}
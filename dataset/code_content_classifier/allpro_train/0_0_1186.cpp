#include <iostream>
#include <string>
#include <set>

int main() {
    std::string L, R;
    std::cin >> L >> R;

    std::set<std::string> inedible_tails;

    for (long long i = std::stoll(L); i <= std::stoll(R); i++) {
        std::string num_str = std::to_string(i);
        std::sort(num_str.begin(), num_str.end());

        while (num_str[0] == '0') {
            num_str.erase(num_str.begin());
        }

        inedible_tails.insert(num_str);
    }

    std::cout << inedible_tails.size() << std::endl;

    return 0;
}